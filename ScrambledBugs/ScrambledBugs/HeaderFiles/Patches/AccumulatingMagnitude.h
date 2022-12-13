#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/AccumulatingValueModifierEffect.h"
#include "Shared/Skyrim/A/ActiveEffect.h"
#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/E/EffectItem.h"
#include "Shared/Skyrim/F/FindMaxMagnitudeVisitor.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/M/MagicTarget.h"



namespace ScrambledBugs::Patches
{
	class AccumulatingMagnitude
	{
	public:
		static void Patch(bool& accumulatingMagnitude);

	private:
		static Skyrim::AccumulatingValueModifierEffect*                    Allocate(Skyrim::Actor* caster, Skyrim::MagicItem* magicItem, Skyrim::EffectItem* effect);
		static float                                                       FindMaximumWardPower(Skyrim::MagicTarget* magicTarget, Skyrim::ActiveEffect* finishedActiveEffect);
		static void                                                        UpdateActorValue(Skyrim::AccumulatingValueModifierEffect* accumulatingValueModifierEffect, float frameTime);
		static Skyrim::MagicTarget::ForEachActiveEffectVisitor::ReturnType Visit(Skyrim::FindMaxMagnitudeVisitor* findMaximumMagnitudeVisitor, Skyrim::ActiveEffect* activeEffect);

		static decltype(&AccumulatingMagnitude::Allocate) allocate_;
	};
}
