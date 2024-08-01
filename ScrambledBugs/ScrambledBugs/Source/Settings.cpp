#include "PrecompiledHeader.h"

#include "Settings.h"

#include "Fixes/ActivateFurniture.h"
#include "Fixes/ActorValuePercentage.h"
#include "Fixes/EnchantmentCost.h"
#include "Fixes/HitEffectRaceCondition.h"
#include "Fixes/ImpactEffectCrash.h"
#include "Fixes/IngredientRespawn.h"
#include "Fixes/IsCurrentSpell.h"
#include "Fixes/KillCamera.h"
#include "Fixes/LeftHandPowerAttacks.h"
#include "Fixes/MagicEffectFlags.h"
#include "Fixes/ModifyArmorWeightPerkEntryPoint.h"
#include "Fixes/OpenEffectArchetype.h"
#include "Fixes/PowerCooldowns.h"
#include "Fixes/ProjectileFadeDuration.h"
#include "Fixes/QuickShot.h"
#include "Fixes/TerrainImpactEffects.h"
#include "Fixes/TrainingMenu.h"
#include "Fixes/WeaponCharge.h"
#include "Patches/AccumulatingMagnitude.h"
#include "Patches/AlreadyCaughtPickpocketing.h"
#include "Patches/AttachHitEffectArt.h"
#include "Patches/CloakHitEffects.h"
#include "Patches/DeferredHitEffects.h"
#include "Patches/DifficultyMultipliers.h"
#include "Patches/EnchantmentEffectPower.h"
#include "Patches/EquipBestAmmunition.h"
#include "Patches/LeveledCharacters.h"
#include "Patches/LockpickingExperience.h"
#include "Patches/PerkEntryPoints/ApplySpells.h"
#include "Patches/PerkEntryPoints/CastSpells.h"
#include "Patches/PoisonResistance.h"
#include "Patches/PowerAttackStamina.h"
#include "Patches/ReflectDamage.h"
#include "Patches/ScrollExperience.h"
#include "Patches/SoulGems.h"
#include "Patches/StaffExperience.h"
#include "Patches/SteepSlopes.h"
#include "Shared/Relocation/Module.h"



namespace ScrambledBugs
{
	Settings::Fixes::QuickShot& Settings::Fixes::QuickShot::Deserialize(const std::filesystem::path& directory)
	{
		Settings::Deserialize(directory / "PlaybackSpeed.json", this->playbackSpeed);
		Settings::Deserialize(directory / "QuickShot.json", this->quickShot);

		return *this;
	}

	nlohmann::json Settings::Fixes::QuickShot::Serialize() const
	{
		nlohmann::json json;

		json["playbackSpeed"] = this->playbackSpeed;
		json["quickShot"]     = this->quickShot;

		return json;
	}

	Settings::Fixes& Settings::Fixes::Deserialize(const std::filesystem::path& directory)
	{
		this->quickShot.Deserialize(directory / "QuickShot");

		Settings::Deserialize(directory / "ActivateFurniture.json", this->activateFurniture);
		Settings::Deserialize(directory / "ActorValuePercentage.json", this->actorValuePercentage);
		Settings::Deserialize(directory / "EnchantmentCost.json", this->enchantmentCost);
		Settings::Deserialize(directory / "HitEffectRaceCondition.json", this->hitEffectRaceCondition);
		Settings::Deserialize(directory / "ImpactEffectCrash.json", this->impactEffectCrash);
		Settings::Deserialize(directory / "IngredientRespawn.json", this->ingredientRespawn);
		Settings::Deserialize(directory / "IsCurrentSpell.json", this->isCurrentSpell);
		Settings::Deserialize(directory / "KillCamera.json", this->killCamera);
		Settings::Deserialize(directory / "LeftHandPowerAttacks.json", this->leftHandPowerAttacks);
		Settings::Deserialize(directory / "MagicEffectFlags.json", this->magicEffectFlags);
		Settings::Deserialize(directory / "ModifyArmorWeightPerkEntryPoint.json", this->modifyArmorWeightPerkEntryPoint);
		Settings::Deserialize(directory / "OpenEffectArchetype.json", this->openEffectArchetype);
		Settings::Deserialize(directory / "PowerCooldowns.json", this->powerCooldowns);
		Settings::Deserialize(directory / "ProjectileFadeDuration.json", this->projectileFadeDuration);
		Settings::Deserialize(directory / "TerrainImpactEffects.json", this->terrainImpactEffects);
		Settings::Deserialize(directory / "TrainingMenu.json", this->trainingMenu);
		Settings::Deserialize(directory / "WeaponCharge.json", this->weaponCharge);

		return *this;
	}

	nlohmann::json Settings::Fixes::Serialize() const
	{
		nlohmann::json json;

		json["quickShot"] = this->quickShot.Serialize();

		json["activateFurniture"]               = this->activateFurniture;
		json["actorValuePercentage"]            = this->actorValuePercentage;
		json["enchantmentCost"]                 = this->enchantmentCost;
		json["hitEffectRaceCondition"]          = this->hitEffectRaceCondition;
		json["impactEffectCrash"]               = this->impactEffectCrash;
		json["ingredientRespawn"]               = this->ingredientRespawn;
		json["isCurrentSpell"]                  = this->isCurrentSpell;
		json["killCamera"]                      = this->killCamera;
		json["leftHandPowerAttacks"]            = this->leftHandPowerAttacks;
		json["magicEffectFlags"]                = this->magicEffectFlags;
		json["modifyArmorWeightPerkEntryPoint"] = this->modifyArmorWeightPerkEntryPoint;
		json["openEffectArchetype"]             = this->openEffectArchetype;
		json["powerCooldowns"]                  = this->powerCooldowns;
		json["projectileFadeDuration"]          = this->projectileFadeDuration;
		json["terrainImpactEffects"]            = this->terrainImpactEffects;
		json["trainingMenu"]                    = this->trainingMenu;
		json["weaponCharge"]                    = this->weaponCharge;

		return json;
	}

	Settings::Patches::DifficultyMultipliers& Settings::Patches::DifficultyMultipliers::Deserialize(const std::filesystem::path& directory)
	{
		Settings::Deserialize(directory / "CommandedActors.json", this->commandedActors);
		Settings::Deserialize(directory / "Teammates.json", this->teammates);

		return *this;
	}

	nlohmann::json Settings::Patches::DifficultyMultipliers::Serialize() const
	{
		nlohmann::json json;

		json["commandedActors"] = this->commandedActors;
		json["teammates"]       = this->teammates;

		return json;
	}

	Settings::Patches::PerkEntryPoints& Settings::Patches::PerkEntryPoints::Deserialize(const std::filesystem::path& directory)
	{
		Settings::Deserialize(directory / "ApplySpells.json", this->applySpells);
		Settings::Deserialize(directory / "CastSpells.json", this->castSpells);

		return *this;
	}

	nlohmann::json Settings::Patches::PerkEntryPoints::Serialize() const
	{
		nlohmann::json json;

		json["applySpells"] = this->applySpells;
		json["castSpells"]  = this->castSpells;

		return json;
	}

	Settings::Patches::SoulGems& Settings::Patches::SoulGems::Deserialize(const std::filesystem::path& directory)
	{
		Settings::Deserialize(directory / "Black.json", this->black);
		Settings::Deserialize(directory / "Underfilled.json", this->underfilled);

		return *this;
	}

	nlohmann::json Settings::Patches::SoulGems::Serialize() const
	{
		nlohmann::json json;

		json["black"]       = this->black;
		json["underfilled"] = this->underfilled;

		return json;
	}

	Settings::Patches::StaffExperience& Settings::Patches::StaffExperience::Deserialize(const std::filesystem::path& directory)
	{
		Settings::Deserialize(directory / "IgnoreEnchantmentCost.json", this->ignoreEnchantmentCost);
		Settings::Deserialize(directory / "StaffExperience.json", this->staffExperience);

		return *this;
	}

	nlohmann::json Settings::Patches::StaffExperience::Serialize() const
	{
		nlohmann::json json;

		json["ignoreEnchantmentCost"] = this->ignoreEnchantmentCost;
		json["staffExperience"]       = this->staffExperience;

		return json;
	}

	Settings::Patches& Settings::Patches::Deserialize(const std::filesystem::path& directory)
	{
		this->difficultyMultipliers.Deserialize(directory / "DifficultyMultipliers");
		this->perkEntryPoints.Deserialize(directory / "PerkEntryPoints");
		this->soulGems.Deserialize(directory / "SoulGems");
		this->staffExperience.Deserialize(directory / "StaffExperience");

		Settings::Deserialize(directory / "AccumulatingMagnitude.json", this->accumulatingMagnitude);
		Settings::Deserialize(directory / "AlreadyCaughtPickpocketing.json", this->alreadyCaughtPickpocketing);
		Settings::Deserialize(directory / "AttachHitEffectArt.json", this->attachHitEffectArt);
		Settings::Deserialize(directory / "CloakHitEffects.json", this->cloakHitEffects);
		Settings::Deserialize(directory / "DeferredHitEffects.json", this->deferredHitEffects);
		Settings::Deserialize(directory / "EnchantmentEffectPower.json", this->enchantmentEffectPower);
		Settings::Deserialize(directory / "EquipBestAmmunition.json", this->equipBestAmmunition);
		Settings::Deserialize(directory / "LeveledCharacters.json", this->leveledCharacters);
		Settings::Deserialize(directory / "LockpickingExperience.json", this->lockpickingExperience);
		Settings::Deserialize(directory / "PoisonResistance.json", this->poisonResistance);
		Settings::Deserialize(directory / "PowerAttackStamina.json", this->powerAttackStamina);
		Settings::Deserialize(directory / "ReflectDamage.json", this->reflectDamage);
		Settings::Deserialize(directory / "ScrollExperience.json", this->scrollExperience);
		Settings::Deserialize(directory / "SteepSlopes.json", this->steepSlopes);

		return *this;
	}

	nlohmann::json Settings::Patches::Serialize() const
	{
		nlohmann::json json;

		json["difficultyMultipliers"] = this->difficultyMultipliers.Serialize();
		json["perkEntryPoints"]       = this->perkEntryPoints.Serialize();
		json["soulGems"]              = this->soulGems.Serialize();
		json["staffExperience"]       = this->staffExperience.Serialize();

		json["accumulatingMagnitude"]      = this->accumulatingMagnitude;
		json["alreadyCaughtPickpocketing"] = this->alreadyCaughtPickpocketing;
		json["attachHitEffectArt"]         = this->attachHitEffectArt;
		json["cloakHitEffects"]            = this->cloakHitEffects;
		json["deferredHitEffects"]         = this->deferredHitEffects;
		json["enchantmentEffectPower"]     = this->enchantmentEffectPower;
		json["equipBestAmmunition"]        = this->equipBestAmmunition;
		json["leveledCharacters"]          = this->leveledCharacters;
		json["lockpickingExperience"]      = this->lockpickingExperience;
		json["poisonResistance"]           = this->poisonResistance;
		json["powerAttackStamina"]         = this->powerAttackStamina;
		json["reflectDamage"]              = this->reflectDamage;
		json["scrollExperience"]           = this->scrollExperience;
		json["steepSlopes"]                = this->steepSlopes;

		return json;
	}

	Settings::Settings(const std::filesystem::path& directory)
	{
		try
		{
			this->Deserialize(directory);
		}
		catch (const std::exception& exception)
		{
			SPDLOG_CRITICAL("{}", exception.what());

			throw;
		}
	}

	void Settings::Deserialize(const std::filesystem::path& path, bool& boolean)
	{
		SPDLOG_INFO("Deserializing... \"{}\"", path.string());

		nlohmann::json::parse(std::ifstream(path)).at("boolean").get_to(boolean);
	}

	void Settings::Deserialize(const std::filesystem::path& path, float& number)
	{
		SPDLOG_INFO("Deserializing... \"{}\"", path.string());

		nlohmann::json::parse(std::ifstream(path)).at("number").get_to(number);
	}

	Settings& Settings::GetSingleton()
	{
		static Settings singleton(std::filesystem::path(Relocation::DynamicLinkLibrary::GetSingleton().GetPath()).replace_extension());

		return singleton;
	}

	Settings& Settings::Deserialize(const std::filesystem::path& directory)
	{
		this->fixes.Deserialize(directory / "Fixes");
		this->patches.Deserialize(directory / "Patches");

		return *this;
	}

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json json;

		json["fixes"]   = this->fixes.Serialize();
		json["patches"] = this->patches.Serialize();

		return json;
	}

	void Settings::Load()
	{
		SPDLOG_INFO("Loading...\n{}", this->Serialize().dump(1, '\t'));

		if (this->fixes.quickShot.quickShot)
		{
			ScrambledBugs::Fixes::QuickShot::Fix(this->fixes.quickShot.quickShot, this->fixes.quickShot.playbackSpeed);
		}

		if (this->fixes.activateFurniture)
		{
			ScrambledBugs::Fixes::ActivateFurniture::Fix(this->fixes.activateFurniture);
		}

		if (this->fixes.actorValuePercentage)
		{
			ScrambledBugs::Fixes::ActorValuePercentage::Fix(this->fixes.actorValuePercentage);
		}

		if (this->fixes.enchantmentCost)
		{
			ScrambledBugs::Fixes::EnchantmentCost::Fix(this->fixes.enchantmentCost);
		}

		if (this->fixes.hitEffectRaceCondition)
		{
			ScrambledBugs::Fixes::HitEffectRaceCondition::Fix(this->fixes.hitEffectRaceCondition);
		}

		if (this->fixes.impactEffectCrash)
		{
			ScrambledBugs::Fixes::ImpactEffectCrash::Fix(this->fixes.impactEffectCrash);
		}

		if (this->fixes.ingredientRespawn)
		{
			ScrambledBugs::Fixes::IngredientRespawn::Fix(this->fixes.ingredientRespawn);
		}

		if (this->fixes.isCurrentSpell)
		{
			ScrambledBugs::Fixes::IsCurrentSpell::Fix(this->fixes.isCurrentSpell);
		}

		if (this->fixes.leftHandPowerAttacks)
		{
			ScrambledBugs::Fixes::LeftHandPowerAttacks::Fix(this->fixes.leftHandPowerAttacks);
		}

		if (this->fixes.magicEffectFlags)
		{
			ScrambledBugs::Fixes::MagicEffectFlags::Fix(this->fixes.magicEffectFlags);
		}

		if (this->fixes.modifyArmorWeightPerkEntryPoint)
		{
			ScrambledBugs::Fixes::ModifyArmorWeightPerkEntryPoint::Fix(this->fixes.modifyArmorWeightPerkEntryPoint);
		}

		if (this->fixes.openEffectArchetype)
		{
			ScrambledBugs::Fixes::OpenEffectArchetype::Fix(this->fixes.openEffectArchetype);
		}

		if (this->fixes.powerCooldowns)
		{
			ScrambledBugs::Fixes::PowerCooldowns::Fix(this->fixes.powerCooldowns);
		}

		if (this->fixes.projectileFadeDuration)
		{
			ScrambledBugs::Fixes::ProjectileFadeDuration::Fix(this->fixes.projectileFadeDuration);
		}

		if (this->fixes.terrainImpactEffects)
		{
			ScrambledBugs::Fixes::TerrainImpactEffects::Fix(this->fixes.terrainImpactEffects);
		}

		if (this->fixes.trainingMenu)
		{
			ScrambledBugs::Fixes::TrainingMenu::Fix(this->fixes.trainingMenu);
		}

		if (this->fixes.weaponCharge)
		{
			ScrambledBugs::Fixes::WeaponCharge::Fix(this->fixes.weaponCharge);
		}

		if (this->patches.difficultyMultipliers.commandedActors || this->patches.difficultyMultipliers.teammates)
		{
			ScrambledBugs::Patches::DifficultyMultipliers::Patch(this->patches.difficultyMultipliers.commandedActors, this->patches.difficultyMultipliers.teammates);
		}

		if (this->patches.perkEntryPoints.applySpells)
		{
			ScrambledBugs::Patches::PerkEntryPoints::ApplySpells::Patch(this->patches.perkEntryPoints.applySpells, this->patches.perkEntryPoints.castSpells);
		}
		else if (this->patches.perkEntryPoints.castSpells)
		{
			ScrambledBugs::Patches::PerkEntryPoints::CastSpells::Patch(this->patches.perkEntryPoints.castSpells);
		}

		if (this->patches.soulGems.black || this->patches.soulGems.underfilled)
		{
			ScrambledBugs::Patches::SoulGems::Patch(this->patches.soulGems.black, this->patches.soulGems.underfilled);
		}

		if (this->patches.staffExperience.staffExperience)
		{
			ScrambledBugs::Patches::StaffExperience::Patch(this->patches.staffExperience.staffExperience, this->patches.staffExperience.ignoreEnchantmentCost);
		}

		if (this->patches.accumulatingMagnitude)
		{
			ScrambledBugs::Patches::AccumulatingMagnitude::Patch(this->patches.accumulatingMagnitude);
		}

		if (this->patches.alreadyCaughtPickpocketing)
		{
			ScrambledBugs::Patches::AlreadyCaughtPickpocketing::Patch(this->patches.alreadyCaughtPickpocketing);
		}

		if (this->patches.attachHitEffectArt)
		{
			ScrambledBugs::Patches::AttachHitEffectArt::Patch(this->patches.attachHitEffectArt);
		}

		if (this->patches.cloakHitEffects)
		{
			ScrambledBugs::Patches::CloakHitEffects::Patch(this->patches.cloakHitEffects);
		}

		if (this->patches.deferredHitEffects)
		{
			ScrambledBugs::Patches::DeferredHitEffects::Patch(this->patches.deferredHitEffects);
		}

		if (this->patches.equipBestAmmunition)
		{
			ScrambledBugs::Patches::EquipBestAmmunition::Patch(this->patches.equipBestAmmunition);
		}

		if (this->patches.leveledCharacters)
		{
			ScrambledBugs::Patches::LeveledCharacters::Patch(this->patches.leveledCharacters);
		}

		if (this->patches.lockpickingExperience)
		{
			ScrambledBugs::Patches::LockpickingExperience::Patch(this->patches.lockpickingExperience);
		}

		if (this->patches.poisonResistance)
		{
			ScrambledBugs::Patches::PoisonResistance::Patch(this->patches.poisonResistance);
		}

		if (this->patches.powerAttackStamina)
		{
			ScrambledBugs::Patches::PowerAttackStamina::Patch(this->patches.powerAttackStamina);
		}

		if (this->patches.reflectDamage)
		{
			ScrambledBugs::Patches::ReflectDamage::Patch(this->patches.reflectDamage);
		}

		if (this->patches.scrollExperience)
		{
			ScrambledBugs::Patches::ScrollExperience::Patch(this->patches.scrollExperience);
		}

		if (this->patches.steepSlopes)
		{
			ScrambledBugs::Patches::SteepSlopes::Patch(this->patches.steepSlopes);
		}

		SPDLOG_INFO("Loaded.\n{}", this->Serialize().dump(1, '\t'));
	}

	void Settings::PostLoad()
	{
		SPDLOG_INFO("Post Loading...\n{}", this->Serialize().dump(1, '\t'));

		// Must be fixed after the Perk Entry Points: Apply Spells fix
		if (this->fixes.killCamera)
		{
			ScrambledBugs::Fixes::KillCamera::Fix(this->fixes.killCamera);
		}

		// Must be patched after the Conditions Target Magic Effects plugin
		if (this->patches.enchantmentEffectPower)
		{
			ScrambledBugs::Patches::EnchantmentEffectPower::Patch(this->patches.enchantmentEffectPower);
		}

		SPDLOG_INFO("Post Loaded.\n{}", this->Serialize().dump(1, '\t'));
	}
}
