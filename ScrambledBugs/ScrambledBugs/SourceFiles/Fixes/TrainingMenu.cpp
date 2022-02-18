#include "PCH.h"

#include "Fixes/TrainingMenu.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	bool TrainingMenu::Fix()
	{
		if (!Patterns::Fixes::TrainingMenu::GetPermanentActorValue())
		{
			return false;
		}

		Utility::Memory::SafeWrite(Addresses::Fixes::TrainingMenu::GetPermanentActorValue, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 0x18ui8);

		return true;
	}
}
