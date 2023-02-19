#include "PrecompiledHeader.h"

#include "Fixes/LeftHandPowerAttacks.h"

#include "Addresses.h"
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
			auto staminaBashBase = powerAttack ? Skyrim::GameSettingCollection::StaminaPowerBashBase()->GetFloat() : Skyrim::GameSettingCollection::StaminaBashBase()->GetFloat();

			return staminaBashBase * attackData->staminaMultiplier;
		}
		else
		{
			if (!powerAttack)
			{
				return 0.0F;
			}

			auto* actor                = static_cast<Skyrim::Actor*>(actorValueOwner);
			auto* equippedWeapon       = actor->GetEquippedWeapon(attackDataFlags.all(Skyrim::BGSAttackData::Flags::kLeftAttack));
			auto  equippedWeaponWeight = equippedWeapon ? equippedWeapon->weight : 1.0F;

			if (!equippedWeapon)
			{
				equippedWeapon = Skyrim::TESObjectWEAP::GetUnarmedWeapon();
			}

			auto staminaAttackWeaponBase       = Skyrim::GameSettingCollection::StaminaAttackWeaponBase()->GetFloat();
			auto staminaAttackWeaponMultiplier = Skyrim::GameSettingCollection::StaminaAttackWeaponMultiplier()->GetFloat();
			auto powerAttackStaminaPenalty     = Skyrim::GameSettingCollection::PowerAttackStaminaPenalty()->GetFloat();

			auto powerAttackStamina = ((equippedWeaponWeight * staminaAttackWeaponMultiplier) + staminaAttackWeaponBase) * powerAttackStaminaPenalty;

			Skyrim::BGSEntryPoint::HandleEntryPoint(Skyrim::BGSEntryPoint::EntryPoint::kModifyPowerAttackStamina, actor, equippedWeapon, std::addressof(powerAttackStamina));

			return powerAttackStamina * attackData->staminaMultiplier;
		}
	}
}
