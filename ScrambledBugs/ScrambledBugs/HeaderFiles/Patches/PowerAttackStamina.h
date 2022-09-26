#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValueOwner.h"
#include "Shared/Skyrim/B/BGSAttackData.h"



namespace ScrambledBugs::Patches
{
	class PowerAttackStamina
	{
	public:
		static void Patch(bool& powerAttackStamina);

	private:
		static float HasAttackStaminaActor(Skyrim::ActorValueOwner* actorValueOwner, Skyrim::BGSAttackData* attackData);
		static float HasAttackStaminaPlayerCharacter(Skyrim::ActorValueOwner* actorValueOwner, Skyrim::BGSAttackData* attackData);

		static decltype(&PowerAttackStamina::HasAttackStaminaActor)           getAttackStaminaActor_;
		static decltype(&PowerAttackStamina::HasAttackStaminaPlayerCharacter) getAttackStaminaPlayerCharacter_;
	};
}
