#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	struct TESWaitStopEvent
	{
	public:
		// Member variables
		bool interrupted;
	};
	static_assert(offsetof(TESWaitStopEvent, interrupted) == 0x0);
	static_assert(sizeof(TESWaitStopEvent) == 0x1);
}
