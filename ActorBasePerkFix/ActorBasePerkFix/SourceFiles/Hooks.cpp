#include "PCH.h"

#include "Hooks.h"

#include "Shared/SKSE/Interfaces.h"
#include "Shared/Skyrim/A/ActorProcess.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BGSPerk.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/T/TESNPC.h"
#include "Shared/Utility/Memory.h"



namespace ActorBasePerkFix
{
	void Hooks::Install()
	{
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Actor::VirtualFunctionTable, 0x101, reinterpret_cast<std::uintptr_t>(std::addressof(Hooks::ApplyBasePerksActor)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Character::VirtualFunctionTable, 0x101, reinterpret_cast<std::uintptr_t>(std::addressof(Hooks::ApplyBasePerksActor)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::PlayerCharacter::VirtualFunctionTable, 0x101, reinterpret_cast<std::uintptr_t>(std::addressof(Hooks::ApplyBasePerksPlayerCharacter)));
	}

	void Hooks::ApplyBasePerksActor(Skyrim::Actor* actor)
	{
		Skyrim::ActorHandle actorHandle{ actor };

		SKSE::Cache::GetSingleton().GetTaskInterface()->AddTask(
			[actorHandle]()
			{
				auto actor = actorHandle.get().get();

				if (!actor)
				{
					return;
				}

				Hooks::ApplyBasePerksActorImplementation(actor);
			});
	}

	void Hooks::ApplyBasePerksActorImplementation(Skyrim::Actor* actor)
	{
		actor->RemoveBasePerks();

		auto currentProcess = actor->currentProcess;

		if (!currentProcess)
		{
			return;
		}

		auto middleHighProcessData = currentProcess->middleHighProcessData;

		if (!middleHighProcessData)
		{
			return;
		}

		auto npc = static_cast<Skyrim::TESNPC*>(actor->baseObject);

		if (!npc)
		{
			return;
		}

		auto perkRankArray = static_cast<Skyrim::BGSPerkRankArray*>(npc);
		auto perkRanks     = perkRankArray->perkRanks;

		if (!perkRanks)
		{
			return;
		}

		auto perkRankCount = perkRankArray->perkRankCount;

		for (std::uint32_t index = 0; index < perkRankCount; ++index)
		{
			const auto& perkRank = perkRanks[index];
			auto        perk     = perkRank.perk;

			if (!perk)
			{
				continue;
			}

			perk->ApplyPerk(actor, 0, perkRank.currentRank);
		}
	}

	void Hooks::ApplyBasePerksPlayerCharacter(Skyrim::PlayerCharacter* player)
	{
		Skyrim::BSPointerHandle<Skyrim::PlayerCharacter> playerHandle{ player };

		SKSE::Cache::GetSingleton().GetTaskInterface()->AddTask(
			[playerHandle]()
			{
				auto player = playerHandle.get().get();

				if (!player)
				{
					return;
				}

				Hooks::ApplyBasePerksPlayerCharacterImplementation(player);
			});
	}

	void Hooks::ApplyBasePerksPlayerCharacterImplementation(Skyrim::PlayerCharacter* player)
	{
		Hooks::ApplyBasePerksActorImplementation(player);

		for (auto addedPerkRank : player->addedPerkRanks)
		{
			auto perk = addedPerkRank->perk;

			if (!perk)
			{
				continue;
			}

			perk->ApplyPerk(player, 0, addedPerkRank->currentRank);
		}
	}
}
