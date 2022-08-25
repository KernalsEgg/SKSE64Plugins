#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/S/SettingCollectionMap.h"
#include "Shared/Skyrim/S/SettingT.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class GameSettingCollection :
		public SettingCollectionMap<Setting> // 0
	{
	public:
		// Override
		virtual ~GameSettingCollection() override; // 0

		// Override (SettingCollectionMap<Setting>)
		virtual bool WriteSetting(Setting* setting) override;        // 3
		virtual bool ReadSetting(Setting* setting) override;         // 4
		virtual void Unknown5(SettingCollection<Setting>*) override; // 5
		virtual void Unknown6(SettingCollection<Setting>*) override; // 6

		// Add
		virtual void UnknownA(GameSettingCollection*); // A

		// Non-member functions
		static SettingT<GameSettingCollection>* ActiveEffectConditionUpdateInterval();
		static SettingT<GameSettingCollection>* ArrowBowMinimumTime();
		static SettingT<GameSettingCollection>* ArrowMinimumPower();
		static SettingT<GameSettingCollection>* BowDrawTime();
		static SettingT<GameSettingCollection>* PlayerMaximumResistance();
		static SettingT<GameSettingCollection>* PowerAttackStaminaPenalty();
		static SettingT<GameSettingCollection>* StaminaAttackWeaponBase();
		static SettingT<GameSettingCollection>* StaminaAttackWeaponMultiplier();
		static SettingT<GameSettingCollection>* StaminaBashBase();
		static SettingT<GameSettingCollection>* StaminaPowerBashBase();
	};
	static_assert(sizeof(GameSettingCollection) == 0x140);
}
