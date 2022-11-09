#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AITimeStamp.h"
#include "Shared/Skyrim/B/BGSWorldLocation.h"



namespace Skyrim
{
	struct UnreachableLocation
	{
	public:
		// Member variables
		BGSWorldLocation worldLocation; // 0
		AITimeStamp      timeStamp;     // 18
	};
	static_assert(offsetof(UnreachableLocation, worldLocation) == 0x0);
	static_assert(offsetof(UnreachableLocation, timeStamp) == 0x18);
	static_assert(sizeof(UnreachableLocation) == 0x20);
}
