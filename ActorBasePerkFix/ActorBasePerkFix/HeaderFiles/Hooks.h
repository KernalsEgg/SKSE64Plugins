#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"



namespace ActorBasePerkFix
{
	class Hooks
	{
	public:
		static void Install();

	private:
		static void ApplyBasePerksActor(Skyrim::Actor* actor);
		static void ApplyBasePerksActorImplementation(Skyrim::Actor* actor);
		static void ApplyBasePerksPlayerCharacter(Skyrim::PlayerCharacter* player);
		static void ApplyBasePerksPlayerCharacterImplementation(Skyrim::PlayerCharacter* player);
	};
}
