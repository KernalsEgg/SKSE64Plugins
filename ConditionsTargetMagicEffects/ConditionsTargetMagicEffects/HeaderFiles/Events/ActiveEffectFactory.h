#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class ActiveEffectFactory
	{
	public:
		static void Register();

	private:
		static bool CheckTargetLevelMagnitude(std::int32_t targetLevel, Skyrim::ActiveEffectFactory::CheckTargetArguments& checkTargetArguments);
	};
}
