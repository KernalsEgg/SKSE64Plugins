#include "PrecompiledHeader.h"

#include "Fixes/WeaponCharge.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void WeaponCharge::Fix(bool& weaponCharge)
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Addresses::Fixes::WeaponCharge::RefreshEquippedActorValueCharge,
			reinterpret_cast<std::uintptr_t>(std::addressof(WeaponCharge::RefreshEquippedActorValueCharge)));
	}

	void WeaponCharge::RefreshEquippedActorValueCharge(Skyrim::Actor* actor, Skyrim::TESBoundObject* boundObject, Skyrim::ExtraDataList* extraDataList, bool leftHand)
	{
		if (!boundObject)
		{
			return;
		}

		auto* playerCharacter = Skyrim::PlayerCharacter::GetSingleton();

		if (actor == playerCharacter)
		{
			playerCharacter->ResetInsufficientChargeMessage(leftHand);
		}

		auto* enchantmentItem = boundObject->GetEnchantmentItem(extraDataList);

		if (!enchantmentItem)
		{
			return;
		}

		if (enchantmentItem->GetCastingType() == Skyrim::MagicSystem::CastingType::kConstantEffect)
		{
			return;
		}

		auto castingSource  = leftHand ? Skyrim::MagicSystem::CastingSource::kLeftHand : Skyrim::MagicSystem::CastingSource::kRightHand;
		auto costActorValue = enchantmentItem->GetCostActorValue(castingSource);

		if (costActorValue != Skyrim::ActorValue::kNone)
		{
			actor->RemoveActorValueModifiers(costActorValue);

			auto maximumCharge = boundObject->GetMaximumCharge(extraDataList);
			actor->SetActorValue(costActorValue, maximumCharge);

			if (extraDataList && extraDataList->HasExtraData(Skyrim::ExtraDataType::kCharge))
			{
				auto charge = extraDataList->GetCharge();
				actor->RestoreActorValue(Skyrim::ActorValueModifier::kDamage, costActorValue, -(maximumCharge - charge));
			}
		}

		actor->SetSelectedMagicItem(castingSource, enchantmentItem);
	}
}
