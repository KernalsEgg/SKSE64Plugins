#include "PCH.h"

#include "Fixes/MagicEffectConditions.h"

#include "Addresses.h"
#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/E/Effect.h"
#include "Shared/Skyrim/G/GameSettingCollection.h"
#include "Shared/Skyrim/M/MagicTarget.h"
#include "Shared/Utility/Memory.h"



namespace BugFixesSSE::Fixes
{
	bool MagicEffectConditions::Fix()
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::MagicEffectConditions::UpdateConditions, reinterpret_cast<std::uintptr_t>(std::addressof(MagicEffectConditions::UpdateConditions)));

		return true;
	}

	float MagicEffectConditions::ActiveEffectConditionUpdateInterval()
	{
		auto activeEffectConditionUpdateInterval = Skyrim::GameSettingCollection::ActiveEffectConditionUpdateInterval()->value.floatingPoint;

		return activeEffectConditionUpdateInterval > 0.0001F ? activeEffectConditionUpdateInterval : 1.0F;
	}

	void MagicEffectConditions::UpdateConditions(Skyrim::ActiveEffect* activeEffect, float frameTime, bool forceUpdate)
	{
		// activeEffect != nullptr

		if (activeEffect->conditions == Skyrim::ActiveEffect::Conditions::kNotAvailable)
		{
			return;
		}

		if ((activeEffect->activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kHasConditions) || activeEffect->displacementSpell) && activeEffect->magicTarget && activeEffect->magicTarget->GetMagicTargetOwner())
		{
			if (!forceUpdate)
			{
				if (activeEffect->elapsedTime <= 0.0F)
				{
					reinterpret_cast<float&>(activeEffect->padding8C) = frameTime;

					return;
				}

				static const auto activeEffectConditionUpdateInterval = MagicEffectConditions::ActiveEffectConditionUpdateInterval();

				if (reinterpret_cast<float&>(activeEffect->padding8C) > 0.0F && reinterpret_cast<float&>(activeEffect->padding8C) < activeEffectConditionUpdateInterval)
				{
					reinterpret_cast<float&>(activeEffect->padding8C) += frameTime;

					return;
				}
			}

			reinterpret_cast<float&>(activeEffect->padding8C) = frameTime;

			auto subject = activeEffect->magicTarget->GetMagicTargetOwner();
			auto target  = activeEffect->caster.get().get();

			activeEffect->conditions = activeEffect->effect->conditions.IsTrue(subject, target) && !activeEffect->ShouldDisplace() ?
                                           Skyrim::ActiveEffect::Conditions::kTrue :
                                           Skyrim::ActiveEffect::Conditions::kFalse;
		}
		else
		{
			activeEffect->conditions = Skyrim::ActiveEffect::Conditions::kNotAvailable;
		}
	}
}
