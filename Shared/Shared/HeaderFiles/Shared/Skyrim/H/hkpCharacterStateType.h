#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	enum class hkpCharacterStateType : std::uint32_t
	{
		kOnGround = 0,
		kJumping  = 1,
		kInAir    = 2,
		kClimbing = 3,
		kFlying   = 4,
		kSwimming = 5,

		kUserState0 = kSwimming,
		kUserState1 = 6,
		kUserState2 = 7,
		kUserState3 = 8,
		kUserState4 = 9,
		kUserState5 = 10,

		kTotal = 11
	};
	static_assert(sizeof(hkpCharacterStateType) == 0x4);
}
