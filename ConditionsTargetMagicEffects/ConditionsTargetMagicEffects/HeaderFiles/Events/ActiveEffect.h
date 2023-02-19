#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class ActiveEffect
	{
	public:
		friend class DualValueModifierEffect;

		static void Register();

	private:
		static void AdjustForPerks(Skyrim::ActiveEffect* activeEffect, Skyrim::Actor* caster, Skyrim::MagicTarget* magicTarget);
	};
}
