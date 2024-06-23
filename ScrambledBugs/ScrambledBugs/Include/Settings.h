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
				QuickShot&     Deserialize(const std::filesystem::path& directory);
				nlohmann::json Serialize() const;

				float playbackSpeed{};
				bool  quickShot{};
			};

			Fixes&         Deserialize(const std::filesystem::path& directory);
			nlohmann::json Serialize() const;

			QuickShot quickShot{};
			bool      activateFurniture{};
			bool      actorValuePercentage{};
			bool      enchantmentCost{};
			bool      hitEffectRaceCondition{};
			bool      impactEffectCrash{};
			bool      ingredientRespawn{};
			bool      isCurrentSpell{};
			bool      killCamera{};
			bool      leftHandPowerAttacks{};
			bool      magicEffectFlags{};
			bool      modifyArmorWeightPerkEntryPoint{};
			bool      powerCooldowns{};
			bool      projectileFadeDuration{};
			bool      terrainImpactEffects{};
			bool      trainingMenu{};
			bool      weaponCharge{};
		};

		class Patches
		{
		public:
			class DifficultyMultipliers
			{
			public:
				DifficultyMultipliers& Deserialize(const std::filesystem::path& directory);
				nlohmann::json         Serialize() const;

				bool commandedActors{};
				bool teammates{};
			};

			class PerkEntryPoints
			{
			public:
				PerkEntryPoints& Deserialize(const std::filesystem::path& directory);
				nlohmann::json   Serialize() const;

				bool applySpells{};
				bool castSpells{};
			};

			class SoulGems
			{
			public:
				SoulGems&      Deserialize(const std::filesystem::path& directory);
				nlohmann::json Serialize() const;

				bool black{};
				bool underfilled{};
			};

			class StaffExperience
			{
			public:
				StaffExperience& Deserialize(const std::filesystem::path& directory);
				nlohmann::json   Serialize() const;

				bool ignoreEnchantmentCost{};
				bool staffExperience{};
			};

			Patches&       Deserialize(const std::filesystem::path& directory);
			nlohmann::json Serialize() const;

			DifficultyMultipliers difficultyMultipliers{};
			PerkEntryPoints       perkEntryPoints{};
			SoulGems              soulGems{};
			StaffExperience       staffExperience{};
			bool                  accumulatingMagnitude{};
			bool                  alreadyCaughtPickpocketing{};
			bool                  attachHitEffectArt{};
			bool                  cloakHitEffects{};
			bool                  deferredHitEffects{};
			bool                  enchantmentEffectPower{};
			bool                  equipBestAmmunition{};
			bool                  leveledCharacters{};
			bool                  lockpickingExperience{};
			bool                  poisonResistance{};
			bool                  powerAttackStamina{};
			bool                  reflectDamage{};
			bool                  scrollExperience{};
			bool                  steepSlopes{};
		};

		Settings()                = delete;
		Settings(const Settings&) = delete;
		Settings(Settings&&)      = delete;

		~Settings() = default;

		Settings& operator=(const Settings&) = delete;
		Settings& operator=(Settings&&)      = delete;

		explicit Settings(const std::filesystem::path& directory);

		static void      Deserialize(const std::filesystem::path& path, bool& boolean);
		static void      Deserialize(const std::filesystem::path& path, float& number);
		static Settings& GetSingleton();

		Settings&      Deserialize(const std::filesystem::path& directory);
		nlohmann::json Serialize() const;

		void Load();
		void PostLoad();

		Fixes   fixes{};
		Patches patches{};
	};
}
