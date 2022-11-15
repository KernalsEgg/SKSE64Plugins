#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/ItemList.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	ItemList::Item* ItemList::GetSelectedItem()
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&ItemList::GetSelectedItem)>::type>(Addresses::ItemList::GetSelectedItem) };

		return function(this);
	}

	void ItemList::Update(TESObjectREFR* owner)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&ItemList::Update)>::type>(Addresses::ItemList::Update) };

		return function(this, owner);
	}
}
