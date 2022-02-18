#include "PCH.h"

#include "Patches/LockpickingExperience.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	bool LockpickingExperience::Patch()
	{
		if (!Patterns::Patches::LockpickingExperience::HasNotBeenUnlocked())
		{
			return false;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::LockpickingExperience::HasNotBeenUnlocked, Utility::Assembly::NoOperation2);

		return true;
	}
}
