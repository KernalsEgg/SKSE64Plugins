#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	enum class BodyPartType : std::uint8_t
	{
		kNone    = static_cast<std::underlying_type_t<BodyPartType>>(-1),
		kTorso   = 0,
		kHead    = 1,
		kEye     = 2,
		kLookAt  = 3,
		kFlyGrab = 4,
		kSaddle  = 5,
		kTotal   = 6
	};
	static_assert(sizeof(BodyPartType) == 0x1);
}
