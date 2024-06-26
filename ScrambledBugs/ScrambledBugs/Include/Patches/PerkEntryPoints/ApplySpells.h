#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Utility/Enumeration.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	class ApplySpells
	{
	public:
		static void Patch(bool& applySpells, bool& castSpells);

	private:
		static void ApplyBashingSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			Skyrim::Actor*                                                         target,
			Skyrim::SpellItem**                                                    result);
		static void ApplyCombatHitSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			Skyrim::TESObjectWEAP*                                                 weapon,
			Skyrim::Actor*                                                         target,
			Skyrim::SpellItem**                                                    result);
		static void ApplyCombatHitSpellArrowProjectile(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			Skyrim::TESObjectWEAP*                                                 weapon,
			Skyrim::Actor*                                                         target,
			Skyrim::SpellItem**                                                    result);
		static void ApplyReanimateSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			Skyrim::SpellItem*                                                     spellItem,
			Skyrim::Actor*                                                         target,
			Skyrim::SpellItem**                                                    result);
		static void ApplySneakingSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			Skyrim::SpellItem**                                                    result);
		static void ApplyWeaponSwingSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			Skyrim::Actor*                                                         attacker,
			Skyrim::TESObjectWEAP*                                                 attackerWeapon,
			Skyrim::SpellItem**                                                    result);
		static void SelectSpell(
			Skyrim::TESObjectREFR*                                                                     perkOwner,
			Utility::Enumeration<Skyrim::BGSEntryPointFunction::EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
			std::uint8_t                                                                               entryPointFunctionTypeArgumentCount,
			void**                                                                                     entryPointFunctionTypeArguments,
			Skyrim::BGSEntryPointFunctionData*                                                         entryPointFunctionData);

		static bool                                                       castSpells_;
		static decltype(ApplySpells::ApplyBashingSpell)*                  applyBashingSpell_;
		static decltype(ApplySpells::ApplyCombatHitSpell)*                applyCombatHitSpell_;
		static decltype(ApplySpells::ApplyCombatHitSpellArrowProjectile)* applyCombatHitSpellArrowProjectile_;
		static decltype(ApplySpells::ApplyReanimateSpell)*                applyReanimateSpell_;
		static decltype(ApplySpells::ApplySneakingSpell)*                 applySneakingSpell_;
		static decltype(ApplySpells::ApplyWeaponSwingSpell)*              applyWeaponSwingSpell_;
	};
}
