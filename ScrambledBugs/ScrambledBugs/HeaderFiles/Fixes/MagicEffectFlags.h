#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/ActiveEffect.h"



namespace ScrambledBugs::Fixes
{
	class MagicEffectFlags
	{
	public:
		static void Fix(bool& magicEffectFlags);

	private:
		static void ResetElapsedTime(Skyrim::ActiveEffect* activeEffect);
		static void SetEffectiveness(Skyrim::ActiveEffect* activeEffect, float effectiveness, bool requiresHostility);
		static void SetEffectivenessImplementation(Skyrim::ActiveEffect* activeEffect, float effectiveness);
	};
}
