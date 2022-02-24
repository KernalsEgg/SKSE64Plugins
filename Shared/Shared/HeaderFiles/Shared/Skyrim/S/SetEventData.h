#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSTArray.h"



namespace Skyrim
{
	struct SetEventData
	{
	public:
		// Member variables
		BSFixedString                 event;     // 0
		BSTSmallArray<BSFixedString>* clips;     // 8
		std::uint64_t                 unknown10; // 10
	};
	static_assert(offsetof(SetEventData, event) == 0x0);
	static_assert(offsetof(SetEventData, clips) == 0x8);
	static_assert(sizeof(SetEventData) == 0x18);
}
