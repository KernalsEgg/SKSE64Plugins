#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs
{
	class Settings
	{
	public:
		class Fixes
		{
		public:
			Fixes&         Deserialize(const nlohmann::json& jsonFixes);
			nlohmann::json Serialize() const;

			bool  activateFurniture{ false };
			bool  actorValuePercentage{ false };
			bool  enchantmentCost{ false };
			bool  harvestedFlags{ false };
			bool  hitEffectRaceCondition{ false };
			bool  impactEffectCrash{ false };
			bool  isCurrentSpell{ false };
			bool  killCamera{ false };
			bool  leftHandPowerAttacks{ false };
			bool  magicEffectFlags{ false };
			bool  modifyArmorWeightPerkEntryPoint{ false };
			bool  powerCooldowns{ false };
			bool  projectileFadeDuration{ false };
			bool  quickShot{ false };
			float quickShotPlaybackSpeed{ 2.0F };
			bool  terrainDecals{ false };
			bool  trainingMenu{ false };
			bool  weaponCharge{ false };
		};

		class Patches
		{
		public:
			class DifficultyMultipliers
			{
			public:
				DifficultyMultipliers& Deserialize(const nlohmann::json& jsonDifficultyMultipliers);
				nlohmann::json         Serialize() const;

				bool commandedActors{ false };
				bool teammates{ false };
			};

			class PerkEntryPoints
			{
			public:
				PerkEntryPoints& Deserialize(const nlohmann::json& jsonPerkEntryPoints);
				nlohmann::json   Serialize() const;

				bool applyMultipleSpells{ false };
				bool castSpells{ false };
			};

			class SoulGems
			{
			public:
				SoulGems&      Deserialize(const nlohmann::json& jsonSoulGems);
				nlohmann::json Serialize() const;

				bool black{ false };
				bool underfilled{ false };
			};

			Patches&       Deserialize(const nlohmann::json& jsonPatches);
			nlohmann::json Serialize() const;

			bool                  accumulatingMagnitude{ false };
			bool                  alreadyCaughtPickpocketing{ false };
			bool                  attachHitEffectArt{ false };
			bool                  cloakHitEffects{ false };
			DifficultyMultipliers difficultyMultipliers{};
			bool                  equipBestAmmunition{ false };
			bool                  improveMultipleEnchantmentEffects{ false };
			bool                  leveledCharacters{ false };
			bool                  lockpickingExperience{ false };
			bool                  pausedGameHitEffects{ false };
			PerkEntryPoints       perkEntryPoints{};
			bool                  poisonResistance{ false };
			bool                  powerAttackStamina{ false };
			bool                  reflectDamage{ false };
			bool                  scrollExperience{ false };
			SoulGems              soulGems{};
			bool                  staffExperience{ false };
			bool                  staffExperienceIgnoreEnchantmentCost{ false };
			bool                  steepSlopes{ false };
		};

		Settings()                = delete;
		Settings(const Settings&) = delete;
		Settings(Settings&&)      = delete;

		~Settings() = default;

		Settings& operator=(const Settings&) = delete;
		Settings& operator=(Settings&&)      = delete;

		explicit Settings(const std::filesystem::path& path);

		static Settings& GetSingleton();

		Settings&      Deserialize(const nlohmann::json& jsonSettings);
		void           Load();
		void           PostLoad();
		nlohmann::json Serialize() const;

		Fixes   fixes{};
		Patches patches{};
	};
}
