#pragma once

#include "PCH.h"



namespace ScrambledBugs::Patches
{
	class PausedGameHitEffects
	{
	public:
		static void Patch(bool& pausedGameHitEffects);
	};
}
