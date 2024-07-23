#include "PrecompiledHeader.h"

#include "ImpactManager.h"

#include "DecalManager.h"
#include "Shared/Utility/Conversion.h"



namespace Trails
{
	bool ImpactManager::PlayImpactEffect(Skyrim::TESObjectREFR* reference, const Settings::Footprint& footprint)
	{
		if (!reference)
		{
			return false;
		}

		auto* impactDataSet = footprint.impactDataSet;

		if (!impactDataSet)
		{
			return false;
		}

		auto* parentCell = reference->parentCell;

		if (!parentCell)
		{
			return false;
		}

		auto* havokWorld = parentCell->GetHavokWorld();

		if (!havokWorld)
		{
			return false;
		}

		const auto& rayCast     = footprint.rayCast;
		auto*       reference3D = reference->GetThirdPerson3D();

		Skyrim::BSFixedString originNodeName = rayCast.origin.nodeName;
		auto*                 originNode     = originNodeName.empty() || !reference3D ? nullptr : reference3D->GetBoneFromName(originNodeName, true);
		auto                  origin         = originNode ? originNode->currentWorldTransform.translation : reference->position;

		Skyrim::NiPoint3 originOffset = { rayCast.origin.offset.x, rayCast.origin.offset.y, rayCast.origin.offset.z };
		Skyrim::NiPoint3 ray          = { rayCast.ray.x, rayCast.ray.y, rayCast.ray.z };

		if (rayCast.rotation.rotate.x || rayCast.rotation.rotate.y || rayCast.rotation.rotate.z)
		{
			auto originOffsetMagnitude = originOffset.Magnitude();
			auto rayMagnitude          = ray.Magnitude();

			originOffset.Normalize();
			ray.Normalize();

			Skyrim::BSFixedString rotationNodeName = rayCast.rotation.nodeName;
			auto*                 rotationNode     = rotationNodeName.empty() || !reference3D ? nullptr : reference3D->GetBoneFromName(rotationNodeName, true);

			Skyrim::NiPoint3 eulerAngles;

			if (rotationNode)
			{
				rotationNode->currentWorldTransform.rotation.RotationMatrixToEulerAnglesZXY(eulerAngles.z, eulerAngles.x, eulerAngles.y);
			}
			else
			{
				eulerAngles = reference->rotation;
			}

			Skyrim::NiMatrix33 rotationMatrix;

			rotationMatrix.EulerAnglesToRotationMatrixZXY(
				rayCast.rotation.rotate.z ? eulerAngles.z : 0.0F,
				rayCast.rotation.rotate.x ? eulerAngles.x : 0.0F,
				rayCast.rotation.rotate.y ? eulerAngles.y : 0.0F);

			originOffset = rotationMatrix * originOffset;
			ray          = rotationMatrix * ray;

			originOffset.Normalize();
			ray.Normalize();

			originOffset *= originOffsetMagnitude;
			ray          *= rayMagnitude;
		}

		origin += originOffset;

		Skyrim::bhkPickData               pickData;
		Skyrim::hkpClosestRayHitCollector closestRayHitCollector;

		pickData.rayHitCollectorA8 = std::addressof(closestRayHitCollector);

		auto havokWorldScale = Skyrim::bhkWorld::GetScale();

		pickData.worldRayCastInput.from.quad = ::_mm_setr_ps(
			origin.x * havokWorldScale,
			origin.y * havokWorldScale,
			origin.z * havokWorldScale,
			0.0F);

		pickData.ray.quad = ::_mm_setr_ps(
			ray.x * havokWorldScale,
			ray.y * havokWorldScale,
			ray.z * havokWorldScale,
			0.0F);

		switch (reference->formType.get())
		{
			case Skyrim::FormType::kActor:
			{
				auto* characterController = static_cast<Skyrim::Actor*>(reference)->GetCharacterController();

				if (characterController)
				{
					characterController->GetCollisionFilterInformation(pickData.worldRayCastInput.filterInformation);
				}

				break;
			}
			default:
			{
				if (reference3D)
				{
					auto* collisionObject = reference3D->GetCollisionObject();

					if (collisionObject)
					{
						auto* rigidBody = collisionObject->GetRigidBody();

						if (rigidBody)
						{
							auto* worldObject = static_cast<Skyrim::hkpWorldObject*>(rigidBody->referencedObject.get());

							if (worldObject)
							{
								pickData.worldRayCastInput.filterInformation = worldObject->linkedCollidable.typedBroadPhaseHandle.collisionFilterInformation;
							}
						}
					}
				}

				break;
			}
		}

		if (!havokWorld->Pick(pickData))
		{
			return false;
		}

		const auto& rayHit         = closestRayHitCollector.rayHit;
		const auto* rootCollidable = rayHit.rootCollidable;

		if (!rootCollidable)
		{
			return false;
		}

		auto position = origin + (ray * rayHit.hitFraction);

		Skyrim::NiPoint3 normal = {
			rayHit.normal.quad.m128_f32[0],
			rayHit.normal.quad.m128_f32[1],
			rayHit.normal.quad.m128_f32[2]
		};

		std::uint32_t       materialID{ 0 };
		Skyrim::NiAVObject* target3D{ nullptr };

		auto terrain = Skyrim::hkpGroupFilter::GetSystemGroupFromFilterInformation(rootCollidable->typedBroadPhaseHandle.collisionFilterInformation) ==
		               Utility::Conversion::ToUnderlying(Skyrim::hkpGroupFilter::SystemGroup::kTerrain);

		if (terrain)
		{
			materialID = Skyrim::TES::GetSingleton()->GetMaterialID(position);

			if (rootCollidable->typedBroadPhaseHandle.type == Utility::Conversion::ToUnderlying(Skyrim::hkpWorldObject::BroadPhaseType::kEntity))
			{
				auto* owner = rootCollidable->GetOwner<Skyrim::hkpWorldObject>();

				if (owner)
				{
					auto* userData = reinterpret_cast<Skyrim::bhkWorldObject*>(owner->userData);

					if (userData)
					{
						auto* property = static_cast<Skyrim::NiAVObject*>(userData->GetProperty(1).GetPointer());

						if (property)
						{
							auto* parentNode = property->parentNode;

							if (parentNode)
							{
								target3D = parentNode;
							}
						}
					}
				}
			}
		}
		else
		{
			const auto* shape = rootCollidable->shape;

			if (shape)
			{
				auto* userData = reinterpret_cast<Skyrim::bhkShape*>(shape->userData);

				if (userData)
				{
					auto        shapeKey  = Skyrim::HK_INVALID_SHAPE_KEY;
					const auto& shapeKeys = rayHit.shapeKeys;

					for (std::int32_t shapeKeyIndex = 0; shapeKeyIndex < Skyrim::hkpShapeRayCastOutput::kMaximumHierarchyDepth; ++shapeKeyIndex)
					{
						if (shapeKeys[shapeKeyIndex] == Skyrim::HK_INVALID_SHAPE_KEY)
						{
							break;
						}

						shapeKey = shapeKeys[shapeKeyIndex];
					}

					materialID = userData->GetMaterialID(shapeKey);
				}
			}

			target3D = rootCollidable->Get3D();
		}

		if (!materialID)
		{
			return false;
		}

		auto* materialType = Skyrim::BGSMaterialType::GetMaterialTypeFromMaterialID(materialID);

		if (!materialType)
		{
			return false;
		}

		auto* impactData = impactDataSet->GetImpactData(materialType);

		if (!impactData)
		{
			return false;
		}

		parentCell->CreateTemporaryEffectParticle(impactData->effectDuration, impactData->GetModelPath(), normal, position, 1.0F, 0x7, nullptr);

		Skyrim::BGSImpactManager::GetSingleton()->PlaySound(Skyrim::BGSImpactManager::SoundData{
			.impactData = impactData,
			.position   = std::addressof(position),
			.source     = nullptr,
			.sound1     = nullptr,
			.sound2     = nullptr,
			.playSound1 = true,
			.playSound2 = true,
			.unknown2A  = 0,
			.unknown30  = 0,
		});

		auto* primaryTextureSet = impactData->primaryTextureSet;

		if (!primaryTextureSet)
		{
			return true;
		}

		auto* target = Skyrim::TESObjectREFR::GetReferenceFrom3D(target3D);

		if (!terrain && (!target || !target->ShouldApplyDecal()))
		{
			return true;
		}

		Skyrim::BGSDecalManager::CreationData creationData;
		creationData.position            = position;
		creationData.normal              = normal;
		creationData.target3D            = Skyrim::NiPointer<Skyrim::NiAVObject>(target3D);
		creationData.primaryTextureSet   = primaryTextureSet;
		creationData.secondaryTextureSet = impactData->secondaryTextureSet;

		const auto& decalData = impactData->decalData;

		std::mt19937                   randomNumberGenerator(std::random_device{}());
		std::uniform_real_distribution widthDistribution(decalData.minimumWidth, decalData.maximumWidth);
		std::uniform_real_distribution heightDistribution(decalData.minimumHeight, decalData.maximumHeight);

		creationData.width  = widthDistribution(randomNumberGenerator);
		creationData.height = heightDistribution(randomNumberGenerator);
		creationData.depth  = decalData.depth;

		const auto& decal = footprint.decal;

		if (decal.rotation.rotate.x || decal.rotation.rotate.y || decal.rotation.rotate.z)
		{
			Skyrim::BSFixedString rotationNodeName = decal.rotation.nodeName;
			auto*                 rotationNode     = rotationNodeName.empty() || !reference3D ? nullptr : reference3D->GetBoneFromName(rotationNodeName, true);

			Skyrim::NiPoint3 eulerAngles;

			if (rotationNode)
			{
				rotationNode->currentWorldTransform.rotation.RotationMatrixToEulerAnglesZXY(eulerAngles.z, eulerAngles.x, eulerAngles.y);
			}
			else
			{
				eulerAngles = reference->rotation;
			}

			if ((decal.rotation.offset.minimum.x || decal.rotation.offset.maximum.x) && (decal.rotation.offset.maximum.x >= decal.rotation.offset.minimum.x))
			{
				std::uniform_real_distribution xDistribution(decal.rotation.offset.minimum.x, decal.rotation.offset.maximum.x);

				eulerAngles.x += xDistribution(randomNumberGenerator) * (std::numbers::pi_v<float> / 180.0F);
			}

			if ((decal.rotation.offset.minimum.y || decal.rotation.offset.maximum.y) && (decal.rotation.offset.maximum.y >= decal.rotation.offset.minimum.y))
			{
				std::uniform_real_distribution yDistribution(decal.rotation.offset.minimum.y, decal.rotation.offset.maximum.y);

				eulerAngles.y += yDistribution(randomNumberGenerator) * (std::numbers::pi_v<float> / 180.0F);
			}

			if ((decal.rotation.offset.minimum.z || decal.rotation.offset.maximum.z) && (decal.rotation.offset.maximum.z >= decal.rotation.offset.minimum.z))
			{
				std::uniform_real_distribution zDistribution(decal.rotation.offset.minimum.z, decal.rotation.offset.maximum.z);

				eulerAngles.z += zDistribution(randomNumberGenerator) * (std::numbers::pi_v<float> / 180.0F);
			}

			creationData.rotation.EulerAnglesToRotationMatrixZXY(
				decal.rotation.rotate.z ? eulerAngles.z : 0.0F,
				decal.rotation.rotate.x ? eulerAngles.x : 0.0F,
				decal.rotation.rotate.y ? eulerAngles.y : 0.0F);
		}

		if (!target)
		{
			creationData.parentCell = Skyrim::TES::GetSingleton()->GetCell(position);
		}

		creationData.parallaxScale   = decalData.parallaxScale;
		creationData.shininess       = decalData.shininess;
		creationData.angleThreshold  = impactData->angleThreshold;
		creationData.placementRadius = impactData->placementRadius;

		creationData.color = Skyrim::NiColor(
			static_cast<float>(decalData.color.red) / 255.0F,
			static_cast<float>(decalData.color.green) / 255.0F,
			static_cast<float>(decalData.color.blue) / 255.0F);

		if (terrain && decal.landColor)
		{
			Skyrim::NiColorA landColor;

			if (Skyrim::TES::GetSingleton()->GetLandColor(position, landColor))
			{
				creationData.color = Skyrim::NiColor(
					std::min(std::max(landColor.red, 0.0F), 1.0F),
					std::min(std::max(landColor.green, 0.0F), 1.0F),
					std::min(std::max(landColor.blue, 0.0F), 1.0F));
			}
		}

		auto decalDataFlags = decalData.decalDataFlags;

		if (decalDataFlags.all(Skyrim::DecalData::Flags::kNoSubTextures))
		{
			creationData.subTextureIndex = -1;
		}
		else
		{
			std::uniform_int_distribution subtextureIndexDistribution(0, 3);

			creationData.subTextureIndex = static_cast<std::int8_t>(subtextureIndexDistribution(randomNumberGenerator));
		}

		creationData.parallax      = decalDataFlags.all(Skyrim::DecalData::Flags::kParallax);
		creationData.alphaTesting  = decalDataFlags.all(Skyrim::DecalData::Flags::kAlphaTesting);
		creationData.alphaBlending = decalDataFlags.all(Skyrim::DecalData::Flags::kAlphaBlending);

		creationData.parallaxPasses = decalData.parallaxPasses;

		DecalManager::AddDecal(Skyrim::BGSDecalManager::GetSingleton(), creationData, decal.force, nullptr);

		return true;
	}
}
