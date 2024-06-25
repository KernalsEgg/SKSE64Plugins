#include "PrecompiledHeader.h"

#include "Fixes/HitEffectRaceCondition.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void HitEffectRaceCondition::Fix(bool& hitEffectRaceCondition)
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Addresses::Fixes::HitEffectRaceCondition::ShouldUpdate,
			reinterpret_cast<std::uintptr_t>(std::addressof(HitEffectRaceCondition::ShouldUpdate)));
	}

	bool HitEffectRaceCondition::ShouldUpdate(Skyrim::ActiveEffect* activeEffect)
	{
		// activeEffect != nullptr

		auto activeEffectFlags = activeEffect->activeEffectFlags;

		if (activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kWornOff))
		{
			return false;
		}

		auto* magicItem = activeEffect->magicItem;

		if (!magicItem || !magicItem->IsPermanent())
		{
			return true;
		}

		if (activeEffect->GetEffectSetting()->effectSettingFlags.none(Skyrim::EffectSetting::Flags::kRecover))
		{
			return true;
		}

		if (activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kConditional))
		{
			return true;
		}

		if (activeEffectFlags.none(Skyrim::ActiveEffect::Flags::kAppliedHitEffects))
		{
			return true;
		}

		if (activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kApplyingHitEffects))
		{
			return true;
		}

		if (activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kApplyingSounds))
		{
			return true;
		}

		if (activeEffect->displacementSpell)
		{
			return true;
		}

		if (activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kDispelled))
		{
			return true;
		}

		return false;
	}
}
