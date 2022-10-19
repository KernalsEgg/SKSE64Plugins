#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActiveEffect.h"



namespace ScrambledBugs::Fixes
{
	class MagicEffectFlags
	{
	public:
		static void Fix(bool& magicEffectFlags);

	private:
		static void Adjust(Skyrim::ActiveEffect* activeEffect, float effectiveness, bool requiresHostility);
		static void Restart(Skyrim::ActiveEffect* activeEffect);
	};
}
