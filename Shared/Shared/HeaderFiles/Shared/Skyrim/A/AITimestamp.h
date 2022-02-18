#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	struct AITimestamp
	{
	public:
		// Member variables
		float timestamp; // 0
	};
	static_assert(offsetof(AITimestamp, timestamp) == 0x0);
	static_assert(sizeof(AITimestamp) == 0x4);
}
