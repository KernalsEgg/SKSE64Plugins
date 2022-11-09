#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GameSettingCollection.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	GameSettingCollection* GameSettingCollection::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<GameSettingCollection**>(Addresses::GameSettingCollection::Singleton) };

		return *singleton;
	}

	void GameSettingCollection::InitializeCollection()
	{
		auto* function{ reinterpret_cast<decltype(&GameSettingCollection::InitializeCollection)>(Addresses::GameSettingCollection::InitializeCollection) };

		function();
	}

	SettingT<GameSettingCollection>* GameSettingCollection::ActiveEffectConditionUpdateInterval()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::ActiveEffectConditionUpdateInterval) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::ArrowBowMinimumTime()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::ArrowBowMinimumTime) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::ArrowMinimumPower()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::ArrowMinimumPower) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::BowDrawTime()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::BowDrawTime) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::No()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::No) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::Okay()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::Okay) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::PlayerMaximumResistance()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::PlayerMaximumResistance) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::PowerAttackStaminaPenalty()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::PowerAttackStaminaPenalty) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::StaminaAttackWeaponBase()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::StaminaAttackWeaponBase) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::StaminaAttackWeaponMultiplier()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::StaminaAttackWeaponMultiplier) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::StaminaBashBase()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::StaminaBashBase) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::StaminaPowerBashBase()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::StaminaPowerBashBase) };

		return singleton;
	}

	SettingT<GameSettingCollection>* GameSettingCollection::Yes()
	{
		auto* singleton{ reinterpret_cast<SettingT<GameSettingCollection>*>(Addresses::GameSettingCollection::Yes) };

		return singleton;
	}
}
