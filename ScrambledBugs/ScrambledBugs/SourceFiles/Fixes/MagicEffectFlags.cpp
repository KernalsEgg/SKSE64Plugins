#include "PCH.h"

#include "Fixes/MagicEffectFlags.h"

#include "Addresses.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void MagicEffectFlags::Fix(bool& magicEffectFlags)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::MagicEffectFlags::SetEffectiveness, reinterpret_cast<std::uintptr_t>(std::addressof(MagicEffectFlags::SetEffectiveness)));
	}

	void MagicEffectFlags::SetEffectiveness(Skyrim::ActiveEffect* activeEffect, float effectiveness)
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
			auto newMagnitude = oldMagnitude * effectiveness;

			if (oldMagnitude >= 0.0F)
			{
				activeEffect->magnitude = newMagnitude >= 1.0F ? newMagnitude : 1.0F;
			}
			else
			{
				activeEffect->magnitude = newMagnitude <= -1.0F ? newMagnitude : -1.0F;
			}
		}
	}
}
