#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/D/Difficulty.h"
#include "Shared/Utility/Enumeration.h"



namespace ScrambledBugs::Patches
{
	class TeammateDifficulty
	{
	public:
		static bool Patch();

	private:
		static float GetDifficultyMultiplier(Utility::Enumeration<Skyrim::Difficulty, std::uint32_t> difficulty, bool toPlayer);
		static float MultiplyDamage(Skyrim::Actor* actor, float damage, float decreaseDamageOnly);
	};
}
