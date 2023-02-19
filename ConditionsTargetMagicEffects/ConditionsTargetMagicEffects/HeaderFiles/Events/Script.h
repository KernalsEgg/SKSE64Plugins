#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class Script
	{
	public:
		static void Register();

	private:
		static bool EntryPointMagicSpellHasKeywordConditionFunction(Skyrim::TESObjectREFR* object, void* parameter1, void* parameter2, double& result);
		static bool EntryPointMagicSpellHasSkillConditionFunction(Skyrim::TESObjectREFR* object, void* parameter1, void* parameter2, double& result);
	};
}
