#include "PrecompiledHeader.h"

#include "Fixes/TrainingMenu.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void TrainingMenu::Fix(bool& trainingMenu)
	{
		if (!Patterns::Fixes::TrainingMenu::GetPermanentActorValue())
		{
			trainingMenu = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Fixes::TrainingMenu::GetPermanentActorValue, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 0x18ui8);
	}
}
