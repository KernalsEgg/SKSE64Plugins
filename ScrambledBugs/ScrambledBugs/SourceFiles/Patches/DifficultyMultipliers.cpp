#include "PrecompiledHeader.h"

#include "Patches/DifficultyMultipliers.h"

#include "Addresses.h"
#include "Shared/Skyrim/A/AIProcess.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/C/CombatController.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Skyrim/T/TaskQueueInterface.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void DifficultyMultipliers::Patch(bool& commandedActors, bool& followers)
	{
		DifficultyMultipliers::commandedActors_ = commandedActors;
		DifficultyMultipliers::followers_       = followers;

		Utility::Memory::SafeWriteAbsoluteJump(Skyrim::Addresses::Actor::AdjustHealthDamageToDifficulty, reinterpret_cast<std::uintptr_t>(std::addressof(DifficultyMultipliers::AdjustHealthDamageToDifficulty)));
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Patches::DifficultyMultipliers::DamageHealth, reinterpret_cast<std::uintptr_t>(std::addressof(DifficultyMultipliers::DamageHealth)));
	}

	float DifficultyMultipliers::AdjustHealthDamageToDifficulty(Skyrim::Actor* target, float damage, float onlyReduceDamage)
	{
		auto* player               = Skyrim::PlayerCharacter::GetSingleton();
		auto  difficultyMultiplier = Skyrim::PlayerCharacter::GetDifficultyMultiplier(
			 player->difficulty,
			 Skyrim::ActorValue::kHealth,
			 target == player || (DifficultyMultipliers::followers_ && target->IsPlayerTeammate()) || (DifficultyMultipliers::commandedActors_ && target->GetCommandingActor().get().get() == player));

		return std::abs(onlyReduceDamage) <= 0.0001F || difficultyMultiplier < 1.0F ? difficultyMultiplier * damage : damage;
	}

	bool DifficultyMultipliers::DamageHealth(Skyrim::Actor* target, float damage, Skyrim::Actor* attacker, bool onlyReduceDamage)
	{
		if (target->IsInvulnerable() || target->booleanFlags.all(Skyrim::Actor::BooleanFlags::kInKillMove))
		{
			return false;
		}

		if (target->actorState1.actorLifeState == Skyrim::ActorState::ActorState1::ActorLifeState::kEssentialDown && target->CanBeKilledBy(attacker))
		{
			target->actorState1.actorLifeState = Skyrim::ActorState::ActorState1::ActorLifeState::kAlive;
		}

		auto adjustedDamage = -target->AdjustHealthDamageToDifficulty(-damage, static_cast<float>(onlyReduceDamage));

		if (adjustedDamage > 0.0F)
		{
			auto* targetCombatController = target->combatController;

			if (targetCombatController)
			{
				targetCombatController->DamagedByAttacker(attacker, adjustedDamage);
			}

			if (target != Skyrim::PlayerCharacter::GetSingleton())
			{
				auto* targetCurrentProcess = target->currentProcess;

				if (targetCurrentProcess && target->booleanFlags.none(Skyrim::Actor::BooleanFlags::kEssential) && target->CanBeKilledBy(attacker))
				{
					targetCurrentProcess->ModifyTrackedDamage(attacker, adjustedDamage);
				}
			}

			target->ModifyActorValue(Skyrim::ActorValueModifier::kDamage, Skyrim::ActorValue::kHealth, -adjustedDamage, attacker);

			if (Skyrim::TaskQueueInterface::ShouldQueueTask())
			{
				Skyrim::TaskQueueInterface::GetSingleton()->QueueScriptFunctionCall(0x116C, target, damage);
			}
			else
			{
				target->DamageObject(damage, false);
			}
		}

		return target->IsDead(false);
	}

	bool DifficultyMultipliers::commandedActors_{ false };
	bool DifficultyMultipliers::followers_{ false };
}
