#include "PCH.h"

#include "Patches/ImproveMultipleEnchantmentEffects.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BGSEntryPointPerkEntry.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Skyrim/E/EnchantmentItem.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void ImproveMultipleEnchantmentEffects::Patch(bool& improveMultipleEnchantmentEffects)
	{
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor::VirtualFunctionTable, 0x1, reinterpret_cast<std::uintptr_t>(std::addressof(ImproveMultipleEnchantmentEffects::Traverse)));
	}

	Skyrim::MagicItemTraversalFunctor::ReturnType ImproveMultipleEnchantmentEffects::Traverse(Skyrim::CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor* createEffectFunctor, Skyrim::Effect* effect)
	{
		auto& createdEffect = createEffectFunctor->effects.emplace_back(*effect);

		auto magnitude = effect->GetMagnitude();
		auto duration  = effect->GetDuration();

		auto effectSettingFlags    = effect->baseEffect->effectSettingFlags;
		auto powerAffectsMagnitude = effectSettingFlags.all(Skyrim::EffectSetting::Flags::kPowerAffectsMagnitude);
		auto powerAffectsDuration  = effectSettingFlags.all(Skyrim::EffectSetting::Flags::kPowerAffectsDuration);

		auto power = 1.0F;

		auto* enchantmentEntry = createEffectFunctor->enchantmentEntry;

		if (enchantmentEntry)
		{
			auto maximumPower = 1.0F;

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
			Skyrim::BGSEntryPointPerkEntry::HandleEntryPoint(Skyrim::BGSPerkEntry::EntryPoint::kModifyEnchantmentPower, player, enchantmentEntry->enchantment, createEffectFunctor->item, std::addressof(maximumPower));
			maximumPower = std::floor(maximumPower);

			if (effect == createEffectFunctor->costliestEffect)
			{
				power = enchantmentEntry->power;

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

				if (enchantmentEntry->filterFlag.all(Skyrim::CraftingSubMenus::EnchantConstructMenu::EnchantmentEntry::FilterFlag::kEffectWeapon))
				{
					enchantmentEntry->power = power;
				}
				else if (enchantmentEntry->filterFlag.all(Skyrim::CraftingSubMenus::EnchantConstructMenu::EnchantmentEntry::FilterFlag::kEffectArmor))
				{
					power = maximumPower * createEffectFunctor->effectiveness;

					if (power < 1.0F)
					{
						power = 1.0F;
					}

					enchantmentEntry->power = power;
				}
			}
			else
			{
				power = maximumPower;

				if (enchantmentEntry->filterFlag.all(Skyrim::CraftingSubMenus::EnchantConstructMenu::EnchantmentEntry::FilterFlag::kEffectArmor))
				{
					power = maximumPower * createEffectFunctor->effectiveness;

					if (power < 1.0F)
					{
						power = 1.0F;
					}
				}
			}
		}

		if (powerAffectsMagnitude)
		{
			magnitude = power;
		}
		else if (powerAffectsDuration)
		{
			duration = static_cast<std::uint32_t>(std::round(power));
		}

		createdEffect.SetMagnitude(magnitude);
		createdEffect.SetDuration(duration);

		return Skyrim::MagicItemTraversalFunctor::ReturnType::kContinue;
	}
}
