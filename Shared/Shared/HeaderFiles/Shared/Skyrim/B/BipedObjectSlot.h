#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class BipedObjectSlot : std::uint32_t
	{
		kNone             = static_cast<std::underlying_type_t<BipedObjectSlot>>(-1),
		kHead             = 0,
		kHair             = 1,
		kBody             = 2,
		kHands            = 3,
		kForearms         = 4,
		kAmulet           = 5,
		kRing             = 6,
		kFeet             = 7,
		kCalves           = 8,
		kShield           = 9,
		kLongHair         = 11,
		kCirclet          = 12,
		kEars             = 13,
		kFX01             = 31,
		kCreationKitTotal = 32,
		kHandToHandMelee  = kCreationKitTotal,
		kOneHandSword     = 33,
		kOneHandDagger    = 34,
		kOneHandAxe       = 35,
		kOneHandMace      = 36,
		kTwoHand          = 37,
		kBow              = 38,
		kStaff            = 39,
		kCrossbow         = 40,
		kQuiver           = 41,
		kTotal            = 42
	};
	static_assert(sizeof(BipedObjectSlot) == 0x4);
}
