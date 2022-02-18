#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSSimpleList.h"



namespace Skyrim
{
	class InventoryEntryData;
	class TESObjectREFR;

	class InventoryChanges
	{
	public:
		// Member functions
		void ResetWeight();

		// Member variables
		BSSimpleList<InventoryEntryData*>* inventoryEntryDataList;  // 0
		TESObjectREFR*                     owner;                   // 8
		float                              currentInventoryWeight;  // 10
		float                              previousInventoryWeight; // 14
		bool                               changed;                 // 18
		std::int8_t                        padding19;               // 19
		std::int16_t                       padding1A;               // 1A
		std::int32_t                       padding1C;               // 1C
	};
	static_assert(offsetof(InventoryChanges, inventoryEntryDataList) == 0x0);
	static_assert(offsetof(InventoryChanges, owner) == 0x8);
	static_assert(offsetof(InventoryChanges, currentInventoryWeight) == 0x10);
	static_assert(offsetof(InventoryChanges, previousInventoryWeight) == 0x14);
	static_assert(offsetof(InventoryChanges, changed) == 0x18);
	static_assert(sizeof(InventoryChanges) == 0x20);
}
