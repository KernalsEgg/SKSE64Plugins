#include "PrecompiledHeader.h"

#include "Patches/LockpickingExperience.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
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

		Utility::Memory::SafeWrite(Addresses::Patches::LockpickingExperience::HasNotBeenUnlocked, Utility::Assembly::NO_OPERATION_2);
	}
}
