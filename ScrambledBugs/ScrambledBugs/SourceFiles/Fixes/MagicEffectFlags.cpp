#include "PrecompiledHeader.h"

#include "Fixes/MagicEffectFlags.h"

#include "Addresses.h"
#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/E/EffectItem.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void MagicEffectFlags::Fix(bool& magicEffectFlags)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::MagicEffectFlags::Adjust, reinterpret_cast<std::uintptr_t>(std::addressof(MagicEffectFlags::Adjust)));
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::MagicEffectFlags::Restart, reinterpret_cast<std::uintptr_t>(std::addressof(MagicEffectFlags::Restart)));
	}

	void MagicEffectFlags::Adjust(Skyrim::ActiveEffect* activeEffect, float effectiveness, bool requiresHostility)
	{
		// activeEffect != nullptr

		auto* magicItem = activeEffect->magicItem;

		if (!magicItem->ShouldAdjust())
		{
			return;
		}

		if (requiresHostility && !activeEffect->effect->IsHostile())
		{
			return;
		}

		if (effectiveness == 1.0F || effectiveness < 0.0F)
		{
			return;
		}

		auto effectSettingFlags = activeEffect->GetEffectSetting()->effectSettingFlags;

		if (effectSettingFlags.none(Skyrim::EffectSetting::Flags::kNoDuration) && effectSettingFlags.all(Skyrim::EffectSetting::Flags::kPowerAffectsDuration))
		{
			activeEffect->duration *= effectiveness;
		}

		if (effectSettingFlags.none(Skyrim::EffectSetting::Flags::kNoMagnitude) && effectSettingFlags.all(Skyrim::EffectSetting::Flags::kPowerAffectsMagnitude))
		{
			auto oldMagnitude = activeEffect->magnitude;
			auto newMagnitude = effectiveness * oldMagnitude;

			activeEffect->magnitude = oldMagnitude >= 0.0F ? std::max(newMagnitude, 1.0F) : std::min(newMagnitude, -1.0F);
		}
	}

	void MagicEffectFlags::Restart(Skyrim::ActiveEffect* activeEffect)
	{
		// activeEffect != nullptr

		activeEffect->elapsedTime = 0.0F;

		auto* effectSetting = activeEffect->GetEffectSetting();

		if (effectSetting && effectSetting->effectSettingFlags.none(Skyrim::EffectSetting::Flags::kRecover))
		{
			auto* caster = activeEffect->caster.get().get();

			if (caster)
			{
				auto dualCasted  = activeEffect->activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kDualCasted);
				auto dualCasting = caster->IsDualCasting();

				if (dualCasting)
				{
					activeEffect->activeEffectFlags.set(Skyrim::ActiveEffect::Flags::kDualCasted);
				}
				else
				{
					activeEffect->activeEffectFlags.reset(Skyrim::ActiveEffect::Flags::kDualCasted);
				}

				if (dualCasting != dualCasted)
				{
					auto* magicItem = activeEffect->magicItem;
					auto  cost      = magicItem->GetCost(caster);

					auto effectiveness = caster->GetDualCastingEffectiveness(cost);

					if (dualCasted)
					{
						effectiveness = 1.0F / effectiveness;
					}

					MagicEffectFlags::Adjust(activeEffect, effectiveness, false);
				}
			}
		}
	}
}
