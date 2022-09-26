#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class SoulLevel : std::uint32_t
	{
		kNone    = 0,
		kPetty   = 1,
		kLesser  = 2,
		kCommon  = 3,
		kGreater = 4,
		kGrand   = 5
	};
	static_assert(sizeof(SoulLevel) == 0x4);
}
