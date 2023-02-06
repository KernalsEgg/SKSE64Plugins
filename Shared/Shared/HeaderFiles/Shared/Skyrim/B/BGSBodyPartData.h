#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/B/BGSPreloadable.h"
#include "Shared/Skyrim/B/BodyPartType.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Skyrim/T/TESModelPSA.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSDebris;
	class BGSExplosion;
	class BGSImpactDataSet;
	class BGSRagdoll;

	class BGSBodyPartData :
		public TESForm,       // 0
		public TESModel,      // 20
		public BGSPreloadable // 48
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone                    = 0,
			kSeverable               = 1U << 0,
			kIKData                  = 1U << 1,
			kIKDataBipedData         = 1U << 2,
			kExplodable              = 1U << 3,
			kIKDataIsHead            = 1U << 4,
			kIKDataHeadTracking      = 1U << 5,
			kExplosionChanceAbsolute = 1U << 6
		};
		static_assert(sizeof(Flags) == 0x1);

		struct BodyPart
		{
		public:
			// Member variables
			BSFixedString                                    partNode;                       // 0
			BSFixedString                                    vatsTarget;                     // 8
			BSFixedString                                    ikDataStartNode;                // 10
			BSFixedString                                    partName;                       // 18
			BSFixedString                                    goreEffectsTargetBone;          // 20
			TESModel                                         explodableLimbReplacement;      // 28
			TESModelPSA                                      poseMatching;                   // 50
			float                                            damageMultiplier;               // 78
			Utility::Enumeration<Flags, std::uint8_t>        bodyPartFlags;                  // 7C
			Utility::Enumeration<BodyPartType, std::uint8_t> partType;                       // 7D
			std::uint8_t                                     healthPercentage;               // 7E
			Utility::Enumeration<ActorValue, std::uint8_t>   actorValue;                     // 7F
			std::uint8_t                                     toHitChance;                    // 80
			std::uint8_t                                     explodableExplosionChance;      // 81
			std::uint8_t                                     explodableGenericDebrisCount;   // 82
			std::uint8_t                                     padding83;                      // 83
			std::uint32_t                                    padding84;                      // 84
			BGSDebris*                                       explodableGenericDebris;        // 88
			BGSExplosion*                                    explodableExplosion;            // 90
			float                                            trackingMaximumAngle;           // 98
			float                                            explodableGenericDebrisScale;   // 9C
			std::uint8_t                                     severableGenericDebrisCount;    // A0
			std::uint8_t                                     paddingA1;                      // A1
			std::uint16_t                                    paddingA2;                      // A2
			std::uint32_t                                    paddingA4;                      // A4
			BGSDebris*                                       severableGenericDebris;         // A8
			BGSExplosion*                                    severableExplosion;             // B0
			float                                            severableGenericDebrisScale;    // B8
			NiPoint3                                         goreEffectsLocalTranslate;      // BC
			NiPoint3                                         goreEffectsLocalRotate;         // C8
			std::uint32_t                                    paddingD4;                      // D4
			BGSImpactDataSet*                                severableBloodSpurt;            // D8
			BGSImpactDataSet*                                explodableBloodSpurt;           // E0
			std::uint8_t                                     severableDecalCount;            // E8
			std::uint8_t                                     explodableDecalCount;           // E9
			std::uint16_t                                    paddingEA;                      // EA
			float                                            explodableLimbReplacementScale; // EC
		};
		static_assert(offsetof(BodyPart, partNode) == 0x0);
		static_assert(offsetof(BodyPart, vatsTarget) == 0x8);
		static_assert(offsetof(BodyPart, ikDataStartNode) == 0x10);
		static_assert(offsetof(BodyPart, partName) == 0x18);
		static_assert(offsetof(BodyPart, goreEffectsTargetBone) == 0x20);
		static_assert(offsetof(BodyPart, explodableLimbReplacement) == 0x28);
		static_assert(offsetof(BodyPart, poseMatching) == 0x50);
		static_assert(offsetof(BodyPart, damageMultiplier) == 0x78);
		static_assert(offsetof(BodyPart, bodyPartFlags) == 0x7C);
		static_assert(offsetof(BodyPart, partType) == 0x7D);
		static_assert(offsetof(BodyPart, healthPercentage) == 0x7E);
		static_assert(offsetof(BodyPart, actorValue) == 0x7F);
		static_assert(offsetof(BodyPart, toHitChance) == 0x80);
		static_assert(offsetof(BodyPart, explodableExplosionChance) == 0x81);
		static_assert(offsetof(BodyPart, explodableGenericDebrisCount) == 0x82);
		static_assert(offsetof(BodyPart, explodableGenericDebris) == 0x88);
		static_assert(offsetof(BodyPart, explodableExplosion) == 0x90);
		static_assert(offsetof(BodyPart, trackingMaximumAngle) == 0x98);
		static_assert(offsetof(BodyPart, explodableGenericDebrisScale) == 0x9C);
		static_assert(offsetof(BodyPart, severableGenericDebrisCount) == 0xA0);
		static_assert(offsetof(BodyPart, severableGenericDebris) == 0xA8);
		static_assert(offsetof(BodyPart, severableExplosion) == 0xB0);
		static_assert(offsetof(BodyPart, severableGenericDebrisScale) == 0xB8);
		static_assert(offsetof(BodyPart, goreEffectsLocalTranslate) == 0xBC);
		static_assert(offsetof(BodyPart, goreEffectsLocalRotate) == 0xC8);
		static_assert(offsetof(BodyPart, severableBloodSpurt) == 0xD8);
		static_assert(offsetof(BodyPart, explodableBloodSpurt) == 0xE0);
		static_assert(offsetof(BodyPart, severableDecalCount) == 0xE8);
		static_assert(offsetof(BodyPart, explodableDecalCount) == 0xE9);
		static_assert(offsetof(BodyPart, explodableLimbReplacementScale) == 0xEC);
		static_assert(sizeof(BodyPart) == 0xF0);

		// Override
		virtual ~BGSBodyPartData() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Override (BGSPreloadable)
		virtual void Unknown4(BGSPreloadable*) override; // 4

		// Member variables
		BodyPart*   partData[Utility::ToUnderlying(BodyPartType::kTotal)]; // 50
		BGSRagdoll* ragdollData;                                           // 80
	};
	static_assert(offsetof(BGSBodyPartData, partData) == 0x50);
	static_assert(offsetof(BGSBodyPartData, ragdollData) == 0x80);
	static_assert(sizeof(BGSBodyPartData) == 0x88);
}
