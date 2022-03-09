#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/D/Difficulty.h"
#include "Shared/Skyrim/S/SettingCollectionMap.h"
#include "Shared/Skyrim/S/SettingT.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class GameSettingCollection :
		public SettingCollectionMap<Setting>
	{
	public:
		struct DifficultyMultipliers
		{
		public:
			// Member variables
			SettingT<GameSettingCollection> multipliers[Utility::ToUnderlying(Difficulty::kTotal)];
		};
		static_assert(offsetof(DifficultyMultipliers, multipliers) == 0x0);
		static_assert(sizeof(DifficultyMultipliers) == 0x90);

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
		static DifficultyMultipliers*           DifficultyMultiplierHealthByPlayer();
		static DifficultyMultipliers*           DifficultyMultiplierHealthToPlayer();
		static SettingT<GameSettingCollection>* PlayerMaximumResistance();
		static SettingT<GameSettingCollection>* PowerAttackStaminaPenalty();
		static SettingT<GameSettingCollection>* StaminaAttackWeaponBase();
		static SettingT<GameSettingCollection>* StaminaAttackWeaponMultiplier();
		static SettingT<GameSettingCollection>* StaminaBashBase();
		static SettingT<GameSettingCollection>* StaminaPowerBashBase();
	};
	static_assert(sizeof(GameSettingCollection) == 0x140);
}
