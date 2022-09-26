#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/E/ExtraLevCreaModifier.h"



namespace ScrambledBugs::Patches
{
	class LeveledCharacters
	{
	public:
		static void Patch(bool& leveledCharacters);

	private:
		static std::uint32_t GetLeveledCreatureModifier(Skyrim::ExtraLevCreaModifier* extraLeveledCreatureModifier);
	};
}
