#include "Shared/PCH.h"

#include "Shared/Skyrim/I/InventoryEntryData.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	std::int32_t InventoryEntryData::GetValue() const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&InventoryEntryData::GetValue)>::type>(Addresses::InventoryEntryData::GetValue) };

		return function(this);
	}

	bool InventoryEntryData::IsQuestItem() const
	{
		auto extraDataLists = this->extraDataLists;

		if (extraDataLists)
		{
			for (auto extraDataList : *extraDataLists)
			{
				if (extraDataList->IsQuestItem())
				{
					return true;
				}
			}
		}

		return false;
	}

	bool InventoryEntryData::IsWorn() const
	{
		auto extraDataLists = this->extraDataLists;

		if (extraDataLists)
		{
			for (auto extraDataList : *extraDataLists)
			{
				if (extraDataList->IsWorn())
				{
					return true;
				}
			}
		}

		return false;
	}
}
