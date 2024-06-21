#pragma once

#include "PrecompiledHeader.h"



namespace ScriptEffectArchetypeCrashFix
{
	class Events
	{
	public:
		static void Register();

	private:
		using CheckTargetFunction = bool(Skyrim::ActiveEffectFactory::CheckTargetArguments&);
	};
}
