#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActiveEffect.h"

#include "Shared/Skyrim/E/Effect.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Skyrim/F/FindAppropriateDisplaceEffect.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/M/MagicTarget.h"
#include "Shared/Skyrim/S/SpellItem.h"



namespace Skyrim
{
	float ActiveEffect::GetCurrentMagnitude(float magnitude, float remainingTime, float taperDuration, float taperWeight, float taperCurve)
	{
		if (remainingTime < 0.0F)
		{
			remainingTime = 0.0F;
		}

		if (remainingTime < taperDuration)
		{
			if (std::abs(remainingTime) > 0.0001 || taperCurve >= 0.0F)
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

	EffectSetting* ActiveEffect::GetBaseEffect()
	{
		return this->effect->baseEffect;
	}

	const EffectSetting* ActiveEffect::GetBaseEffect() const
	{
		return this->effect->baseEffect;
	}

	float ActiveEffect::GetCurrentMagnitude() const
	{
		if (this->activeEffectFlags.all(Flags::kRecover))
		{
			return this->magnitude;
		}

		const auto* baseEffect = this->GetBaseEffect();

		auto noDuration  = baseEffect->effectSettingFlags.all(EffectSetting::Flags::kNoDuration);
		auto noMagnitude = baseEffect->effectSettingFlags.all(EffectSetting::Flags::kNoMagnitude);

		auto taperDuration = noDuration || noMagnitude ? 0.0F : baseEffect->taperDuration;
		auto taperWeight   = noDuration || noMagnitude ? 0.0F : baseEffect->taperWeight;
		auto taperCurve    = noDuration || noMagnitude ? 0.0F : baseEffect->taperCurve;

		return ActiveEffect::GetCurrentMagnitude(this->magnitude, this->duration - this->elapsedTime, taperDuration, taperWeight, taperCurve);
	}

	bool ActiveEffect::ShouldDisplace() const
	{
		auto* magicTarget = this->magicTarget;

		if (!magicTarget)
		{
			return false;
		}

		FindAppropriateDisplaceEffect findAppropriateDisplaceEffect;
		findAppropriateDisplaceEffect.displacementSpell = this->displacementSpell;
		findAppropriateDisplaceEffect.addiction         = static_cast<SpellItem*>(this->magicItem);
		findAppropriateDisplaceEffect.displace          = false;

		magicTarget->VisitActiveEffects(std::addressof(findAppropriateDisplaceEffect));

		return findAppropriateDisplaceEffect.displace;
	}
}
