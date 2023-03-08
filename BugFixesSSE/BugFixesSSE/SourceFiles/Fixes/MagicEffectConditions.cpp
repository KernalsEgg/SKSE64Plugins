#include "PrecompiledHeader.h"

#include "Fixes/MagicEffectConditions.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace BugFixesSSE::Fixes
{
	void MagicEffectConditions::Fix(bool& magicEffectConditions)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::MagicEffectConditions::EvaluateConditions, reinterpret_cast<std::uintptr_t>(std::addressof(MagicEffectConditions::EvaluateConditions)));
	}

	float MagicEffectConditions::ActiveEffectConditionUpdateInterval()
	{
		static auto* activeEffectConditionUpdateInterval = Skyrim::GameSettingCollection::InitializeSetting("fActiveEffectConditionUpdateInterval");

		return activeEffectConditionUpdateInterval->GetFloat() > 0.0001F ? activeEffectConditionUpdateInterval->GetFloat() : 1.0F;
	}

	void MagicEffectConditions::EvaluateConditions(Skyrim::ActiveEffect* activeEffect, float elapsedTimeDelta, bool forceUpdate)
	{
		// activeEffect != nullptr

		if (activeEffect->conditionStatus == Skyrim::ActiveEffect::ConditionStatus::kNotAvailable)
		{
			return;
		}

		if ((activeEffect->activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kHasConditions) || activeEffect->displacementSpell) && activeEffect->magicTarget && activeEffect->magicTarget->GetMagicTargetAsReference())
		{
			auto& conditionUpdateTime = reinterpret_cast<float&>(activeEffect->padding8C);

			if (!forceUpdate)
			{
				if (activeEffect->elapsedTime <= 0.0F)
				{
					conditionUpdateTime = elapsedTimeDelta;

					return;
				}

				static const auto activeEffectConditionUpdateInterval = MagicEffectConditions::ActiveEffectConditionUpdateInterval();

				if (conditionUpdateTime > 0.0F && conditionUpdateTime < activeEffectConditionUpdateInterval)
				{
					conditionUpdateTime += elapsedTimeDelta;

					return;
				}
			}

			conditionUpdateTime = elapsedTimeDelta;

			auto* subject = activeEffect->magicTarget->GetMagicTargetAsReference();
			auto* target  = activeEffect->caster.get().get();

			activeEffect->conditionStatus = activeEffect->effect->conditions.IsTrue(subject, target) && !activeEffect->CheckDisplacementSpellOnTarget() ?
			                                    Skyrim::ActiveEffect::ConditionStatus::kTrue :
			                                    Skyrim::ActiveEffect::ConditionStatus::kFalse;
		}
		else
		{
			activeEffect->conditionStatus = Skyrim::ActiveEffect::ConditionStatus::kNotAvailable;
		}
	}
}
