#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/ActiveEffect.h"



namespace BugFixesSSE::Fixes
{
	class MagicEffectConditions
	{
	public:
		static void Fix(bool& magicEffectConditions);

	private:
		static float ActiveEffectConditionUpdateInterval();
		static void  UpdateConditions(Skyrim::ActiveEffect* activeEffect, float deltaTime, bool forceUpdate);
	};
}
