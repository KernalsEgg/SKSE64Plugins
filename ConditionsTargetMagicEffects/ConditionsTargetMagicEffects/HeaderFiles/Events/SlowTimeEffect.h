#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class SlowTimeEffect
	{
	public:
		static void Register();

	private:
		static void Start(Skyrim::SlowTimeEffect* slowTimeEffect);
	};
}
