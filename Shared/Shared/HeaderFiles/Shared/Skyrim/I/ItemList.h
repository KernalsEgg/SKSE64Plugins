#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/G/GFxValue.h"
#include "Shared/Skyrim/G/GPointer.h"
#include "Shared/Skyrim/S/StandardItemData.h"



namespace Skyrim
{
	class GFxMovieView;
	class TESObjectREFR;

	struct ItemList
	{
	public:
		struct Item
		{
		public:
			// Member variables
			StandardItemData standardItemData; // 0
			GFxValue         object;           // 18
			std::uint64_t    unknown30;        // 30
			std::uint64_t    unknown38;        // 38
		};
		static_assert(offsetof(Item, standardItemData) == 0x0);
		static_assert(sizeof(Item) == 0x40);

		// Member functions
		Item* GetSelectedItem();
		void  Update(TESObjectREFR* owner);

		// Member variables
		GPointer<GFxMovieView> movieView; // 0
		GFxValue               root;      // 8
		GFxValue               entryList; // 20
		BSTArray<Item*>        items;     // 38
		std::uint64_t          unknown50; // 50
	};
	static_assert(offsetof(ItemList, movieView) == 0x0);
	static_assert(offsetof(ItemList, root) == 0x8);
	static_assert(offsetof(ItemList, entryList) == 0x20);
	static_assert(offsetof(ItemList, items) == 0x38);
	static_assert(sizeof(ItemList) == 0x58);
}
