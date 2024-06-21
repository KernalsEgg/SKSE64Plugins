#include "PrecompiledHeader.h"

#include "Fixes/ProjectileFadeDuration.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void ProjectileFadeDuration::Fix(bool& projectileFadeDuration)
	{
		if (!Patterns::Fixes::ProjectileFadeDuration::HasFaded() ||
			!Patterns::Fixes::ProjectileFadeDuration::HasProcessedImpacts())
		{
			projectileFadeDuration = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Fixes::ProjectileFadeDuration::HasProcessedImpacts, std::optional<std::uint8_t>{}, std::optional<std::uint8_t>{}, 0x0Dui32);
	}
}
