#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class DeferredHitEffects
	{
	public:
		static void Patch(bool& deferredHitEffects);

	private:
		static bool AllowHitEffects(Skyrim::ActiveEffect* activeEffect);
	};
}
