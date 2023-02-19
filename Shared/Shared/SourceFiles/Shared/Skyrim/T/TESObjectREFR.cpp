#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESObjectREFR.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESContainer.h"
#include "Shared/Skyrim/T/TESNPC.h"
#include "Shared/Skyrim/T/TESObjectCELL.h"
#include "Shared/Skyrim/T/TESObjectCONT.h"
#include "Shared/Skyrim/T/TESRace.h"
#include "Shared/Skyrim/T/TESWorldSpace.h"
#include "Shared/Utility/Enumeration.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	TESObjectREFR* TESObjectREFR::GetReferenceFrom3D(NiAVObject* avObject)
	{
		auto* function{ reinterpret_cast<decltype(TESObjectREFR::GetReferenceFrom3D)*>(Addresses::TESObjectREFR::GetReferenceFrom3D) };

		return function(avObject);
	}

	bool TESObjectREFR::Activate(TESObjectREFR* activator, bool deferred, TESBoundObject* item, std::int32_t itemCount, bool defaultProcessingOnly)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&TESObjectREFR::Activate)>::type>(Addresses::TESObjectREFR::Activate) };

		return function(this, activator, deferred, item, itemCount, defaultProcessingOnly);
	}

	TESContainer* TESObjectREFR::GetContainer() const
	{
		auto* baseObject = this->baseObject;

		if (baseObject)
		{
			switch (baseObject->formType.get())
			{
				case FormType::kContainer:
				{
					return static_cast<TESContainer*>(static_cast<TESObjectCONT*>(baseObject));
				}
				case FormType::kNPC:
				{
					return static_cast<TESContainer*>(static_cast<TESNPC*>(baseObject));
				}
			}
		}

		return nullptr;
	}

	float TESObjectREFR::GetDistanceSquared(TESObjectREFR* target) const
	{
		return ((target->position.x - this->position.x) * (target->position.x - this->position.x)) +
		       ((target->position.y - this->position.y) * (target->position.y - this->position.y)) +
		       ((target->position.z - this->position.z) * (target->position.z - this->position.z));
	}

	float TESObjectREFR::GetDistanceSquared(TESObjectREFR* target, bool ignoreDisabled, bool ignoreWorldSpace) const
	{
		if (target &&
			(Utility::Enumeration<TESObjectREFR::RecordFlags, std::uint32_t>(target->recordFlags).none(TESObjectREFR::RecordFlags::kDisabled) || ignoreDisabled) &&
			(Utility::Enumeration<TESObjectREFR::RecordFlags, std::uint32_t>(target->recordFlags).none(TESObjectREFR::RecordFlags::kDeleted)) &&
			(ignoreWorldSpace || this->SameWorldSpace(target, true)))
		{
			return this->GetDistanceSquared(target);
		}
		else
		{
			return std::numeric_limits<float>::max();
		}
	}

	bool TESObjectREFR::GetInteraction(BSTSmartPointer<RefrInteraction>& referenceInteraction) const
	{
		return this->extraDataList.GetInteraction(referenceInteraction);
	}

	InventoryChanges* TESObjectREFR::GetInventoryChanges()
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&TESObjectREFR::GetInventoryChanges)>::type>(Addresses::TESObjectREFR::GetInventoryChanges) };

		return function(this);
	}

	const char* TESObjectREFR::GetReferenceName() const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&TESObjectREFR::GetReferenceName)>::type>(Addresses::TESObjectREFR::GetReferenceName) };

		return function(this);
	}

	BipedObjectSlot TESObjectREFR::GetShieldObject() const
	{
		auto* baseObject = this->baseObject;

		if (!baseObject || baseObject->formType != FormType::kNPC)
		{
			return BipedObjectSlot::kNone;
		}

		auto* race = static_cast<TESNPC*>(baseObject)->race;

		return race ? race->shieldBipedObject.get() : BipedObjectSlot::kNone;
	}

	bool TESObjectREFR::Is3DLoaded() const
	{
		return this->GetThirdPerson3D() != nullptr;
	}

	bool TESObjectREFR::SameWorldSpace(TESObjectREFR* target, bool compareParentWorldSpace) const
	{
		auto* parentCell       = this->parentCell;
		auto* targetParentCell = target->parentCell;

		if ((parentCell && parentCell->cellFlags.all(TESObjectCELL::Flags::kInteriorCell)) ||
			(targetParentCell && targetParentCell->cellFlags.all(TESObjectCELL::Flags::kInteriorCell)))
		{
			return parentCell == targetParentCell;
		}

		TESWorldSpace* worldSpace{ nullptr };
		TESWorldSpace* targetWorldSpace{ nullptr };

		if (parentCell)
		{
			if (parentCell->cellFlags.none(TESObjectCELL::Flags::kInteriorCell))
			{
				worldSpace = parentCell->worldSpace;
			}
		}
		else
		{
			auto* persistentCell = this->GetPersistentCell();

			if (persistentCell && persistentCell->cellFlags.none(TESObjectCELL::Flags::kInteriorCell))
			{
				worldSpace = persistentCell->worldSpace;
			}
		}

		if (targetParentCell)
		{
			if (!targetParentCell->cellFlags.none(TESObjectCELL::Flags::kInteriorCell))
			{
				targetWorldSpace = targetParentCell->worldSpace;
			}
		}
		else
		{
			auto* targetPersistentCell = target->GetPersistentCell();

			if (targetPersistentCell && targetPersistentCell->cellFlags.none(TESObjectCELL::Flags::kInteriorCell))
			{
				targetWorldSpace = targetPersistentCell->worldSpace;
			}
		}

		if (worldSpace == targetWorldSpace)
		{
			return true;
		}

		if (!compareParentWorldSpace || !worldSpace || !targetWorldSpace)
		{
			return false;
		}

		auto* parentWorldSpace = worldSpace->parentWorldSpace;

		if (parentWorldSpace && worldSpace->useFlags.all(TESWorldSpace::UseFlags::kUseLandData))
		{
			worldSpace = parentWorldSpace;
		}

		auto* targetParentWorldSpace = targetWorldSpace->parentWorldSpace;

		if (targetParentWorldSpace && targetWorldSpace->useFlags.all(TESWorldSpace::UseFlags::kUseLandData))
		{
			targetWorldSpace = targetParentWorldSpace;
		}

		return worldSpace == targetWorldSpace;
	}

	bool TESObjectREFR::ShouldApplyDecal() const
	{
		if (this->IsWater())
		{
			return false;
		}

		if (this->baseObject->formType == FormType::kNPC || this->baseObject->formType == FormType::kProjectile)
		{
			return false;
		}

		return true;
	}
}
