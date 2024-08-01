#include "PrecompiledHeader.h"

#include "Patches/PerkEntryPoints/ApplySpells.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Conversion.h"
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

		const auto* trampolineInterface = SKSE::Storage::GetSingleton().GetTrampolineInterface();

		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyBashingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyBashingSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyCombatHitSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpellArrowProjectile, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyCombatHitSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyReanimateSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyReanimateSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplySneakingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplySneakingSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyWeaponSwingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyWeaponSwingSpell)));

		*reinterpret_cast<decltype(ApplySpells::SelectSpell)**>(Addresses::Patches::PerkEntryPoints::ApplySpells::SelectSpell) = std::addressof(ApplySpells::SelectSpell);
	}

	/* Apply Bashing Spell
	* Perk Owner
	* Target */
	void ApplySpells::ApplyBashingSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::Actor*                                                         target,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// target != nullptr
		// result != nullptr

		auto bashingSpellItems = ApplySpells::HandleEntryPoint(entryPoint, perkOwner, std::vector<Skyrim::TESForm*>{ perkOwner, target });

		for (auto* bashingSpellItem : bashingSpellItems)
		{
			if (bashingSpellItem)
			{
				static_cast<Skyrim::SpellItem*>(bashingSpellItem)->Apply(target, ApplySpells::castSpells_ ? perkOwner : target);
			}
		}
	}

	/* Apply Combat Hit Spell
	* Perk Owner
	* Weapon
	* Target */
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

		auto combatHitSpellItems = ApplySpells::HandleEntryPoint(entryPoint, perkOwner, std::vector<Skyrim::TESForm*>{ perkOwner, weapon, target });

		for (auto* combatHitSpellItem : combatHitSpellItems)
		{
			if (combatHitSpellItem)
			{
				static_cast<Skyrim::SpellItem*>(combatHitSpellItem)->Apply(target, ApplySpells::castSpells_ ? perkOwner : target);
			}
		}
	}

	/* Apply Reanimate Spell
	* Perk Owner
	* Spell
	* Target */
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

		auto reanimateSpellItems = ApplySpells::HandleEntryPoint(entryPoint, perkOwner, std::vector<Skyrim::TESForm*>{ perkOwner, spellItem, target });

		for (auto* reanimateSpellItem : reanimateSpellItems)
		{
			if (reanimateSpellItem)
			{
				static_cast<Skyrim::SpellItem*>(reanimateSpellItem)->Apply(target, ApplySpells::castSpells_ ? perkOwner : target);
			}
		}
	}

	/* Apply Sneaking Spell
	* Perk Owner */
	void ApplySpells::ApplySneakingSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::SpellItem**                                                    result)
	{
		// perkOwner != nullptr
		// result != nullptr

		auto sneakingSpellItems = ApplySpells::HandleEntryPoint(entryPoint, perkOwner, std::vector<Skyrim::TESForm*>{ perkOwner });

		for (auto* sneakingSpellItem : sneakingSpellItems)
		{
			if (sneakingSpellItem)
			{
				static_cast<Skyrim::SpellItem*>(sneakingSpellItem)->Apply(perkOwner, perkOwner);
			}
		}
	}

	/* Apply Weapon Swing Spell
	* Perk Owner
	* Attacker
	* Attacker Weapon */
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

		auto weaponSwingSpellItems = ApplySpells::HandleEntryPoint(entryPoint, perkOwner, std::vector<Skyrim::TESForm*>{ perkOwner, attacker, attackerWeapon });

		for (auto* weaponSwingSpellItem : weaponSwingSpellItems)
		{
			if (weaponSwingSpellItem)
			{
				static_cast<Skyrim::SpellItem*>(weaponSwingSpellItem)->Apply(perkOwner, ApplySpells::castSpells_ ? attacker : perkOwner);
			}
		}
	}

	std::vector<void*> ApplySpells::HandleEntryPoint(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		std::vector<Skyrim::TESForm*>                                          conditionFilterArguments)
	{
		if (entryPoint.underlying() < Utility::Conversion::ToUnderlying(Skyrim::BGSEntryPoint::EntryPoint::kTotal))
		{
			if (perkOwner && perkOwner->HasPerkEntries(entryPoint.get()))
			{
				auto conditionFilterArgumentCount = Skyrim::BGSEntryPoint::GetEntryPoint(entryPoint)->conditionFilterArgumentCount;

				if (conditionFilterArguments.size() == conditionFilterArgumentCount)
				{
					auto entryPointFunctionType          = Skyrim::BGSEntryPoint::GetEntryPoint(entryPoint)->entryPointFunctionType;
					auto entryPointFunctionArgumentCount = Skyrim::BGSEntryPointFunction::GetEntryPointFunctionArgumentCount(entryPointFunctionType.get());

					/* If the last spell item is a null pointer then all spell items have been found
					* Increment the size of the vector in each iteration */
					std::vector<void*> entryPointFunctionArguments{};

					do
					{
						entryPointFunctionArguments = { entryPointFunctionArgumentCount++, nullptr };

						Skyrim::HandleEntryPointVisitor handleEntryPointVisitor(
							entryPointFunctionType.get(),
							conditionFilterArguments.empty() ? nullptr : conditionFilterArguments.data(),
							entryPointFunctionArguments.empty() ? nullptr : entryPointFunctionArguments.data(),
							perkOwner,
							static_cast<std::uint8_t>(conditionFilterArguments.size()),
							static_cast<std::uint8_t>(entryPointFunctionArguments.size()));

						perkOwner->ForEachPerkEntry(entryPoint.get(), handleEntryPointVisitor);
					} while (std::find(entryPointFunctionArguments.begin(), entryPointFunctionArguments.end(), nullptr) == entryPointFunctionArguments.end());

					std::erase(entryPointFunctionArguments, nullptr);

					return entryPointFunctionArguments;
				}
			}
		}

		return {};
	}

	void ApplySpells::SelectSpell(
		Skyrim::TESObjectREFR*                                                                     perkOwner,
		Utility::Enumeration<Skyrim::BGSEntryPointFunction::EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
		std::uint8_t                                                                               entryPointFunctionArgumentCount,
		void**                                                                                     entryPointFunctionArguments,
		Skyrim::BGSEntryPointFunctionData*                                                         entryPointFunctionData)
	{
		// perkOwner != nullptr
		// entryPointFunctionArguments != nullptr
		// entryPointFunctionData != nullptr

		if (entryPointFunctionType != Skyrim::BGSEntryPointFunction::EntryPointFunctionType::kSpellItem)
		{
			return;
		}

		if (!entryPointFunctionArguments)
		{
			return;
		}

		if (entryPointFunctionData->GetEntryPointFunctionDataType() != Skyrim::BGSEntryPointFunctionData::EntryPointFunctionData::kSpellItem)
		{
			return;
		}

		auto* spellItem = static_cast<Skyrim::BGSEntryPointFunctionDataSpellItem*>(entryPointFunctionData)->spellItem;

		if (!spellItem)
		{
			return;
		}

		std::span<void*> entryPointFunctionArgumentSpan(entryPointFunctionArguments, entryPointFunctionArgumentCount);

		auto entryPointFunctionArgumentIterator = std::find(entryPointFunctionArgumentSpan.begin(), entryPointFunctionArgumentSpan.end(), nullptr);

		if (entryPointFunctionArgumentIterator != entryPointFunctionArgumentSpan.end())
		{
			*entryPointFunctionArgumentIterator = spellItem;
		}
	}

	bool ApplySpells::castSpells_{};
}
