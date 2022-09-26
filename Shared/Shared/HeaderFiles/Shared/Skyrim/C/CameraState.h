#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class CameraState
	{
		kFirstPerson      = 0,
		kAutomaticVanity  = 1,
		kVATS             = 2,
		kFree             = 3,
		kIronSights       = 4,
		kFurniture        = 5,
		kPlayerTransition = 6,
		kTween            = 7,
		kAnimated         = 8,
		kThirdPerson      = 9,
		kMount            = 10,
		kBleedout         = 11,
		kDragon           = 12,
		kTotal            = 13
	};
}
