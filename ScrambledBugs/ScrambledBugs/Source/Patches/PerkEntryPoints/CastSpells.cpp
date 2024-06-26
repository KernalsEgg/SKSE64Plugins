#include "PrecompiledHeader.h"

#include "Patches/PerkEntryPoints/CastSpells.h"

#include "Addresses.h"
#include "Patterns.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	void CastSpells::Patch(bool& castSpells)
	{
		if (!Patterns::Patches::PerkEntryPoints::CastSpells::ApplyBashingSpell() ||
			!Patterns::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpell() ||
			!Patterns::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpellArrowProjectile() ||
			!Patterns::Patches::PerkEntryPoints::CastSpells::ApplyReanimateSpell() ||
			!Patterns::Patches::PerkEntryPoints::CastSpells::ApplyWeaponSwingSpell())
		{
			castSpells = false;

			return;
		}

		const auto* trampolineInterface = SKSE::Storage::GetSingleton().GetTrampolineInterface();

		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::CastSpells::ApplyBashingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(CastSpells::ApplySpellItem)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpell, reinterpret_cast<std::uintptr_t>(std::addressof(CastSpells::ApplySpellItem)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpellArrowProjectile, reinterpret_cast<std::uintptr_t>(std::addressof(CastSpells::ApplySpellItem)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::CastSpells::ApplyReanimateSpell, reinterpret_cast<std::uintptr_t>(std::addressof(CastSpells::ApplySpellItem)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::CastSpells::ApplyWeaponSwingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(CastSpells::ApplySpellItem)));
	}

	void CastSpells::ApplySpellItem(Skyrim::Actor* target, Skyrim::SpellItem* spellItem, Skyrim::Actor* caster)
	{
		// target != nullptr
		// spellItem != nullptr
		// caster != nullptr

		spellItem->Apply(target, caster);
	}
}
