#include "PCH.h"

#include "Patches/PerkEntryPoints/CastSpells.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	bool CastSpells::Patch()
	{
		if (!Patterns::Patches::PerkEntryPoints::CastSpells::ApplyBashingSpell() ||
			!Patterns::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpell() ||
			!Patterns::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpellArrowProjectile() ||
			!Patterns::Patches::PerkEntryPoints::CastSpells::ApplyReanimateSpell() ||
			!Patterns::Patches::PerkEntryPoints::CastSpells::ApplyWeaponSwingSpell())
		{
			return false;
		}

		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Patches::PerkEntryPoints::CastSpells::ApplyBashingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(CastSpells::ApplySpell)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpell, reinterpret_cast<std::uintptr_t>(std::addressof(CastSpells::ApplySpell)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpellArrowProjectile, reinterpret_cast<std::uintptr_t>(std::addressof(CastSpells::ApplySpell)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Patches::PerkEntryPoints::CastSpells::ApplyReanimateSpell, reinterpret_cast<std::uintptr_t>(std::addressof(CastSpells::ApplySpell)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Patches::PerkEntryPoints::CastSpells::ApplyWeaponSwingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(CastSpells::ApplySpell)));

		return true;
	}

	void CastSpells::ApplySpell(Skyrim::Actor* target, Skyrim::SpellItem* spell, Skyrim::Actor* caster)
	{
		// target != nullptr
		// spell != nullptr
		// caster != nullptr

		spell->Apply(target, caster);
	}
}
