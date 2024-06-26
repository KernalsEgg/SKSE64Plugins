#include "PrecompiledHeader.h"

#include "Patches/PerkEntryPoints/ApplySpells.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	void ApplySpells::Patch(bool& applySpells, bool& castSpells)
	{
		if (!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplyBashingSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpellArrowProjectile() ||
			!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplyReanimateSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplySneakingSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplyWeaponSwingSpell())
		{
			applySpells = false;
			castSpells  = false;

			return;
		}

		ApplySpells::castSpells_ = castSpells;

		*reinterpret_cast<decltype(ApplySpells::SelectSpell)**>(Addresses::Patches::PerkEntryPoints::ApplySpells::SelectSpell) = std::addressof(ApplySpells::SelectSpell);

		ApplySpells::applyBashingSpell_                  = reinterpret_cast<decltype(ApplySpells::applyBashingSpell_)>(Utility::Memory::ReadRelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyBashingSpell));
		ApplySpells::applyCombatHitSpell_                = reinterpret_cast<decltype(ApplySpells::applyCombatHitSpell_)>(Utility::Memory::ReadRelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpell));
		ApplySpells::applyCombatHitSpellArrowProjectile_ = reinterpret_cast<decltype(ApplySpells::applyCombatHitSpellArrowProjectile_)>(Utility::Memory::ReadRelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpellArrowProjectile));
		ApplySpells::applyReanimateSpell_                = reinterpret_cast<decltype(ApplySpells::applyReanimateSpell_)>(Utility::Memory::ReadRelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyReanimateSpell));
		ApplySpells::applySneakingSpell_                 = reinterpret_cast<decltype(ApplySpells::applySneakingSpell_)>(Utility::Memory::ReadRelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplySneakingSpell));
		ApplySpells::applyWeaponSwingSpell_              = reinterpret_cast<decltype(ApplySpells::applyWeaponSwingSpell_)>(Utility::Memory::ReadRelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyWeaponSwingSpell));

		const auto* trampolineInterface = SKSE::Storage::GetSingleton().GetTrampolineInterface();

		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyBashingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyBashingSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyCombatHitSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpellArrowProjectile, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyCombatHitSpellArrowProjectile)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyReanimateSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyReanimateSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplySneakingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplySneakingSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyWeaponSwingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyWeaponSwingSpell)));
	}

	void ApplySpells::ApplyBashingSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::Actor*                                                         target,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// target != nullptr
		// result != nullptr

		std::vector<Skyrim::SpellItem*> bashingSpellItems;

		ApplySpells::applyBashingSpell_(entryPoint, perkOwner, target, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(bashingSpellItems)));

		for (auto* bashingSpellItem : bashingSpellItems)
		{
			bashingSpellItem->Apply(target, ApplySpells::castSpells_ ? perkOwner : target);
		}
	}

	void ApplySpells::ApplyCombatHitSpell(
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

		std::vector<Skyrim::SpellItem*> combatHitSpellItems;

		ApplySpells::applyCombatHitSpell_(entryPoint, perkOwner, weapon, target, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(combatHitSpellItems)));

		for (auto* combatHitSpellItem : combatHitSpellItems)
		{
			combatHitSpellItem->Apply(target, ApplySpells::castSpells_ ? perkOwner : target);
		}
	}

	void ApplySpells::ApplyCombatHitSpellArrowProjectile(
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

		std::vector<Skyrim::SpellItem*> combatHitSpellItems;

		ApplySpells::applyCombatHitSpellArrowProjectile_(entryPoint, perkOwner, weapon, target, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(combatHitSpellItems)));

		for (auto* combatHitSpellItem : combatHitSpellItems)
		{
			combatHitSpellItem->Apply(target, ApplySpells::castSpells_ ? perkOwner : target);
		}
	}

	void ApplySpells::ApplyReanimateSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::SpellItem*                                                     spellItem,
		Skyrim::Actor*                                                         target,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// spellItem != nullptr
		// target != nullptr
		// result != nullptr

		std::vector<Skyrim::SpellItem*> reanimateSpellItems;

		ApplySpells::applyReanimateSpell_(entryPoint, perkOwner, spellItem, target, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(reanimateSpellItems)));

		for (auto* reanimateSpellItem : reanimateSpellItems)
		{
			reanimateSpellItem->Apply(target, ApplySpells::castSpells_ ? perkOwner : target);
		}
	}

	void ApplySpells::ApplySneakingSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// result != nullptr

		std::vector<Skyrim::SpellItem*> sneakingSpellItems;

		ApplySpells::applySneakingSpell_(entryPoint, perkOwner, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(sneakingSpellItems)));

		for (auto* sneakingSpellItem : sneakingSpellItems)
		{
			sneakingSpellItem->Apply(perkOwner, perkOwner);
		}
	}

	void ApplySpells::ApplyWeaponSwingSpell(
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

		std::vector<Skyrim::SpellItem*> weaponSwingSpellItems;

		ApplySpells::applyWeaponSwingSpell_(entryPoint, perkOwner, attacker, attackerWeapon, reinterpret_cast<Skyrim::SpellItem**>(std::addressof(weaponSwingSpellItems)));

		for (auto* weaponSwingSpellItem : weaponSwingSpellItems)
		{
			weaponSwingSpellItem->Apply(perkOwner, ApplySpells::castSpells_ ? attacker : perkOwner);
		}
	}

	void ApplySpells::SelectSpell(
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

		auto* spellItem = static_cast<Skyrim::BGSEntryPointFunctionDataSpellItem*>(entryPointFunctionData)->spellItem;

		if (!spellItem)
		{
			return;
		}

		auto* spellItems = static_cast<std::vector<Skyrim::SpellItem*>*>(*entryPointFunctionTypeArguments);

		if (!spellItems)
		{
			return;
		}

		spellItems->push_back(spellItem);
	}

	bool                                                       ApplySpells::castSpells_{};
	decltype(ApplySpells::ApplyBashingSpell)*                  ApplySpells::applyBashingSpell_{ nullptr };
	decltype(ApplySpells::ApplyCombatHitSpell)*                ApplySpells::applyCombatHitSpell_{ nullptr };
	decltype(ApplySpells::ApplyCombatHitSpellArrowProjectile)* ApplySpells::applyCombatHitSpellArrowProjectile_{ nullptr };
	decltype(ApplySpells::ApplyReanimateSpell)*                ApplySpells::applyReanimateSpell_{ nullptr };
	decltype(ApplySpells::ApplySneakingSpell)*                 ApplySpells::applySneakingSpell_{ nullptr };
	decltype(ApplySpells::ApplyWeaponSwingSpell)*              ApplySpells::applyWeaponSwingSpell_{ nullptr };
}
