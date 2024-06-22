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
			class QuickShot
			{
			public:
				QuickShot&     Deserialize(const nlohmann::json& jsonQuickShot);
				nlohmann::json Serialize() const;

				float playbackSpeed{ 2.0F };
				bool  quickShot{ false };
			};

			Fixes&         Deserialize(const nlohmann::json& jsonFixes);
			nlohmann::json Serialize() const;

			bool      activateFurniture{ false };
			bool      actorValuePercentage{ false };
			bool      enchantmentCost{ false };
			bool      hitEffectRaceCondition{ false };
			bool      impactEffectCrash{ false };
			bool      ingredientRespawn{ false };
			bool      isCurrentSpell{ false };
			bool      killCamera{ false };
			bool      leftHandPowerAttacks{ false };
			bool      magicEffectFlags{ false };
			bool      modifyArmorWeightPerkEntryPoint{ false };
			bool      powerCooldowns{ false };
			bool      projectileFadeDuration{ false };
			QuickShot quickShot{};
			bool      terrainImpactEffects{ false };
			bool      trainingMenu{ false };
			bool      weaponCharge{ false };
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

				bool applySpells{ false };
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

			class StaffExperience
			{
			public:
				StaffExperience& Deserialize(const nlohmann::json& jsonStaffExperience);
				nlohmann::json   Serialize() const;

				bool ignoreEnchantmentCost{ false };
				bool staffExperience{ false };
			};

			Patches&       Deserialize(const nlohmann::json& jsonPatches);
			nlohmann::json Serialize() const;

			bool                  accumulatingMagnitude{ false };
			bool                  alreadyCaughtPickpocketing{ false };
			bool                  attachHitEffectArt{ false };
			bool                  cloakHitEffects{ false };
			bool                  deferredHitEffects{ false };
			DifficultyMultipliers difficultyMultipliers{};
			bool                  enchantmentEffectPower{ false };
			bool                  equipBestAmmunition{ false };
			bool                  leveledCharacters{ false };
			bool                  lockpickingExperience{ false };
			PerkEntryPoints       perkEntryPoints{};
			bool                  poisonResistance{ false };
			bool                  powerAttackStamina{ false };
			bool                  reflectDamage{ false };
			bool                  scrollExperience{ false };
			SoulGems              soulGems{};
			StaffExperience       staffExperience{};
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
		nlohmann::json Serialize() const;

		void Load();
		void PostLoad();

		Fixes   fixes{};
		Patches patches{};
	};
}
