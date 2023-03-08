#include "PrecompiledHeader.h"

#include "Patches/LockpickingExperience.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void LockpickingExperience::Patch(bool& lockpickingExperience)
	{
		if (!Patterns::Patches::LockpickingExperience::HasNotBeenUnlocked())
		{
			lockpickingExperience = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::LockpickingExperience::HasNotBeenUnlocked, std::optional<std::uint8_t>{}, 0x00ui8);
	}
}
