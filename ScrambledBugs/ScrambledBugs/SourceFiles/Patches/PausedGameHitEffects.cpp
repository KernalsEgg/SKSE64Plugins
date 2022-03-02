#include "PCH.h"

#include "Patches/PausedGameHitEffects.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void PausedGameHitEffects::Patch(bool& pausedGameHitEffects)
	{
		if (!Patterns::Patches::PausedGameHitEffects::ApplyHitEffects())
		{
			pausedGameHitEffects = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::PausedGameHitEffects::ApplyHitEffects, Utility::Assembly::NoOperation2);
	}
}
