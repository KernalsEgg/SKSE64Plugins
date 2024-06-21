#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/M/MemoryManager.h"



namespace Skyrim
{
	class Actor;
	class AlchemyItem;
	class ExtraDataList;
	class TESBoundObject;
	class TESForm;

	class InventoryEntryData
	{
	public:
		SKYRIM_MEMORY_REDEFINE_NEW();

		InventoryEntryData() = default;
		InventoryEntryData(const InventoryEntryData& right);
		InventoryEntryData(InventoryEntryData&& right);

		~InventoryEntryData();

		InventoryEntryData& operator=(const InventoryEntryData& right);
		InventoryEntryData& operator=(InventoryEntryData&& right);

		// Member functions
		void           AddExtraDataList(ExtraDataList* extraDataList);
		float          GetHealth() const;
		const char*    GetName() const;
		AlchemyItem*   GetPoison() const;
		std::int32_t   GetValue() const;
		ExtraDataList* GetWornExtraDataList(bool eitherHand, bool leftHand) const;
		bool           IsLeveledItem() const;
		bool           IsOwnedBy(Actor* actor, TESForm* owner, bool defaultOwnership) const;
		bool           IsQuestItem() const;
		bool           IsWorn(bool eitherHand, bool leftHand) const;

		// Member variables
		TESBoundObject*               item{ nullptr };           // 0
		BSSimpleList<ExtraDataList*>* extraDataLists{ nullptr }; // 8, Each item in the stack has a separate ExtraDataList
		std::int32_t                  itemCountDelta{ 0 };       // 10
	};
	static_assert(offsetof(InventoryEntryData, item) == 0x0);
	static_assert(offsetof(InventoryEntryData, extraDataLists) == 0x8);
	static_assert(offsetof(InventoryEntryData, itemCountDelta) == 0x10);
	static_assert(sizeof(InventoryEntryData) == 0x18);
}
