#pragma once

#include "PCH.h"



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
			bool  killCamera{ false };
			bool  leftHandPowerAttacks{ false };
			bool  magicEffectFlags{ false };
			bool  modArmorWeightPerkEntryPoint{ false };
			bool  powerCooldowns{ false };
			bool  quickShot{ false };
			float quickShotPlaybackSpeed{ 0.0F };
			bool  terrainDecals{ false };
			bool  trainingMenu{ false };
			bool  weaponCharge{ false };
		};

		class Patches
		{
		public:
			class PerkEntryPoints
			{
			public:
				PerkEntryPoints& Deserialize(const nlohmann::json& jsonPerkEntryPoints);
				nlohmann::json   Serialize() const;

				bool applyMultipleSpells{ false };
				bool castSpells{ false };
			};

			Patches&       Deserialize(const nlohmann::json& jsonPatches);
			nlohmann::json Serialize() const;

			bool            accumulatingMagnitude{ false };
			bool            alreadyCaughtPickpocketing{ false };
			bool            attachHitEffectArt{ false };
			bool            blackSoulGems{ false };
			bool            cloakHitEffects{ false };
			bool            equipBestAmmo{ false };
			bool            improveMultipleEnchantmentEffects{ false };
			bool            leveledCharacters{ false };
			bool            lockpickingExperience{ false };
			bool            pausedGameHitEffects{ false };
			PerkEntryPoints perkEntryPoints;
			bool            poisonResistance{ false };
			bool            powerAttackStamina{ false };
			bool            reflectDamage{ false };
			bool            scrollExperience{ false };
			bool            staffExperience{ false };
			bool            steepSlopes{ false };
			bool            underfilledSoulGems{ false };
		};

		Settings()                = delete;
		Settings(const Settings&) = delete;
		Settings(Settings&&)      = delete;

		~Settings() = default;

		Settings& operator=(const Settings&) = delete;
		Settings& operator=(Settings&&) = delete;

		explicit Settings(const std::filesystem::path& path);

		static Settings& GetSingleton();

		Settings&      Deserialize(const nlohmann::json& jsonSettings);
		nlohmann::json Serialize() const;

		Fixes   fixes;
		Patches patches;
	};
}
