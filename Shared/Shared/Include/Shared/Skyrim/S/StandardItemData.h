#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"



namespace Skyrim
{
	class InventoryEntryData;

	class StandardItemData
	{
	public:
		// Add
		virtual ~StandardItemData();           // 0
		virtual const char*   GetName();       // 1
		virtual std::uint32_t GetCount();      // 2
		virtual std::uint32_t GetEquipState(); // 3
		virtual std::uint32_t GetFilterFlag(); // 4
		virtual std::uint32_t GetFavorited();  // 5
		virtual bool          IsEnabled();     // 6

		// Member variables
		InventoryEntryData*   inventoryEntryData; // 8
		ObjectReferenceHandle owner;              // 10
		std::uint32_t         padding14;          // 14
	};
	static_assert(offsetof(StandardItemData, inventoryEntryData) == 0x8);
	static_assert(offsetof(StandardItemData, owner) == 0x10);
	static_assert(sizeof(StandardItemData) == 0x18);
}
