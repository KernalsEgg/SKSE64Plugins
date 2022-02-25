#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"



namespace Skyrim
{
	class hkVector4
	{
	public:
		// Member variables
		hkQuadReal quad; // 0
	};
	static_assert(offsetof(hkVector4, quad) == 0x0);
	static_assert(sizeof(hkVector4) == 0x10);
}
