#include "PCH.h"

#include "Patches/AlreadyCaughtPickpocketing.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void AlreadyCaughtPickpocketing::Patch(bool& alreadyCaughtPickpocketing)
	{
		if (!Patterns::Patches::AlreadyCaughtPickpocketing::AttackOnSight() ||
			!Patterns::Patches::AlreadyCaughtPickpocketing::HasBeenPickpocketed())
		{
			alreadyCaughtPickpocketing = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::AlreadyCaughtPickpocketing::AttackOnSight, Utility::Assembly::NoOperation2);
		Utility::Memory::SafeWrite(Addresses::Patches::AlreadyCaughtPickpocketing::HasBeenPickpocketed, Utility::Assembly::NoOperation2);
	}
}
