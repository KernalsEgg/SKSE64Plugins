#include "PrecompiledHeader.h"

#include "Patches.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ConsoleCommandCompanion
{
	bool Patches::Install()
	{
		if (!Patterns::Patches::IsLoggedIn())
		{
			return false;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::IsLoggedIn(), std::optional<std::uint8_t>{}, 0x00ui8);

		return true;
	}
}
