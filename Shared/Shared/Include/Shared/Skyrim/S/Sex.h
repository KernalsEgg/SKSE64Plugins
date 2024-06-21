#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class Sex : std::uint32_t
	{
		kNone   = static_cast<std::underlying_type_t<Sex>>(-1),
		kMale   = 0,
		kFemale = 1,
		kTotal  = 2
	};
	static_assert(sizeof(Sex) == 0x4);
}
