#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSPreloadable.h"
#include "Shared/Skyrim/S/SoundLevel.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESEnchantableForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESImageSpaceModifiableForm.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSImpactDataSet;
	class BGSProjectile;
	class BGSSoundDescriptorForm;
	class TESObjectLIGH;
	class TESObjectREFR;

	class BGSExplosion :
		public TESBoundObject,             // 0
		public TESFullName,                // 30
		public TESModel,                   // 40
		public TESEnchantableForm,         // 68
		public BGSPreloadable,             // 80
		public TESImageSpaceModifiableForm // 88
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                             = 0,
			kAlwaysUsesWorldOrientation       = 1U << 1,
			kKnockDownLivingActorsAlways      = 1U << 2,
			kKnockDownLivingActorsByFormula   = 1U << 3,
			kIgnoreLOSCheck                   = 1U << 4,
			kPushExplosionSourceReferenceOnly = 1U << 5,
			kIgnoreImageSpaceSwap             = 1U << 6,
			kChain                            = 1U << 7,
			kNoControllerVibration            = 1U << 8
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~BGSExplosion() override; // 0

		// Override (TESBoundObject)
		virtual void InitializeData() override;      // 4
		virtual bool Load(TESFile* file) override;   // 6
		virtual void Unknown13(TESForm*) override;   // 13
		virtual void Unknown40(TESObject*) override; // 40
		virtual void Unknown41(TESObject*) override; // 41

		// Override (BGSPreloadable)
		virtual void Unknown4(BGSPreloadable*) override; // 4

		// Member variables
		TESObjectLIGH*                                  light;                    // 98
		BGSSoundDescriptorForm*                         sound1;                   // A0
		BGSSoundDescriptorForm*                         sound2;                   // A8
		BGSImpactDataSet*                               impactDataSet;            // B0
		TESObjectREFR*                                  placedObject;             // B8
		BGSProjectile*                                  spawnProjectile;          // C0
		float                                           force;                    // C8
		float                                           damage;                   // CC
		float                                           radius;                   // D0
		float                                           imageSpaceRadius;         // D4
		float                                           verticalOffsetMultiplier; // D8
		Utility::Enumeration<Flags, std::uint32_t>      explosionFlags;           // DC
		Utility::Enumeration<SoundLevel, std::uint32_t> soundLevel;               // E0
		std::uint32_t                                   paddingE4;                // E4
	};
	static_assert(offsetof(BGSExplosion, light) == 0x98);
	static_assert(offsetof(BGSExplosion, sound1) == 0xA0);
	static_assert(offsetof(BGSExplosion, sound2) == 0xA8);
	static_assert(offsetof(BGSExplosion, impactDataSet) == 0xB0);
	static_assert(offsetof(BGSExplosion, placedObject) == 0xB8);
	static_assert(offsetof(BGSExplosion, spawnProjectile) == 0xC0);
	static_assert(offsetof(BGSExplosion, force) == 0xC8);
	static_assert(offsetof(BGSExplosion, damage) == 0xCC);
	static_assert(offsetof(BGSExplosion, radius) == 0xD0);
	static_assert(offsetof(BGSExplosion, imageSpaceRadius) == 0xD4);
	static_assert(offsetof(BGSExplosion, verticalOffsetMultiplier) == 0xD8);
	static_assert(offsetof(BGSExplosion, explosionFlags) == 0xDC);
	static_assert(offsetof(BGSExplosion, soundLevel) == 0xE0);
	static_assert(sizeof(BGSExplosion) == 0xE8);
}
