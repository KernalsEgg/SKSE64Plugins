#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActiveEffect.h"

#include "Shared/Skyrim/E/EffectItem.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Skyrim/F/FindAppropriateDisplaceEffect.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/M/MagicTarget.h"
#include "Shared/Skyrim/S/SpellItem.h"



namespace Skyrim
{
	bool ActiveEffect::CheckDisplacement() const
	{
		auto* magicTarget = this->magicTarget;

		if (!magicTarget)
		{
			return false;
		}

		FindAppropriateDisplaceEffect findAppropriateDisplaceEffect;

		findAppropriateDisplaceEffect.displacementMagicItem = this->displacementMagicItem;
		findAppropriateDisplaceEffect.addiction             = static_cast<SpellItem*>(this->magicItem);
		findAppropriateDisplaceEffect.displace              = false;

		magicTarget->ForEachActiveEffect(findAppropriateDisplaceEffect);

		return findAppropriateDisplaceEffect.displace;
	}

	float ActiveEffect::GetCurrentMagnitude(float magnitude, float remainingTime, float taperDuration, float taperWeight, float taperCurve)
	{
		if (remainingTime < 0.0F)
		{
			remainingTime = 0.0F;
		}

		if (remainingTime < taperDuration)
		{
			if (std::abs(remainingTime) > 0.0001F || taperCurve >= 0.0F)
			{
				magnitude *= std::pow(remainingTime / taperDuration, taperCurve) * taperWeight;
			}
			else if (magnitude <= 0.0F)
			{
				magnitude = -std::numeric_limits<float>::max();
			}
			else
			{
				magnitude = std::numeric_limits<float>::max();
			}
		}

		return magnitude;
	}

	EffectSetting* ActiveEffect::GetEffectSetting()
	{
		return this->effectItem->effectSetting;
	}

	const EffectSetting* ActiveEffect::GetEffectSetting() const
	{
		return this->effectItem->effectSetting;
	}

	float ActiveEffect::GetCurrentMagnitude() const
	{
		if (this->activeEffectFlags.all(Flags::kRecover))
		{
			return this->magnitude;
		}

		const auto* effectSetting = this->GetEffectSetting();

		auto noDuration  = effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoDuration);
		auto noMagnitude = effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoMagnitude);

		auto taperDuration = noDuration || noMagnitude ? 0.0F : effectSetting->taperDuration;
		auto taperWeight   = noDuration || noMagnitude ? 0.0F : effectSetting->taperWeight;
		auto taperCurve    = noDuration || noMagnitude ? 0.0F : effectSetting->taperCurve;

		return ActiveEffect::GetCurrentMagnitude(this->magnitude, this->duration - this->elapsedTime, taperDuration, taperWeight, taperCurve);
	}
}
