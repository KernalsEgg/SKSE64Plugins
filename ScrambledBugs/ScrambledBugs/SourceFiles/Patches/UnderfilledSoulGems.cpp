#include "PCH.h"

#include "Patches/UnderfilledSoulGems.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	bool UnderfilledSoulGems::Patch()
	{
		if (!Patterns::Patches::UnderfilledSoulGems::CompareSoulLevelValue())
		{
			return false;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::UnderfilledSoulGems::CompareSoulLevelValue, 0x75ui8, std::optional<std::uint8_t>{});

		return true;
	}
}
