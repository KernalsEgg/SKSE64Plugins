#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiPoint3.h"



namespace Skyrim
{
	class NiBound
	{
	public:
		// Member variables
		NiPoint3 center; // 0
		float    radius; // C
	};
	static_assert(offsetof(NiBound, center) == 0x0);
	static_assert(offsetof(NiBound, radius) == 0xC);
	static_assert(sizeof(NiBound) == 0x10);
}
