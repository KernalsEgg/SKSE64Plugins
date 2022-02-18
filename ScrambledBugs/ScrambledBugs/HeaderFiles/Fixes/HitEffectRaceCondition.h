#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/ActiveEffect.h"



namespace ScrambledBugs::Fixes
{
	class HitEffectRaceCondition
	{
	public:
		static bool Fix();

	private:
		static bool ShouldUpdate(Skyrim::ActiveEffect* activeEffect);
	};
}
