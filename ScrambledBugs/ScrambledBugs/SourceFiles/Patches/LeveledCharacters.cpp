#include "PrecompiledHeader.h"

#include "Patches/LeveledCharacters.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void LeveledCharacters::Patch(bool& leveledCharacters)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Patches::LeveledCharacters::GetAllBelowForce, reinterpret_cast<std::uintptr_t>(std::addressof(LeveledCharacters::GetAllBelowForce)));
	}

	Skyrim::TESLeveledList::AllBelowForce LeveledCharacters::GetAllBelowForce(Skyrim::ExtraLevCreaModifier* extraLeveledCreatureModifier)
	{
		// extraLeveledCreatureModifier != nullptr

		switch (extraLeveledCreatureModifier->leveledCreatureModifier.get())
		{
			case Skyrim::LeveledCreatureModifier::kEasy:
			{
				return Skyrim::TESLeveledList::AllBelowForce::kLessThan;
			}
			case Skyrim::LeveledCreatureModifier::kNone:
			{
				return Skyrim::TESLeveledList::AllBelowForce::kEqualTo;
			}
			default:
			{
				return Skyrim::TESLeveledList::AllBelowForce::kNone;
			}
		}
	}
}
