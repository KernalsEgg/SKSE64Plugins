#include "PrecompiledHeader.h"

#include "Patches/PerkEntryPoints/ApplyMultipleSpells.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/B/BGSEntryPointFunctionDataSpellItem.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	void ApplyMultipleSpells::Patch(bool& applyMultipleSpells, bool& castSpells)
	{
		if (!Patterns::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyBashingSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyCombatHitSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyCombatHitSpellArrowProjectile() ||
			!Patterns::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyReanimateSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplySneakingSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyWeaponSwingSpell())
		{
			applyMultipleSpells = false;
			castSpells          = false;

			return;
		}

		ApplyMultipleSpells::castSpells_ = castSpells;

		*reinterpret_cast<decltype(&ApplyMultipleSpells::SelectSpell)*>(Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::SelectSpell) = std::addressof(ApplyMultipleSpells::SelectSpell);

		ApplyMultipleSpells::applyBashingSpell_ = reinterpret_cast<decltype(ApplyMultipleSpells::applyBashingSpell_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyBashingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplyMultipleSpells::ApplyBashingSpell))));

		ApplyMultipleSpells::applyCombatHitSpell_ = reinterpret_cast<decltype(ApplyMultipleSpells::applyCombatHitSpell_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyCombatHitSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplyMultipleSpells::ApplyCombatHitSpell))));

		ApplyMultipleSpells::applyCombatHitSpellArrowProjectile_ = reinterpret_cast<decltype(ApplyMultipleSpells::applyCombatHitSpellArrowProjectile_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyCombatHitSpellArrowProjectile, reinterpret_cast<std::uintptr_t>(std::addressof(ApplyMultipleSpells::ApplyCombatHitSpellArrowProjectile))));

		ApplyMultipleSpells::applyReanimateSpell_ = reinterpret_cast<decltype(ApplyMultipleSpells::applyReanimateSpell_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyReanimateSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplyMultipleSpells::ApplyReanimateSpell))));

		ApplyMultipleSpells::applySneakingSpell_ = reinterpret_cast<decltype(ApplyMultipleSpells::applySneakingSpell_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplySneakingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplyMultipleSpells::ApplySneakingSpell))));

		ApplyMultipleSpells::applyWeaponSwingSpell_ = reinterpret_cast<decltype(ApplyMultipleSpells::applyWeaponSwingSpell_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyWeaponSwingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplyMultipleSpells::ApplyWeaponSwingSpell))));
	}

	void ApplyMultipleSpells::ApplyBashingSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::Actor*                                                         target,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// target != nullptr
		// result != nullptr

		std::vector<Skyrim::SpellItem*> bashingSpells;

		ApplyMultipleSpells::applyBashingSpell_(entryPoint, perkOwner, target, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(bashingSpells)));

		for (auto* bashingSpell : bashingSpells)
		{
			bashingSpell->Apply(target, ApplyMultipleSpells::castSpells_ ? perkOwner : target);
		}
	}

	void ApplyMultipleSpells::ApplyCombatHitSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::TESObjectWEAP*                                                 weapon,
		Skyrim::Actor*                                                         target,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// weapon != nullptr
		// target != nullptr
		// result != nullptr

		std::vector<Skyrim::SpellItem*> combatHitSpells;

		ApplyMultipleSpells::applyCombatHitSpell_(entryPoint, perkOwner, weapon, target, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(combatHitSpells)));

		for (auto* combatHitSpell : combatHitSpells)
		{
			combatHitSpell->Apply(target, ApplyMultipleSpells::castSpells_ ? perkOwner : target);
		}
	}

	void ApplyMultipleSpells::ApplyCombatHitSpellArrowProjectile(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::TESObjectWEAP*                                                 weapon,
		Skyrim::Actor*                                                         target,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// weapon != nullptr
		// target != nullptr
		// result != nullptr

		std::vector<Skyrim::SpellItem*> combatHitSpells;

		ApplyMultipleSpells::applyCombatHitSpellArrowProjectile_(entryPoint, perkOwner, weapon, target, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(combatHitSpells)));

		for (auto* combatHitSpell : combatHitSpells)
		{
			combatHitSpell->Apply(target, ApplyMultipleSpells::castSpells_ ? perkOwner : target);
		}
	}

	void ApplyMultipleSpells::ApplyReanimateSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::SpellItem*                                                     spell,
		Skyrim::Actor*                                                         target,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// spell != nullptr
		// target != nullptr
		// result != nullptr

		std::vector<Skyrim::SpellItem*> reanimateSpells;

		ApplyMultipleSpells::applyReanimateSpell_(entryPoint, perkOwner, spell, target, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(reanimateSpells)));

		for (auto* reanimateSpell : reanimateSpells)
		{
			reanimateSpell->Apply(target, ApplyMultipleSpells::castSpells_ ? perkOwner : target);
		}
	}

	void ApplyMultipleSpells::ApplySneakingSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// result != nullptr

		std::vector<Skyrim::SpellItem*> sneakingSpells;

		ApplyMultipleSpells::applySneakingSpell_(entryPoint, perkOwner, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(sneakingSpells)));

		for (auto* sneakingSpell : sneakingSpells)
		{
			sneakingSpell->Apply(perkOwner, perkOwner);
		}
	}

	void ApplyMultipleSpells::ApplyWeaponSwingSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::Actor*                                                         attacker,
		Skyrim::TESObjectWEAP*                                                 attackerWeapon,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// attacker != nullptr
		// attackerWeapon != nullptr
		// result != nullptr

		std::vector<Skyrim::SpellItem*> weaponSwingSpells;

		ApplyMultipleSpells::applyWeaponSwingSpell_(entryPoint, perkOwner, attacker, attackerWeapon, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(weaponSwingSpells)));

		for (auto* weaponSwingSpell : weaponSwingSpells)
		{
			weaponSwingSpell->Apply(perkOwner, ApplyMultipleSpells::castSpells_ ? attacker : perkOwner);
		}
	}

	void ApplyMultipleSpells::SelectSpell(
		Skyrim::TESObjectREFR*                                                                     perkOwner,
		Utility::Enumeration<Skyrim::BGSEntryPointFunction::EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
		std::uint8_t                                                                               entryPointFunctionTypeArgumentCount,
		void**                                                                                     entryPointFunctionTypeArguments,
		Skyrim::BGSEntryPointFunctionData*                                                         entryPointFunctionData)
	{
		// perkOwner != nullptr
		// entryPointFunctionTypeArguments != nullptr
		// entryPointFunctionData != nullptr

		if (entryPointFunctionType != Skyrim::BGSEntryPointFunction::EntryPointFunctionType::kSpellItem)
		{
			return;
		}

		if (entryPointFunctionTypeArgumentCount != Skyrim::BGSEntryPointFunction::GetEntryPointFunctionTypeArgumentCount(Skyrim::BGSEntryPointFunction::EntryPointFunctionType::kSpellItem))
		{
			return;
		}

		if (entryPointFunctionData->GetType() != Skyrim::BGSEntryPointFunctionData::EntryPointFunctionDataType::kSpellItem)
		{
			return;
		}

		auto* spell = static_cast<Skyrim::BGSEntryPointFunctionDataSpellItem*>(entryPointFunctionData)->spell;

		if (!spell)
		{
			return;
		}

		auto* spells = static_cast<std::vector<Skyrim::SpellItem*>*>(*entryPointFunctionTypeArguments);

		if (!spells)
		{
			return;
		}

		spells->push_back(spell);
	}

	bool                                                               ApplyMultipleSpells::castSpells_{ false };
	decltype(&ApplyMultipleSpells::ApplyBashingSpell)                  ApplyMultipleSpells::applyBashingSpell_{ nullptr };
	decltype(&ApplyMultipleSpells::ApplyCombatHitSpell)                ApplyMultipleSpells::applyCombatHitSpell_{ nullptr };
	decltype(&ApplyMultipleSpells::ApplyCombatHitSpellArrowProjectile) ApplyMultipleSpells::applyCombatHitSpellArrowProjectile_{ nullptr };
	decltype(&ApplyMultipleSpells::ApplyReanimateSpell)                ApplyMultipleSpells::applyReanimateSpell_{ nullptr };
	decltype(&ApplyMultipleSpells::ApplySneakingSpell)                 ApplyMultipleSpells::applySneakingSpell_{ nullptr };
	decltype(&ApplyMultipleSpells::ApplyWeaponSwingSpell)              ApplyMultipleSpells::applyWeaponSwingSpell_{ nullptr };
}
