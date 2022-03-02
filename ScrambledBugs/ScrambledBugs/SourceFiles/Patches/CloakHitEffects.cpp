#include "PCH.h"

#include "Patches/CloakHitEffects.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void CloakHitEffects::Patch(bool& cloakHitEffects)
	{
		if (!Patterns::Patches::CloakHitEffects::IsNotCostliestEffect())
		{
			cloakHitEffects = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::CloakHitEffects::IsNotCostliestEffect, 0xEBui8, std::optional<std::uint8_t>{});
	}
}
