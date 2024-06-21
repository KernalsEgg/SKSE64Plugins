#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class PausedGameHitEffects
	{
	public:
		static void Patch(bool& pausedGameHitEffects);

	private:
		static bool AllowHitEffects(Skyrim::ActiveEffect* activeEffect);
	};
}
