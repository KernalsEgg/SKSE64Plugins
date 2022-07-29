#include "PCH.h"

#include "Patches/AccumulatingMagnitude.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	/*
	Swap the maximum magnitude and the accumulation rate (magnitude) of AccumulatingValueModifierEffects
	The maximum magnitude of AccumulatingValueModifierEffects therefore scales with effectiveness instead of the accumulation rate
	*/
	void AccumulatingMagnitude::Patch(bool& accumulatingMagnitude)
	{
		auto accumulatingValueModifierEffectAllocate                                                            = Addresses::Patches::AccumulatingMagnitude::ActiveEffectAllocateFunctions + sizeof(std::uintptr_t) * Utility::ToUnderlying(Skyrim::EffectArchetype::kAccumulateMagnitude);
		AccumulatingMagnitude::allocate_                                                                        = *reinterpret_cast<decltype(AccumulatingMagnitude::allocate_)*>(accumulatingValueModifierEffectAllocate);
		*reinterpret_cast<decltype(AccumulatingMagnitude::allocate_)*>(accumulatingValueModifierEffectAllocate) = std::addressof(AccumulatingMagnitude::Allocate);

		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::AccumulatingValueModifierEffect::VirtualFunctionTable, 0x1D, reinterpret_cast<std::uintptr_t>(std::addressof(AccumulatingMagnitude::UpdateActorValue)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::FindMaxMagnitudeVisitor::VirtualFunctionTable, 0x1, reinterpret_cast<std::uintptr_t>(std::addressof(AccumulatingMagnitude::Visit)));
	}

	Skyrim::AccumulatingValueModifierEffect* AccumulatingMagnitude::Allocate(Skyrim::Actor* caster, Skyrim::MagicItem* magicItem, Skyrim::Effect* effect)
	{
		// accumulatingValueModifierEffect != nullptr

		auto* accumulatingValueModifierEffect = AccumulatingMagnitude::allocate_(caster, magicItem, effect);

		// Swap the accumulation rate and the maximum magnitude
		std::swap(accumulatingValueModifierEffect->magnitude, accumulatingValueModifierEffect->maximumMagnitude);

		return accumulatingValueModifierEffect;
	}

	float AccumulatingMagnitude::FindMaximumWardPower(Skyrim::MagicTarget* magicTarget, Skyrim::ActiveEffect* finishedActiveEffect)
	{
		Skyrim::FindMaxMagnitudeVisitor findMaximumMagnitudeVisitor;
		*reinterpret_cast<std::uintptr_t*>(std::addressof(findMaximumMagnitudeVisitor)) = Skyrim::Addresses::FindMaxMagnitudeVisitor::VirtualFunctionTable;
		findMaximumMagnitudeVisitor.finishedActiveEffect                                = finishedActiveEffect;
		findMaximumMagnitudeVisitor.maximumMagnitude                                    = -1.0F;

		magicTarget->VisitActiveEffects(std::addressof(findMaximumMagnitudeVisitor));

		return findMaximumMagnitudeVisitor.maximumMagnitude;
	}

	void AccumulatingMagnitude::UpdateActorValue(Skyrim::AccumulatingValueModifierEffect* accumulatingValueModifierEffect, float frameTime)
	{
		// accumulatingValueModifierEffect != nullptr

		if (accumulatingValueModifierEffect->holdDuration <= 0.0F)
		{
			auto* magicTarget = accumulatingValueModifierEffect->magicTarget;

			if (magicTarget)
			{
				auto* magicTargetOwnerActor = magicTarget->GetMagicTargetOwnerActor();

				if (magicTargetOwnerActor)
				{
					// Swap the accumulation rate and the maximum magnitude
					auto maximumMagnitude = accumulatingValueModifierEffect->GetCurrentMagnitude();
					auto accumulationRate = accumulatingValueModifierEffect->maximumMagnitude * frameTime;

					if (accumulatingValueModifierEffect->actorValue == Skyrim::ActorValue::kWardPower)
					{
						// Update maximum ward power
						auto maximumWardPower = AccumulatingMagnitude::FindMaximumWardPower(magicTarget, nullptr);
						magicTargetOwnerActor->SetMaximumWardPower(maximumWardPower);

						if (maximumWardPower > 0.0F)
						{
							maximumMagnitude = maximumWardPower;
						}
					}

					auto currentMagnitude = magicTargetOwnerActor->GetActorValue(accumulatingValueModifierEffect->actorValue);

					if (currentMagnitude + accumulationRate > maximumMagnitude)
					{
						accumulationRate = maximumMagnitude - currentMagnitude;
					}

					accumulatingValueModifierEffect->ModifyActorValue(magicTargetOwnerActor, accumulationRate, Skyrim::ActorValue::kNone);
					accumulatingValueModifierEffect->currentMagnitude += accumulationRate;
				}
			}
		}
		else
		{
			accumulatingValueModifierEffect->holdDuration -= frameTime;
		}
	}

	Skyrim::MagicTarget::ForEachActiveEffectVisitor::ReturnType AccumulatingMagnitude::Visit(Skyrim::FindMaxMagnitudeVisitor* findMaximumMagnitudeVisitor, Skyrim::ActiveEffect* activeEffect)
	{
		// findMaximumMagnitudeVisitor != nullptr

		if (!activeEffect)
		{
			return Skyrim::MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
		}

		if (activeEffect == findMaximumMagnitudeVisitor->finishedActiveEffect)
		{
			return Skyrim::MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
		}

		if (activeEffect->GetBaseEffect()->effectArchetype != Skyrim::EffectArchetype::kAccumulateMagnitude)
		{
			return Skyrim::MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
		}

		auto* accumulatingValueModifierEffect = static_cast<Skyrim::AccumulatingValueModifierEffect*>(activeEffect);

		if (accumulatingValueModifierEffect->actorValue != Skyrim::ActorValue::kWardPower)
		{
			return Skyrim::MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
		}

		// Get the accumulation rate instead of the maximum magnitude
		auto accumulationRate = accumulatingValueModifierEffect->GetCurrentMagnitude();

		if (accumulationRate > findMaximumMagnitudeVisitor->maximumMagnitude)
		{
			findMaximumMagnitudeVisitor->maximumMagnitude = accumulationRate;
		}

		return Skyrim::MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
	}

	decltype(&AccumulatingMagnitude::Allocate) AccumulatingMagnitude::allocate_{ nullptr };
}
