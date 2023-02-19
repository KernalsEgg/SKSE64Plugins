#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class IsCurrentSpell
	{
	public:
		static void Fix(bool& isCurrentSpell);

	private:
		static bool IsCurrentSpellConditionFunction(Skyrim::TESObjectREFR* object, void* parameter1, void* parameter2, double& result);
		static bool IsCurrentSpellFunction(const Skyrim::ScriptParameter* scriptParameters, Skyrim::ScriptFunction::ScriptData* scriptData, Skyrim::TESObjectREFR* object, Skyrim::TESObjectREFR* containingObject, Skyrim::Script* script, Skyrim::ScriptLocals* scriptLocals, double& result, std::uint32_t& opcodeOffset);

		static decltype(IsCurrentSpell::IsCurrentSpellConditionFunction)* isCurrentSpellConditionFunction_;
		static decltype(IsCurrentSpell::IsCurrentSpellFunction)*          isCurrentSpellFunction_;
	};
}
