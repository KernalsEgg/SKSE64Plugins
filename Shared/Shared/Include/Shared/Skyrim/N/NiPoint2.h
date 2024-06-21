#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class NiPoint2
	{
	public:
		// Member variables
		float x; // 0
		float y; // 4
	};
	static_assert(offsetof(NiPoint2, x) == 0x0);
	static_assert(offsetof(NiPoint2, y) == 0x4);
	static_assert(sizeof(NiPoint2) == 0x8);
}
