#include "PrecompiledHeader.h"

#include "Patches/PausedGameHitEffects.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void PausedGameHitEffects::Patch(bool& pausedGameHitEffects)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Patches::PausedGameHitEffects::AllowHitEffects, reinterpret_cast<std::uintptr_t>(std::addressof(PausedGameHitEffects::AllowHitEffects)));
	}

	bool PausedGameHitEffects::AllowHitEffects(Skyrim::ActiveEffect* activeEffect)
	{
		return true;
	}
}
