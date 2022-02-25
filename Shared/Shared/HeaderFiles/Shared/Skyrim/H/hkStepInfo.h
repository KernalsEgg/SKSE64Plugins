#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"



namespace Skyrim
{
	class hkStepInfo
	{
	public:
		alignas(0x10) hkTime startTime; // 0
		hkTime endTime;                 // 4
		float  deltaTime;               // 8
		float  inverseDeltaTime;        // C
	};
	static_assert(offsetof(hkStepInfo, startTime) == 0x0);
	static_assert(offsetof(hkStepInfo, endTime) == 0x4);
	static_assert(offsetof(hkStepInfo, deltaTime) == 0x8);
	static_assert(offsetof(hkStepInfo, inverseDeltaTime) == 0xC);
	static_assert(sizeof(hkStepInfo) == 0x10);
}
