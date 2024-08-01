#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	namespace BGSBodyPartDefinitions
	{
		enum class Limb : std::uint8_t
		{
			kNone    = static_cast<std::underlying_type_t<Limb>>(-1),
			kTorso   = 0,
			kHead    = 1,
			kEye     = 2,
			kLookAt  = 3,
			kFlyGrab = 4,
			kSaddle  = 5,
			kTotal   = 6
		};
		static_assert(sizeof(Limb) == 0x1);
	}
}
