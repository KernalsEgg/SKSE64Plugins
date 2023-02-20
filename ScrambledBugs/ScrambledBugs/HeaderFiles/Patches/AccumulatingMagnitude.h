#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class AccumulatingMagnitude
	{
	public:
		static void Patch(bool& accumulatingMagnitude);

	private:
		static Skyrim::AccumulatingValueModifierEffect* Allocate(Skyrim::Actor* caster, Skyrim::MagicItem* magicItem, Skyrim::EffectItem* effect);
		static float                                    FindMaximumWardPower(Skyrim::MagicTarget* magicTarget, Skyrim::ActiveEffect* finishedActiveEffect);
		static Skyrim::ForEachResult                    FunctionCallOperator(Skyrim::FindMaxMagnitudeVisitor* findMaximumMagnitudeVisitor, Skyrim::ActiveEffect* activeEffect);
		static void                                     UpdateActorValue(Skyrim::AccumulatingValueModifierEffect* accumulatingValueModifierEffect, float frameTime);

		static decltype(AccumulatingMagnitude::Allocate)* allocate_;
	};
}
