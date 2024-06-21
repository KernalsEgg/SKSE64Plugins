#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESCondition.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESIcon.h"



namespace Skyrim
{
	class Actor;
	class BGSPerkEntry;

	class BGSPerk :
		public TESForm,        // 0
		public TESFullName,    // 20
		public TESDescription, // 30
		public TESIcon         // 40
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kNonPlayable = 1U << 2
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		// Override
		virtual ~BGSPerk() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member functions
		void ApplyPerk(Actor* perkOwner, std::uint8_t removeRank, std::uint8_t applyRank) const;

		// Member variables
		bool                    trait;       // 50
		std::uint8_t            level;       // 51
		std::uint8_t            rankCount;   // 52
		bool                    playable;    // 53
		bool                    hidden;      // 54
		std::uint8_t            padding55;   // 55
		std::uint16_t           padding56;   // 56
		TESCondition            conditions;  // 58
		BSTArray<BGSPerkEntry*> perkEntries; // 60
		BGSPerk*                nextPerk;    // 78
	};
	static_assert(offsetof(BGSPerk, trait) == 0x50);
	static_assert(offsetof(BGSPerk, level) == 0x51);
	static_assert(offsetof(BGSPerk, rankCount) == 0x52);
	static_assert(offsetof(BGSPerk, playable) == 0x53);
	static_assert(offsetof(BGSPerk, hidden) == 0x54);
	static_assert(offsetof(BGSPerk, conditions) == 0x58);
	static_assert(offsetof(BGSPerk, perkEntries) == 0x60);
	static_assert(offsetof(BGSPerk, nextPerk) == 0x78);
	static_assert(sizeof(BGSPerk) == 0x80);
}
