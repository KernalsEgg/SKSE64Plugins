#include "PrecompiledHeader.h"

#include "Events/EnchantConstructMenu.h"

#include "Shared/Utility/Memory.h"



namespace ConditionsTargetMagicEffects::Events
{
	void CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor::Register()
	{
		Utility::Memory::SafeWriteVirtualFunction(
			Skyrim::Addresses::CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor::VirtualFunctionTable(),
			0x1,
			reinterpret_cast<std::uintptr_t>(std::addressof(CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor::FunctionCallOperator)));
	}

	Skyrim::ForEachResult CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor::FunctionCallOperator(Skyrim::CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor* createEffectFunctor, Skyrim::EffectItem* effect)
	{
		auto& createdEffect = createEffectFunctor->effects.emplace_back(*effect);

		if (effect != createEffectFunctor->costliestEffect)
		{
			return Skyrim::ForEachResult::kContinue;
		}

		auto magnitude = effect->GetMagnitude();
		auto duration  = effect->GetDuration();

		auto* effectSetting         = effect->effectSetting;
		auto  powerAffectsMagnitude = effectSetting->effectSettingFlags.all(Skyrim::EffectSetting::Flags::kPowerAffectsMagnitude);
		auto  powerAffectsDuration  = effectSetting->effectSettingFlags.all(Skyrim::EffectSetting::Flags::kPowerAffectsDuration);

		float power{ 1.0F };

		auto* enchantmentEntry = createEffectFunctor->enchantmentEntry;

		if (enchantmentEntry)
		{
			float maximumPower{ 1.0F };

			if (powerAffectsMagnitude)
			{
				maximumPower = magnitude;
			}
			else if (powerAffectsDuration)
			{
				maximumPower = static_cast<float>(duration);
			}

			auto* player          = Skyrim::PlayerCharacter::GetSingleton();
			auto  enchantingSkill = player->GetActorValue(Skyrim::ActorValue::kEnchanting);

			maximumPower = Skyrim::EnchantmentItem::ModifyPower(maximumPower, enchantingSkill);

			bool modifiedEnchantmentPower{ false };

			Skyrim::BGSEntryPoint::HandleEntryPoint(
				Skyrim::BGSEntryPoint::EntryPoint::kModifyEnchantmentPower,
				player,
				effectSetting,
				enchantmentEntry->enchantment,
				nullptr,
				createEffectFunctor->boundObject,
				std::addressof(maximumPower),
				std::addressof(modifiedEnchantmentPower));

			if (!modifiedEnchantmentPower)
			{
				Skyrim::BGSEntryPoint::HandleEntryPoint(
					Skyrim::BGSEntryPoint::EntryPoint::kModifyEnchantmentPower,
					player,
					enchantmentEntry->enchantment,
					createEffectFunctor->boundObject,
					std::addressof(maximumPower));
			}

			maximumPower = std::floor(maximumPower);
			power        = enchantmentEntry->power;

			if (power > maximumPower)
			{
				power = maximumPower;
			}
			else if (power < 1.0F)
			{
				power = 1.0F;
			}

			if (maximumPower != enchantmentEntry->maximumPower)
			{
				power = maximumPower;
			}

			enchantmentEntry->maximumPower = maximumPower;

			switch (enchantmentEntry->filterFlag.get())
			{
				case Skyrim::CraftingSubMenus::EnchantConstructMenu::CategoryListEntry::FilterFlag::kEffectArmor:
				{
					power = maximumPower * createEffectFunctor->effectiveness;

					if (power < 1.0F)
					{
						power = 1.0F;
					}

					[[fallthrough]];
				}
				case Skyrim::CraftingSubMenus::EnchantConstructMenu::CategoryListEntry::FilterFlag::kEffectWeapon:
				{
					enchantmentEntry->power = power;

					break;
				}
			}
		}

		if (powerAffectsMagnitude)
		{
			magnitude = power;
		}
		else if (powerAffectsDuration)
		{
			duration = static_cast<std::int32_t>(std::round(power));
		}

		createdEffect.SetMagnitude(magnitude);
		createdEffect.SetDuration(duration);

		return Skyrim::ForEachResult::kContinue;
	}
}
