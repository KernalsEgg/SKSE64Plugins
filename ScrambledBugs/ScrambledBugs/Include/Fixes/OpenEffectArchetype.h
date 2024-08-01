#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class OpenEffectArchetype
	{
	public:
		static void Fix(bool& openEffectArchetype);

	private:
		static bool CheckTarget(Skyrim::ActiveEffectFactory::CheckTargetArguments* checkTargetArguments);
	};
}
