#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class AITimer
	{
	public:
		// Non-member functions
		static float GetTimer();

		// Member variables
		float aiTimer; // 0
		float timer;   // 4
	};
	static_assert(offsetof(AITimer, aiTimer) == 0x0);
	static_assert(offsetof(AITimer, timer) == 0x4);
	static_assert(sizeof(AITimer) == 0x8);
}
