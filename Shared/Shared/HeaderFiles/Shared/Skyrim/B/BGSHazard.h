#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSPreloadable.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESImageSpaceModifiableForm.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSImpactDataSet;
	class BGSSoundDescriptorForm;
	class SpellItem;
	class TESObjectLIGH;

	class BGSHazard :
		public TESBoundObject,             // 0
		public TESFullName,                // 30
		public TESModel,                   // 40
		public BGSPreloadable,             // 68
		public TESImageSpaceModifiableForm // 70
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                          = 0,
			kAffectsPlayerOnly             = 1U << 0,
			kInheritDurationFromSpawnSpell = 1U << 1,
			kAlignToImpactNormal           = 1U << 2,
			kInheritRadiusFromSpawnSpell   = 1U << 3,
			kDropToGround                  = 1U << 4
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~BGSHazard() override; // 0

		// Override (TESBoundObject)
		virtual void InitializeData() override;    // 4
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Override (BGSPreloadable)
		virtual void Unknown4(BGSPreloadable*) override; // 4

		// Member variables
		std::uint32_t                              limit;            // 80
		float                                      radius;           // 84
		float                                      lifetime;         // 88
		float                                      imageSpaceRadius; // 8C
		float                                      targetInterval;   // 90
		Utility::Enumeration<Flags, std::uint32_t> hazardFlags;      // 94
		SpellItem*                                 spell;            // 98
		TESObjectLIGH*                             light;            // A0
		BGSImpactDataSet*                          impactDataSet;    // A8
		BGSSoundDescriptorForm*                    sound;            // B0
	};
	static_assert(offsetof(BGSHazard, limit) == 0x80);
	static_assert(offsetof(BGSHazard, radius) == 0x84);
	static_assert(offsetof(BGSHazard, lifetime) == 0x88);
	static_assert(offsetof(BGSHazard, imageSpaceRadius) == 0x8C);
	static_assert(offsetof(BGSHazard, targetInterval) == 0x90);
	static_assert(offsetof(BGSHazard, hazardFlags) == 0x94);
	static_assert(offsetof(BGSHazard, spell) == 0x98);
	static_assert(offsetof(BGSHazard, light) == 0xA0);
	static_assert(offsetof(BGSHazard, impactDataSet) == 0xA8);
	static_assert(offsetof(BGSHazard, sound) == 0xB0);
	static_assert(sizeof(BGSHazard) == 0xB8);
}
