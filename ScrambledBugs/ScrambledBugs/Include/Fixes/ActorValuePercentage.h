#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Utility/Enumeration.h"



namespace ScrambledBugs::Fixes
{
	class ActorValuePercentage
	{
	public:
		static void Fix(bool& actorValuePercentage);

	private:
		static float GetActorValuePercentage(Skyrim::Actor* actor, Utility::Enumeration<Skyrim::ActorValue, std::uint32_t> actorValue);
		static float GetHealthPercentage(Skyrim::Actor* actor);
		static float GetStaminaPercentage(Skyrim::Actor* actor);
	};
}
