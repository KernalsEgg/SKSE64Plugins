#pragma once

#include "PrecompiledHeader.h"



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
