#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPointFunctionData.h"



namespace Skyrim
{
	class SpellItem;

	class BGSEntryPointFunctionDataSpellItem :
		public BGSEntryPointFunctionData // 0
	{
	public:
		// Override
		virtual ~BGSEntryPointFunctionDataSpellItem() override; // 0

		// Override (BGSEntryPointFunctionData)
		virtual EntryPointFunctionData GetEntryPointFunctionDataType() const override; // 1
		virtual void                   Unknown2(BGSEntryPointFunctionData*) override;  // 2
		virtual void                   Unknown3(BGSEntryPointFunctionData*) override;  // 3

		// Member variables
		SpellItem* spellItem; // 8
	};
	static_assert(offsetof(BGSEntryPointFunctionDataSpellItem, spellItem) == 0x8);
	static_assert(sizeof(BGSEntryPointFunctionDataSpellItem) == 0x10);
}
