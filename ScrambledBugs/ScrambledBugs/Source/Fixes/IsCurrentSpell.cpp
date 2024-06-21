#include "PrecompiledHeader.h"

#include "Fixes/IsCurrentSpell.h"

#include "Shared/Utility/Enumeration.h"



namespace ScrambledBugs::Fixes
{
	/* The IsCurrentSpell condition and console command treat the spell item as the casting source and the casting source as the spell item */
	void IsCurrentSpell::Fix(bool& isCurrentSpell)
	{
		auto* isCurrentSpellScriptFunction = Skyrim::ScriptCompiler::GetFunctionDefinition(Skyrim::ScriptOutput::kIsCurrentSpell);

		if (!isCurrentSpellScriptFunction)
		{
			isCurrentSpell = false;

			return;
		}

		IsCurrentSpell::isCurrentSpellConditionFunction_ = isCurrentSpellScriptFunction->conditionFunction;

		isCurrentSpellScriptFunction->conditionFunction = std::addressof(IsCurrentSpell::IsCurrentSpellConditionFunction);
		isCurrentSpellScriptFunction->executeFunction   = std::addressof(IsCurrentSpell::IsCurrentSpellFunction);
	}

	bool IsCurrentSpell::IsCurrentSpellConditionFunction(Skyrim::TESObjectREFR* object, void* parameter1, void* parameter2, double& result)
	{
		return IsCurrentSpell::isCurrentSpellConditionFunction_(object, parameter2, parameter1, result);
	}

	bool IsCurrentSpell::IsCurrentSpellFunction(const Skyrim::ScriptParameter* scriptParameters, Skyrim::ScriptFunction::ScriptData* scriptData, Skyrim::TESObjectREFR* object, Skyrim::TESObjectREFR* containingObject, Skyrim::Script* script, Skyrim::ScriptLocals* scriptLocals, double& result, std::uint32_t& opcodeOffset)
	{
		Skyrim::SpellItem*                                                      spellItem{ nullptr };
		Utility::Enumeration<Skyrim::MagicSystem::CastingSource, std::uint32_t> castingSource{ Skyrim::MagicSystem::CastingSource::kNone };

		return Skyrim::Script::ParseParameters(scriptParameters, scriptData, opcodeOffset, object, containingObject, script, scriptLocals, std::addressof(spellItem), std::addressof(castingSource)) ?
		           IsCurrentSpell::IsCurrentSpellConditionFunction(object, spellItem, reinterpret_cast<void*>(static_cast<std::uintptr_t>(castingSource.underlying())), result) :
		           false;
	}

	decltype(IsCurrentSpell::IsCurrentSpellConditionFunction)* IsCurrentSpell::isCurrentSpellConditionFunction_{ nullptr };
}
