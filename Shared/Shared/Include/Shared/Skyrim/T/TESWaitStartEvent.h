#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	struct TESWaitStartEvent
	{
	public:
		// Member variables
		float startTime;      // Game days passed
		float desiredEndTime; // Game days passed
	};
	static_assert(offsetof(TESWaitStartEvent, startTime) == 0x0);
	static_assert(offsetof(TESWaitStartEvent, desiredEndTime) == 0x4);
	static_assert(sizeof(TESWaitStartEvent) == 0x8);
}
