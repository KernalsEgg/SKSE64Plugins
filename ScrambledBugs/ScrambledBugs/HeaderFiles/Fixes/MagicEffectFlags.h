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
		static void SetEffectiveness(Skyrim::ActiveEffect* activeEffect, float effectiveness);
	};
}
