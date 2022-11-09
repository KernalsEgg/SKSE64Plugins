#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	struct AITimeStamp
	{
	public:
		// Member variables
		float timeStamp; // 0
	};
	static_assert(offsetof(AITimeStamp, timeStamp) == 0x0);
	static_assert(sizeof(AITimeStamp) == 0x4);
}
