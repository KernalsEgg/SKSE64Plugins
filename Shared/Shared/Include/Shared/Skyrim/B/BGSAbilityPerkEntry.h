#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSPerkEntry.h"



namespace Skyrim
{
	class SpellItem;

	class BGSAbilityPerkEntry :
		public BGSPerkEntry // 0
	{
	public:
		// Override
		virtual ~BGSAbilityPerkEntry() override; // 3

		// Override (BGSPerkEntry)
		virtual PerkEntryType GetPerkEntryType() const override;          // 4
		virtual void          Unknown6(BGSPerkEntry*) override;           // 6
		virtual void          Unknown7(BGSPerkEntry*) override;           // 7
		virtual void          ApplyPerkEntry(Actor* perkOwner) override;  // A
		virtual void          RemovePerkEntry(Actor* perkOwner) override; // B

		// Member variables
		SpellItem* ability; // 10
	};
	static_assert(offsetof(BGSAbilityPerkEntry, ability) == 0x10);
	static_assert(sizeof(BGSAbilityPerkEntry) == 0x18);
}
