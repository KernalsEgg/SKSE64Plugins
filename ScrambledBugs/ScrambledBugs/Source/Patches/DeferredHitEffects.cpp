#include "PrecompiledHeader.h"

#include "Patches/DeferredHitEffects.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void DeferredHitEffects::Patch(bool& deferredHitEffects)
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Addresses::Patches::DeferredHitEffects::AllowHitEffects,
			reinterpret_cast<std::uintptr_t>(std::addressof(DeferredHitEffects::AllowHitEffects)));
	}

	bool DeferredHitEffects::AllowHitEffects(Skyrim::ActiveEffect* activeEffect)
	{
		return true;
	}
}
