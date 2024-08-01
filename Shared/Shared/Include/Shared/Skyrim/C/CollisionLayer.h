#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class CollisionLayer : std::uint32_t
	{
		kWater = 11
	};
	static_assert(sizeof(CollisionLayer) == 0x4);
}
