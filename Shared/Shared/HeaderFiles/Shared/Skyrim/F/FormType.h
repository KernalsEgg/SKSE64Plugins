#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	enum class FormType
	{
		kNone                = 0,
		kEnchantment         = 0x15,
		kScroll              = 0x17,
		kArmor               = 0x1A,
		kContainer           = 0x1C,
		kLight               = 0x1F,
		kStatic              = 0x22,
		kTree                = 0x26,
		kFlora               = 0x27,
		kFurniture           = 0x28,
		kWeapon              = 0x29,
		kNPC                 = 0x2B,
		kConstructibleObject = 0x31,
		kProjectile          = 0x32,
		kSoulGem             = 0x34,
		kCell                = 0x3C,
		kActor               = 0x3E,
		kImpactDataSet       = 0x65,
		kTotal               = 0x8A
	};
}
