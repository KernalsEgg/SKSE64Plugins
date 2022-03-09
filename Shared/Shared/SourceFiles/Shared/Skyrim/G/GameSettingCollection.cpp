#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GameSettingCollection.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	SettingT<GameSettingCollection>* GameSettingCollection::ActiveEffectConditionUpdateInterval()
	{
		auto singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::ActiveEffectConditionUpdateInterval) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::ArrowBowMinimumTime()
	{
		auto singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::ArrowBowMinimumTime) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::ArrowMinimumPower()
	{
		auto singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::ArrowMinimumPower) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::BowDrawTime()
	{
		auto singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::BowDrawTime) };

		return singleton;
	}

	GameSettingCollection::DifficultyMultipliers* GameSettingCollection::DifficultyMultiplierHealthByPlayer()
	{
		auto singleton{ reinterpret_cast<DifficultyMultipliers**>(Addresses::GameSettingCollection::DifficultyMultiplierHealthByPlayer) };

		return *singleton;
	}

	GameSettingCollection::DifficultyMultipliers* GameSettingCollection::DifficultyMultiplierHealthToPlayer()
	{
		auto singleton{ reinterpret_cast<DifficultyMultipliers**>(Addresses::GameSettingCollection::DifficultyMultiplierHealthToPlayer) };

		return *singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::PlayerMaximumResistance()
	{
		auto singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::PlayerMaximumResistance) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::PowerAttackStaminaPenalty()
	{
		auto singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::PowerAttackStaminaPenalty) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::StaminaAttackWeaponBase()
	{
		auto singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::StaminaAttackWeaponBase) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::StaminaAttackWeaponMultiplier()
	{
		auto singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::StaminaAttackWeaponMultiplier) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::StaminaBashBase()
	{
		auto singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::StaminaBashBase) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::StaminaPowerBashBase()
	{
		auto singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::StaminaPowerBashBase) };

		return singleton;
	}
}
