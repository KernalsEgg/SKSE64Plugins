#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class Script
	{
	public:
		static void Register();

	private:
		static Skyrim::ScriptFunction::ConditionFunction EntryPointMagicSpellHasKeywordConditionFunction;
		static Skyrim::ScriptFunction::ConditionFunction EntryPointMagicSpellHasSkillConditionFunction;
	};
}
