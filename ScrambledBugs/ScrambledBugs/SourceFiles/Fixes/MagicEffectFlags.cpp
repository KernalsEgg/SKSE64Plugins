#include "PCH.h"

#include "Fixes/MagicEffectFlags.h"

#include "Addresses.h"
#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/E/Effect.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void MagicEffectFlags::Fix(bool& magicEffectFlags)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::MagicEffectFlags::ResetElapsedTime, reinterpret_cast<std::uintptr_t>(std::addressof(MagicEffectFlags::ResetElapsedTime)));
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::MagicEffectFlags::SetEffectiveness, reinterpret_cast<std::uintptr_t>(std::addressof(MagicEffectFlags::SetEffectiveness)));
	}

	void MagicEffectFlags::ResetElapsedTime(Skyrim::ActiveEffect* activeEffect)
	{
		activeEffect->elapsedTime = 0.0F;

		auto baseEffect = activeEffect->GetBaseEffect();

		if (baseEffect && baseEffect->effectSettingFlags.none(Skyrim::EffectSetting::Flags::kRecover))
		{
			auto caster = activeEffect->caster.get().get();

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
					auto magicItem = activeEffect->magicItem;
					auto cost      = magicItem->GetCost(caster);

					auto effectiveness = caster->GetDualCastingEffectiveness(cost);

					if (dualCasted)
					{
						effectiveness = 1.0F / effectiveness;
					}

					if (magicItem->ShouldSetEffectiveness())
					{
						MagicEffectFlags::SetEffectivenessImplementation(activeEffect, effectiveness);
					}
				}
			}
		}
	}

	void MagicEffectFlags::SetEffectiveness(Skyrim::ActiveEffect* activeEffect, float effectiveness, bool requiresHostility)
	{
		auto magicItem = activeEffect->magicItem;

		if (magicItem->ShouldSetEffectiveness() && (requiresHostility || activeEffect->effect->IsHostile()))
		{
			MagicEffectFlags::SetEffectivenessImplementation(activeEffect, effectiveness);
		}
	}

	void MagicEffectFlags::SetEffectivenessImplementation(Skyrim::ActiveEffect* activeEffect, float effectiveness)
	{
		// activeEffect != nullptr

		if (effectiveness == 1.0F || effectiveness < 0.0F)
		{
			return;
		}

		auto effectSettingFlags = activeEffect->GetBaseEffect()->effectSettingFlags;

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
}
