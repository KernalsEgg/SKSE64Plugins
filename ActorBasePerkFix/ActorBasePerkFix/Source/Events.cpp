#include "PrecompiledHeader.h"

#include "Events.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ActorBasePerkFix
{
	void Events::Register()
	{
		Events::applyBasePerksActor_           = reinterpret_cast<decltype(Events::applyBasePerksActor_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::Actor::VirtualFunctionTable(), 0x101));
		Events::applyBasePerksCharacter_       = reinterpret_cast<decltype(Events::applyBasePerksCharacter_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::Character::VirtualFunctionTable(), 0x101));
		Events::applyBasePerksPlayerCharacter_ = reinterpret_cast<decltype(Events::applyBasePerksPlayerCharacter_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::PlayerCharacter::VirtualFunctionTable(), 0x101));

		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Actor::VirtualFunctionTable(), 0x101, reinterpret_cast<std::uintptr_t>(std::addressof(Events::ApplyBasePerksActor)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Character::VirtualFunctionTable(), 0x101, reinterpret_cast<std::uintptr_t>(std::addressof(Events::ApplyBasePerksCharacter)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::PlayerCharacter::VirtualFunctionTable(), 0x101, reinterpret_cast<std::uintptr_t>(std::addressof(Events::ApplyBasePerksPlayerCharacter)));

		Utility::Memory::SafeWriteAbsoluteJump(Addresses::TaskQueueInterface::QueueApplyPerk, reinterpret_cast<std::uintptr_t>(std::addressof(Events::QueueApplyPerk)));
	}

	void Events::ApplyBasePerksActor(Skyrim::Actor* actor)
	{
		actor->RemoveBasePerks();

		Events::applyBasePerksActor_(actor);
	}

	void Events::ApplyBasePerksCharacter(Skyrim::Character* character)
	{
		character->RemoveBasePerks();

		Events::applyBasePerksCharacter_(character);
	}

	void Events::ApplyBasePerksPlayerCharacter(Skyrim::PlayerCharacter* player)
	{
		player->RemoveBasePerks();

		Events::applyBasePerksPlayerCharacter_(player);
	}

	void Events::QueueApplyPerk(Skyrim::TaskQueueInterface* taskQueueInterface, Skyrim::Actor* perkOwner, Skyrim::BGSPerk* perk, std::uint8_t removeRank, std::uint8_t applyRank)
	{
		if (!perkOwner)
		{
			return;
		}

		if (!perk)
		{
			return;
		}

		perk->ApplyPerk(perkOwner, removeRank, applyRank);
	}

	decltype(Events::ApplyBasePerksActor)*           Events::applyBasePerksActor_{ nullptr };
	decltype(Events::ApplyBasePerksCharacter)*       Events::applyBasePerksCharacter_{ nullptr };
	decltype(Events::ApplyBasePerksPlayerCharacter)* Events::applyBasePerksPlayerCharacter_{ nullptr };
}
