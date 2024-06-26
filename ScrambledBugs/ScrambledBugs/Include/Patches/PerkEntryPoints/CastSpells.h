#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	class CastSpells
	{
	public:
		static void Patch(bool& castSpells);

	private:
		static void ApplySpellItem(Skyrim::Actor* target, Skyrim::SpellItem* spellItem, Skyrim::Actor* caster);
	};
}
