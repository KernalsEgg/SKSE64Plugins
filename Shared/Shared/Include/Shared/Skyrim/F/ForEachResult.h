#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class ForEachResult : std::uint32_t
	{
		kStop     = 0,
		kContinue = 1
	};
	static_assert(sizeof(ForEachResult) == 0x4);
}
