#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/B/BGSEntryPoint.h"
#include "Shared/Skyrim/B/BGSEntryPointFunction.h"
#include "Shared/Skyrim/B/BGSEntryPointFunctionData.h"
#include "Shared/Skyrim/S/SpellItem.h"
#include "Shared/Skyrim/T/TESObjectWEAP.h"
#include "Shared/Utility/Enumeration.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	class ApplyMultipleSpells
	{
	public:
		static void Patch(bool& applyMultipleSpells, bool& castSpells);

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
			Skyrim::SpellItem*                                                     spell,
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
			Skyrim::Actor*                                                                             perkOwner,
			Utility::Enumeration<Skyrim::BGSEntryPointFunction::EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
			std::uint8_t                                                                               entryPointFunctionTypeArgumentCount,
			void**                                                                                     entryPointFunctionTypeArguments,
			Skyrim::BGSEntryPointFunctionData*                                                         entryPointFunctionData);

		static bool                                                               castSpells_;
		static decltype(&ApplyMultipleSpells::ApplyBashingSpell)                  applyBashingSpell_;
		static decltype(&ApplyMultipleSpells::ApplyCombatHitSpell)                applyCombatHitSpell_;
		static decltype(&ApplyMultipleSpells::ApplyCombatHitSpellArrowProjectile) applyCombatHitSpellArrowProjectile_;
		static decltype(&ApplyMultipleSpells::ApplyReanimateSpell)                applyReanimateSpell_;
		static decltype(&ApplyMultipleSpells::ApplySneakingSpell)                 applySneakingSpell_;
		static decltype(&ApplyMultipleSpells::ApplyWeaponSwingSpell)              applyWeaponSwingSpell_;
	};
}
