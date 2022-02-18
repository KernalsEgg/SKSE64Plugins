#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class BGSPerk;

	struct PerkRank
	{
	public:
		// Member variables
		BGSPerk*     perk;        // 0
		std::int8_t  currentRank; // 8
		std::int8_t  padding9;    // 9
		std::int16_t paddingA;    // A
		std::int32_t paddingC;    // C
	};
	static_assert(offsetof(PerkRank, perk) == 0x0);
	static_assert(offsetof(PerkRank, currentRank) == 0x8);
	static_assert(sizeof(PerkRank) == 0x10);

	class BGSPerkRankArray :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSPerkRankArray() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		PerkRank*     perkRanks;     // 8
		std::uint32_t perkRankCount; // 10
		std::int32_t  padding14;     // 14
	};
	static_assert(offsetof(BGSPerkRankArray, perkRanks) == 0x8);
	static_assert(offsetof(BGSPerkRankArray, perkRankCount) == 0x10);
	static_assert(sizeof(BGSPerkRankArray) == 0x18);
}
