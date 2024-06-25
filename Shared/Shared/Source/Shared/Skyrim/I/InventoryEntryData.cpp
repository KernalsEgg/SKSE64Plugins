#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/InventoryEntryData.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	InventoryEntryData::InventoryEntryData(const InventoryEntryData& right) :
		boundObject(right.boundObject),
		countDelta(right.countDelta)
	{
		if (right.extraDataLists)
		{
			this->extraDataLists = new BSSimpleList<ExtraDataList*>(*right.extraDataLists);
		}
	}

	InventoryEntryData::InventoryEntryData(InventoryEntryData&& right) :
		boundObject(right.boundObject),
		extraDataLists(right.extraDataLists),
		countDelta(right.countDelta)
	{
		right.boundObject    = nullptr;
		right.extraDataLists = nullptr;
		right.countDelta     = 0;
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

			this->boundObject    = right.boundObject;
			this->extraDataLists = right.extraDataLists ? new BSSimpleList<ExtraDataList*>(*right.extraDataLists) : nullptr;
			this->countDelta     = right.countDelta;
		}

		return *this;
	}

	InventoryEntryData& InventoryEntryData::operator=(InventoryEntryData&& right)
	{
		if (this != std::addressof(right))
		{
			delete this->extraDataLists;

			this->boundObject    = right.boundObject;
			this->extraDataLists = right.extraDataLists;
			this->countDelta     = right.countDelta;

			right.boundObject    = nullptr;
			right.extraDataLists = nullptr;
			right.countDelta     = 0;
		}

		return *this;
	}

	void InventoryEntryData::AddExtraDataList(ExtraDataList* extraDataList)
	{
		if (!extraDataList)
		{
			return;
		}

		if (!this->extraDataLists)
		{
			this->extraDataLists = new BSSimpleList<ExtraDataList*>();
		}

		this->extraDataLists->push_front(extraDataList);
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
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&InventoryEntryData::GetName)>::type>(
			Addresses::InventoryEntryData::GetName()) };

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
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&InventoryEntryData::GetValue)>::type>(
			Addresses::InventoryEntryData::GetValue()) };

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

	bool InventoryEntryData::IsLeveledBoundObject() const
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

				if (extraDataList->IsLeveledBoundObject())
				{
					return true;
				}
			}
		}

		return false;
	}

	bool InventoryEntryData::IsOwnedBy(Actor* actor, TESForm* owner, bool defaultOwnership) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&InventoryEntryData::IsOwnedBy)>::type>(
			Addresses::InventoryEntryData::IsOwnedBy()) };

		return function(this, actor, owner, defaultOwnership);
	}

	bool InventoryEntryData::IsQuestBoundObject() const
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

				if (extraDataList->IsQuestBoundObject())
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
