#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	enum class GMemoryStat : std::uint32_t
	{
		// General memory
		kMemory        = 1,
		kDefaultMemory = 2,
		kImageMemory   = 3,
		kSoundMemory   = 4,
		kStringMemory  = 5,
		kVideoMemory   = 6,

		// Debugging memory
		kDebuggingMemory        = 7,
		kDebuggingHUDMemory     = 8,
		kDebuggingTrackerMemory = 9,
		kStatBagMemory          = 10
	};
	static_assert(sizeof(GMemoryStat) == 0x4);
}
