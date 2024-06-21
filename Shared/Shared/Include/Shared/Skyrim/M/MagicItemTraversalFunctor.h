#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/ForEachResult.h"



namespace Skyrim
{
	struct EffectItem;

	class MagicItemTraversalFunctor
	{
	public:
		// Add
		virtual ~MagicItemTraversalFunctor()                 = default; // 0
		virtual ForEachResult operator()(EffectItem* effect) = 0;       // 1

		// Member variables
		union
		{
		public:
			// Member variables
			float        floatingPoint;
			std::int32_t integer{ 0 };
		} result{};
	};
	static_assert(offsetof(MagicItemTraversalFunctor, result) == 0x8);
	static_assert(sizeof(MagicItemTraversalFunctor) == 0x10);
}
