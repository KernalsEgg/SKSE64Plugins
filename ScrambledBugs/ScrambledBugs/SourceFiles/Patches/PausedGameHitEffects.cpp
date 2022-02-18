#include "PCH.h"

#include "Patches/PausedGameHitEffects.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	bool PausedGameHitEffects::Patch()
	{
		if (!Patterns::Patches::PausedGameHitEffects::ApplyHitEffects())
		{
			return false;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::PausedGameHitEffects::ApplyHitEffects, Utility::Assembly::NoOperation2);

		return true;
	}
}
