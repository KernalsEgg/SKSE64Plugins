#include "PCH.h"

#include "Patches/LeveledCharacters.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void LeveledCharacters::Patch(bool& leveledCharacters)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Patches::LeveledCharacters::GetLeveledCreatureModifier, reinterpret_cast<std::uintptr_t>(std::addressof(LeveledCharacters::GetLeveledCreatureModifier)));
	}

	std::uint32_t LeveledCharacters::GetLeveledCreatureModifier(Skyrim::ExtraLevCreaModifier* extraLeveledCreatureModifier)
	{
		// extraLeveledCreatureModifier != nullptr

		switch (extraLeveledCreatureModifier->leveledCreatureModifier.get())
		{
			case Skyrim::LeveledCreatureModifier::kEasy:
			{
				return 1;
			}
			case Skyrim::LeveledCreatureModifier::kNone:
			{
				return 0;
			}
		}

		return -1;
	}
}
