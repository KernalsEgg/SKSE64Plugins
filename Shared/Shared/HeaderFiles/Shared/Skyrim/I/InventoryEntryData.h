#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSSimpleList.h"



namespace Skyrim
{
	class ExtraDataList;
	class TESBoundObject;

	class InventoryEntryData
	{
	public:
		// Member functions
		std::int32_t GetValue() const;
		bool         IsQuestItem() const;
		bool         IsWorn() const;

		// Member variables
		TESBoundObject*               item;           // 0
		BSSimpleList<ExtraDataList*>* extraDataLists; // 8
		std::int32_t                  itemCountDelta; // 10
		std::uint32_t                 padding14;      // 14
	};
	static_assert(offsetof(InventoryEntryData, item) == 0x0);
	static_assert(offsetof(InventoryEntryData, extraDataLists) == 0x8);
	static_assert(offsetof(InventoryEntryData, itemCountDelta) == 0x10);
	static_assert(sizeof(InventoryEntryData) == 0x18);
}
