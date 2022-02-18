#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/ActiveEffect.h"



namespace BugFixesSSE::Fixes
{
	class MagicEffectConditions
	{
	public:
		static bool Fix();

	private:
		static float ActiveEffectConditionUpdateInterval();
		static void  UpdateConditions(Skyrim::ActiveEffect* activeEffect, float frameTime, bool forceUpdate);
	};
}
