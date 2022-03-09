#include "PCH.h"

#include "Fixes/LeftHandPowerAttacks.h"

#include "Addresses.h"
#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/B/BGSEntryPointPerkEntry.h"
#include "Shared/Skyrim/G/GameSettingCollection.h"
#include "Shared/Skyrim/T/TESObjectWEAP.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void LeftHandPowerAttacks::Fix(bool& leftHandPowerAttacks)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::LeftHandPowerAttacks::GetAttackStamina, reinterpret_cast<std::uintptr_t>(std::addressof(LeftHandPowerAttacks::GetAttackStamina)));
	}

	float LeftHandPowerAttacks::GetAttackStamina(Skyrim::ActorValueOwner* actorValueOwner, Skyrim::BGSAttackData* attackData)
	{
		// actorValueOwner != nullptr
		// attackData != nullptr

		auto attackDataFlags = attackData->attackDataFlags;
		auto powerAttack     = attackDataFlags.all(Skyrim::BGSAttackData::Flags::kPowerAttack);

		if (attackDataFlags.all(Skyrim::BGSAttackData::Flags::kBashAttack))
		{
			auto staminaBashBase = powerAttack ? Skyrim::GameSettingCollection::StaminaPowerBashBase()->value.floatingPoint : Skyrim::GameSettingCollection::StaminaBashBase()->value.floatingPoint;

			return staminaBashBase * attackData->staminaMultiplier;
		}
		else
		{
			if (!powerAttack)
			{
				return 0.0F;
			}

			auto actor                = static_cast<Skyrim::Actor*>(actorValueOwner);
			auto equippedWeapon       = actor->GetEquippedWeapon(attackDataFlags.all(Skyrim::BGSAttackData::Flags::kLeftAttack));
			auto equippedWeaponWeight = equippedWeapon ? equippedWeapon->weight : 1.0F;

			if (!equippedWeapon)
			{
				equippedWeapon = Skyrim::TESObjectWEAP::GetUnarmedWeapon();
			}

			auto staminaAttackWeaponBase       = Skyrim::GameSettingCollection::StaminaAttackWeaponBase()->value.floatingPoint;
			auto staminaAttackWeaponMultiplier = Skyrim::GameSettingCollection::StaminaAttackWeaponMultiplier()->value.floatingPoint;
			auto powerAttackStaminaPenalty     = Skyrim::GameSettingCollection::PowerAttackStaminaPenalty()->value.floatingPoint;

			auto powerAttackStamina = ((equippedWeaponWeight * staminaAttackWeaponMultiplier) + staminaAttackWeaponBase) * powerAttackStaminaPenalty;

			Skyrim::BGSEntryPointPerkEntry::HandleEntryPoint(Skyrim::BGSPerkEntry::EntryPoint::kModifyPowerAttackStamina, actor, equippedWeapon, std::addressof(powerAttackStamina));

			return powerAttackStamina * attackData->staminaMultiplier;
		}
	}
}
