#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	struct Effect;

	class MagicItemTraversalFunctor
	{
	public:
		enum class ReturnType : std::uint32_t
		{
			kStop     = 0,
			kContinue = 1
		};
		static_assert(sizeof(ReturnType) == 0x4);

		// Add
		virtual ~MagicItemTraversalFunctor();            // 0
		virtual ReturnType Traverse(Effect* effect) = 0; // 1

		// Member variables
		std::uint64_t unknown8; // 8
	};
	static_assert(sizeof(MagicItemTraversalFunctor) == 0x10);
}
