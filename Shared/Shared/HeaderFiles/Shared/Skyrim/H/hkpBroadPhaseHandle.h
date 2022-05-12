#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class hkpBroadPhaseHandle
	{
	public:
		// Member variables
		std::uint32_t id; // 0
	};
	static_assert(offsetof(hkpBroadPhaseHandle, id) == 0x0);
	static_assert(sizeof(hkpBroadPhaseHandle) == 0x4);
}
