#pragma once

#include "PrecompiledHeader.h"



namespace ActorBasePerkFix
{
	class Events
	{
	public:
		static void Register();

	private:
		static void ApplyBasePerksActor(Skyrim::Actor* actor);
		static void ApplyBasePerksCharacter(Skyrim::Character* character);
		static void ApplyBasePerksPlayerCharacter(Skyrim::PlayerCharacter* playerCharacter);
		static void QueueApplyPerk(Skyrim::TaskQueueInterface* taskQueueInterface, Skyrim::Actor* perkOwner, Skyrim::BGSPerk* perk, std::uint8_t removeRank, std::uint8_t applyRank);

		static decltype(Events::ApplyBasePerksActor)*           applyBasePerksActor_;
		static decltype(Events::ApplyBasePerksCharacter)*       applyBasePerksCharacter_;
		static decltype(Events::ApplyBasePerksPlayerCharacter)* applyBasePerksPlayerCharacter_;
	};
}
