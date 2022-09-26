#include "PrecompiledHeader.h"

#include "Patches/PausedGameHitEffects.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void PausedGameHitEffects::Patch(bool& pausedGameHitEffects)
	{
		if (!Patterns::Patches::PausedGameHitEffects::ShouldApplyHitEffects())
		{
			pausedGameHitEffects = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::PausedGameHitEffects::ShouldApplyHitEffects, Utility::Assembly::NoOperation6);
	}
}
