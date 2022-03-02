#include "PCH.h"

#include "Fixes/WeaponCharge.h"

#include "Addresses.h"
#include "Shared/Skyrim/E/EnchantmentItem.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void WeaponCharge::Fix(bool& weaponCharge)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::WeaponCharge::UpdateWeaponEnchantments, reinterpret_cast<std::uintptr_t>(std::addressof(WeaponCharge::UpdateWeaponEnchantments)));
	}

	void WeaponCharge::UpdateWeaponEnchantments(Skyrim::Actor* actor, Skyrim::TESBoundObject* item, Skyrim::ExtraDataList* extraDataList, bool leftHand)
	{
		if (!item)
		{
			return;
		}

		auto player = Skyrim::PlayerCharacter::GetSingleton();

		if (actor == player)
		{
			if (leftHand)
			{
				player->flagsBDB.reset(Skyrim::PlayerCharacter::FlagsBDB::kInsufficientChargeLeftHand);
			}
			else
			{
				player->flagsBDB.reset(Skyrim::PlayerCharacter::FlagsBDB::kInsufficientChargeRightHand);
			}
		}

		auto enchantment = item->GetEnchantment(extraDataList);

		if (!enchantment)
		{
			return;
		}

		if (enchantment->GetCastingType() == Skyrim::MagicSystem::CastingType::kConstantEffect)
		{
			return;
		}

		auto costActorValue = enchantment->GetCostActorValue(!leftHand);

		if (costActorValue != Skyrim::ActorValue::kNone)
		{
			actor->RemoveActorValueModifiers(costActorValue);

			auto maximumCharge = item->GetMaximumCharge(extraDataList);
			actor->SetActorValue(costActorValue, maximumCharge);

			if (extraDataList && extraDataList->HasType(Skyrim::ExtraDataType::kCharge))
			{
				auto charge = extraDataList->GetCharge();
				actor->RestoreActorValue(Skyrim::ActorValueModifier::kDamage, costActorValue, -(maximumCharge - charge));
			}
		}

		actor->RevertSelectedSpell(leftHand ? Skyrim::Actor::SlotType::kLeftHand : Skyrim::Actor::SlotType::kRightHand, enchantment);
	}
}
