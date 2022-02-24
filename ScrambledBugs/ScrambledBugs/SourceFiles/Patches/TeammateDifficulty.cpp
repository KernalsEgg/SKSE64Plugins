#include "PCH.h"

#include "Patches/TeammateDifficulty.h"

#include "Addresses.h"
#include "Shared/Skyrim/G/GameSettingCollection.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	bool TeammateDifficulty::Patch()
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Patches::TeammateDifficulty::MultiplyDamage, reinterpret_cast<std::uintptr_t>(std::addressof(TeammateDifficulty::MultiplyDamage)));

		return true;
	}

	float TeammateDifficulty::GetDifficultyMultiplier(Utility::Enumeration<Skyrim::Difficulty, std::uint32_t> difficulty, bool toPlayer)
	{
		auto difficultyMultiplier = toPlayer ? Skyrim::GameSettingCollection::DifficultyMultiplierHealthToPlayer() : Skyrim::GameSettingCollection::DifficultyMultiplierHealthByPlayer();

		return difficultyMultiplier->multipliers[difficulty.underlying()].value.floatingPoint;
	}

	float TeammateDifficulty::MultiplyDamage(Skyrim::Actor* actor, float damage, float onlyDecreaseDamage)
	{
		auto player               = Skyrim::PlayerCharacter::GetSingleton();
		auto difficultyMultiplier = TeammateDifficulty::GetDifficultyMultiplier(player->difficulty, actor == player || (actor && actor->IsPlayerTeammate()));

		return std::abs(onlyDecreaseDamage) <= 0.0001F || difficultyMultiplier < 1.0F ? difficultyMultiplier * damage : damage;
	}
}
