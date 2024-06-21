#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class DualValueModifierEffect
	{
	public:
		static void Register();

	private:
		static void AdjustForPerks(Skyrim::DualValueModifierEffect* dualValueModifierEffect, Skyrim::Actor* caster, Skyrim::MagicTarget* magicTarget);
	};
}
