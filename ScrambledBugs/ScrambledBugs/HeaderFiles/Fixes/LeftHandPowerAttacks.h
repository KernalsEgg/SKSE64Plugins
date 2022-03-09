#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/ActorValueOwner.h"
#include "Shared/Skyrim/B/BGSAttackData.h"



namespace ScrambledBugs::Fixes
{
	class LeftHandPowerAttacks
	{
	public:
		static void Fix(bool& leftHandPowerAttacks);

	private:
		static float GetAttackStamina(Skyrim::ActorValueOwner* actorValueOwner, Skyrim::BGSAttackData* attackData);
	};
}
