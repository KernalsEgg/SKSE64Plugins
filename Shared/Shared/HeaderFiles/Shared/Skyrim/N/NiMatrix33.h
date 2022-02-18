#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class NiMatrix33
	{
	public:
		// Member variables
		float elements[3][3]; // 0
	};
	static_assert(offsetof(NiMatrix33, elements) == 0x0);
	static_assert(sizeof(NiMatrix33) == 0x24);
}
