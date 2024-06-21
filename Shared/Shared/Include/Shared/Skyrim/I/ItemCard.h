#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Skyrim/G/GFxValue.h"
#include "Shared/Skyrim/G/GPointer.h"



namespace Skyrim
{
	class GFxMovieView;

	struct ItemCard
	{
	public:
		// Member variables
		GFxValue               object;          // 0
		BSString               informationText; // 18
		std::uint64_t          unknown28;       // 28
		std::uint64_t          unknown30;       // 30
		GPointer<GFxMovieView> movieView;       // 38
	};
	static_assert(offsetof(ItemCard, object) == 0x0);
	static_assert(offsetof(ItemCard, informationText) == 0x18);
	static_assert(offsetof(ItemCard, movieView) == 0x38);
	static_assert(sizeof(ItemCard) == 0x40);
}
