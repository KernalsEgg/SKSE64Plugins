#include "PrecompiledHeader.h"

#include "Patches/AlreadyCaughtPickpocketing.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void AlreadyCaughtPickpocketing::Patch(bool& alreadyCaughtPickpocketing)
	{
		if (!Patterns::Patches::AlreadyCaughtPickpocketing::IsAngryWithPlayer() ||
			!Patterns::Patches::AlreadyCaughtPickpocketing::HasBeenPickpocketed())
		{
			alreadyCaughtPickpocketing = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::AlreadyCaughtPickpocketing::IsAngryWithPlayer, std::optional<std::uint8_t>{}, 0x00ui8);
		Utility::Memory::SafeWrite(Addresses::Patches::AlreadyCaughtPickpocketing::HasBeenPickpocketed, std::optional<std::uint8_t>{}, 0x00ui8);
	}
}
