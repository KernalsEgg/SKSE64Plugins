#pragma once

#include "PCH.h"

#include "Shared/Skyrim/E/ExtraLevCreaModifier.h"



namespace ScrambledBugs::Patches
{
	class LeveledCharacters
	{
	public:
		static bool Patch();

	private:
		static std::uint32_t GetLeveledCreatureModifier(Skyrim::ExtraLevCreaModifier* extraLeveledCreatureModifier);
	};
}
