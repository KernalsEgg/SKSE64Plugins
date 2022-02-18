#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	enum class EffectArchetype : std::uint32_t
	{
		kNone                = static_cast<std::underlying_type_t<EffectArchetype>>(-1),
		kAccumulateMagnitude = 32
	};
	static_assert(sizeof(EffectArchetype) == 0x4);
}
