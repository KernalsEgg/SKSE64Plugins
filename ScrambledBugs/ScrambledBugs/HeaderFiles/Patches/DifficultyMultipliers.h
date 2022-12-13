#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"



namespace ScrambledBugs::Patches
{
	class DifficultyMultipliers
	{
	public:
		static void Patch(bool& commandedActors, bool& teammates);

	private:
		static float AdjustHealthDamageToDifficulty(Skyrim::Actor* target, float damage, float onlyReduceDamage);
		static bool  DamageHealth(Skyrim::Actor* target, float damage, Skyrim::Actor* attacker, bool onlyReduceDamage);
		static bool  IsCommandedActor(Skyrim::Actor* actor);
		static bool  IsTeammate(Skyrim::Actor* actor);

		static bool commandedActors_;
		static bool teammates_;
	};
}
