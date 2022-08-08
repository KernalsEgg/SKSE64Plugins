#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/M/MemoryManager.h"



namespace Skyrim
{
	class Actor;
	class ExtraDataList;
	class TESBoundObject;
	class TESForm;

	template <class T>
	class BSSimpleList;

	class InventoryEntryData
	{
	public:
		SKYRIM_HEAP_OPERATORS();

		InventoryEntryData() = default;
		InventoryEntryData(const InventoryEntryData& right);
		InventoryEntryData(InventoryEntryData&& right);

		~InventoryEntryData();

		InventoryEntryData& operator=(const InventoryEntryData& right);
		InventoryEntryData& operator=(InventoryEntryData&& right);

		// Member functions
		float          GetHealth() const;
		const char*    GetName() const;
		std::int32_t   GetValue() const;
		ExtraDataList* GetWornExtraDataList(bool eitherHand, bool leftHand) const;
		bool           IsOwnedBy(Actor* actor, TESForm* owner, bool defaultOwnership);
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
