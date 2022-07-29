#include "Shared/PCH.h"

#include "Shared/Skyrim/F/FindMaxMagnitudeVisitor.h"

#include "Shared/Skyrim/A/AccumulatingValueModifierEffect.h"
#include "Shared/Skyrim/A/ActiveEffect.h"
#include "Shared/Skyrim/E/EffectSetting.h"



namespace Skyrim
{
	MagicTarget::ForEachActiveEffectVisitor::ReturnType FindMaxMagnitudeVisitor::Visit(ActiveEffect* activeEffect)
	{
		if (!activeEffect)
		{
			return MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
		}

		if (activeEffect == this->finishedActiveEffect)
		{
			return MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
		}

		if (activeEffect->GetBaseEffect()->effectArchetype != EffectArchetype::kAccumulateMagnitude)
		{
			return MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
		}

		auto* accumulatingValueModifierEffect = static_cast<AccumulatingValueModifierEffect*>(activeEffect);

		if (accumulatingValueModifierEffect->actorValue != ActorValue::kWardPower)
		{
			return MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
		}

		auto maximumMagnitude = accumulatingValueModifierEffect->maximumMagnitude;

		if (maximumMagnitude > this->maximumMagnitude)
		{
			this->maximumMagnitude = maximumMagnitude;
		}

		return MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
	}
}
