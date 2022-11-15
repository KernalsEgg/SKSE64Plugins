#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/InventoryEntryData.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	InventoryEntryData::InventoryEntryData(const InventoryEntryData& right) :
		item(right.item),
		itemCountDelta(right.itemCountDelta)
	{
		if (right.extraDataLists)
		{
			this->extraDataLists = new BSSimpleList<ExtraDataList*>(*right.extraDataLists);
		}
	}

	InventoryEntryData::InventoryEntryData(InventoryEntryData&& right) :
		item(right.item),
		extraDataLists(right.extraDataLists),
		itemCountDelta(right.itemCountDelta)
	{
		right.item           = nullptr;
		right.extraDataLists = nullptr;
		right.itemCountDelta = 0;
	}

	InventoryEntryData::~InventoryEntryData()
	{
		delete this->extraDataLists;
	}

	InventoryEntryData& InventoryEntryData::operator=(const InventoryEntryData& right)
	{
		if (this != std::addressof(right))
		{
			delete this->extraDataLists;

			this->item           = right.item;
			this->extraDataLists = right.extraDataLists ? new BSSimpleList<ExtraDataList*>(*right.extraDataLists) : nullptr;
			this->itemCountDelta = right.itemCountDelta;
		}

		return *this;
	}

	InventoryEntryData& InventoryEntryData::operator=(InventoryEntryData&& right)
	{
		if (this != std::addressof(right))
		{
			delete this->extraDataLists;

			this->item           = right.item;
			this->extraDataLists = right.extraDataLists;
			this->itemCountDelta = right.itemCountDelta;

			right.item           = nullptr;
			right.extraDataLists = nullptr;
			right.itemCountDelta = 0;
		}

		return *this;
	}

	float InventoryEntryData::GetHealth() const
	{
		float result{ 1.0F };

		auto* extraDataLists = this->extraDataLists;

		if (extraDataLists)
		{
			for (auto* extraDataList : *extraDataLists)
			{
				if (!extraDataList)
				{
					break;
				}

				auto health = extraDataList->GetHealth();

				if (health > result)
				{
					result = health;
				}
			}
		}

		return result;
	}

	const char* InventoryEntryData::GetName() const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&InventoryEntryData::GetName)>::type>(Addresses::InventoryEntryData::GetName) };

		return function(this);
	}

	AlchemyItem* InventoryEntryData::GetPoison() const
	{
		auto* extraDataLists = this->extraDataLists;

		if (extraDataLists)
		{
			for (auto* extraDataList : *extraDataLists)
			{
				if (!extraDataList)
				{
					break;
				}

				auto* poison = extraDataList->GetPoison();

				if (poison)
				{
					return poison;
				}
			}
		}

		return nullptr;
	}

	std::int32_t InventoryEntryData::GetValue() const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&InventoryEntryData::GetValue)>::type>(Addresses::InventoryEntryData::GetValue) };

		return function(this);
	}

	ExtraDataList* InventoryEntryData::GetWornExtraDataList(bool eitherHand, bool leftHand) const
	{
		auto* extraDataLists = this->extraDataLists;

		if (extraDataLists)
		{
			for (auto* extraDataList : *extraDataLists)
			{
				if (!extraDataList)
				{
					break;
				}

				if (extraDataList->IsWorn(eitherHand, leftHand))
				{
					return extraDataList;
				}
			}
		}

		return nullptr;
	}

	bool InventoryEntryData::IsOwnedBy(Actor* actor, TESForm* owner, bool defaultOwnership) const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&InventoryEntryData::IsOwnedBy)>::type>(Addresses::InventoryEntryData::IsOwnedBy) };

		return function(this, actor, owner, defaultOwnership);
	}

	bool InventoryEntryData::IsQuestItem() const
	{
		auto* extraDataLists = this->extraDataLists;

		if (extraDataLists)
		{
			for (auto* extraDataList : *extraDataLists)
			{
				if (!extraDataList)
				{
					break;
				}

				if (extraDataList->IsQuestItem())
				{
					return true;
				}
			}
		}

		return false;
	}

	bool InventoryEntryData::IsWorn(bool eitherHand, bool leftHand) const
	{
		auto* extraDataLists = this->extraDataLists;

		if (extraDataLists)
		{
			for (auto* extraDataList : *extraDataLists)
			{
				if (!extraDataList)
				{
					break;
				}

				if (extraDataList->IsWorn(eitherHand, leftHand))
				{
					return true;
				}
			}
		}

		return false;
	}
}
