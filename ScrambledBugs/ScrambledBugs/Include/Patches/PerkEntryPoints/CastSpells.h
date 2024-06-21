#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	class CastSpells
	{
	public:
		static void Patch(bool& castSpells);

	private:
		static void ApplySpell(Skyrim::Actor* target, Skyrim::SpellItem* spell, Skyrim::Actor* caster);
	};
}
