#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/AccumulatingValueModifierEffect.h"
#include "Shared/Skyrim/A/ActiveEffect.h"
#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/E/Effect.h"
#include "Shared/Skyrim/F/FindMaxMagnitudeVisitor.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/M/MagicTarget.h"



namespace ScrambledBugs::Patches
{
	class AccumulatingMagnitude
	{
	public:
		static bool Patch();

	private:
		static Skyrim::AccumulatingValueModifierEffect*                    Constructor(Skyrim::AccumulatingValueModifierEffect* accumulatingValueModifierEffect, Skyrim::Actor* caster, Skyrim::MagicItem* spell, Skyrim::Effect* effect);
		static float                                                       FindMaximumWardPower(Skyrim::MagicTarget* magicTarget, Skyrim::ActiveEffect* finishedActiveEffect);
		static void                                                        UpdateActorValue(Skyrim::AccumulatingValueModifierEffect* accumulatingValueModifierEffect, float frameTime);
		static Skyrim::MagicTarget::ForEachActiveEffectVisitor::ReturnType Visit(Skyrim::FindMaxMagnitudeVisitor* findMaximumMagnitudeVisitor, Skyrim::ActiveEffect* activeEffect);

		static decltype(&AccumulatingMagnitude::Constructor) constructor_;
	};
}
