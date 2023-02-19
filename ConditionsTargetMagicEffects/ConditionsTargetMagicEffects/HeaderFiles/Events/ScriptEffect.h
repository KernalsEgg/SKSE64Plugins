#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class ScriptEffect
	{
	public:
		friend class SlowTimeEffect;

	private:
		static void Start(Skyrim::ScriptEffect* scriptEffect);
	};
}
