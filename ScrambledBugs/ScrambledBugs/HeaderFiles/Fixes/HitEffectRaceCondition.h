#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/ActiveEffect.h"



namespace ScrambledBugs::Fixes
{
	class HitEffectRaceCondition
	{
	public:
		static void Fix(bool& hitEffectRaceCondition);

	private:
		static bool ShouldUpdate(Skyrim::ActiveEffect* activeEffect);
	};
}
