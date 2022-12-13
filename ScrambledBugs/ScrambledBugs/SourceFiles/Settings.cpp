#include "PrecompiledHeader.h"

#include "Settings.h"

#include "Fixes/ActivateFurniture.h"
#include "Fixes/ActorValuePercentage.h"
#include "Fixes/EnchantmentCost.h"
#include "Fixes/HarvestedFlags.h"
#include "Fixes/HitEffectRaceCondition.h"
#include "Fixes/ImpactEffectCrash.h"
#include "Fixes/KillCamera.h"
#include "Fixes/LeftHandPowerAttacks.h"
#include "Fixes/MagicEffectFlags.h"
#include "Fixes/ModifyArmorWeightPerkEntryPoint.h"
#include "Fixes/PowerCooldowns.h"
#include "Fixes/ProjectileFadeDuration.h"
#include "Fixes/QuickShot.h"
#include "Fixes/TerrainDecals.h"
#include "Fixes/TrainingMenu.h"
#include "Fixes/WeaponCharge.h"
#include "Patches/AccumulatingMagnitude.h"
#include "Patches/AlreadyCaughtPickpocketing.h"
#include "Patches/AttachHitEffectArt.h"
#include "Patches/CloakHitEffects.h"
#include "Patches/DifficultyMultipliers.h"
#include "Patches/EquipBestAmmunition.h"
#include "Patches/ImproveMultipleEnchantmentEffects.h"
#include "Patches/LeveledCharacters.h"
#include "Patches/LockpickingExperience.h"
#include "Patches/PausedGameHitEffects.h"
#include "Patches/PerkEntryPoints/ApplyMultipleSpells.h"
#include "Patches/PerkEntryPoints/CastSpells.h"
#include "Patches/PoisonResistance.h"
#include "Patches/PowerAttackStamina.h"
#include "Patches/ReflectDamage.h"
#include "Patches/ScrollExperience.h"
#include "Patches/SoulGems.h"
#include "Patches/StaffExperience.h"
#include "Patches/SteepSlopes.h"
#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Log.h"



namespace ScrambledBugs
{
	Settings::Fixes& Settings::Fixes::Deserialize(const nlohmann::json& jsonFixes)
	{
		if (jsonFixes.contains("activateFurniture"))
		{
			jsonFixes.at("activateFurniture").get_to(this->activateFurniture);
		}

		if (jsonFixes.contains("actorValuePercentage"))
		{
			jsonFixes.at("actorValuePercentage").get_to(this->actorValuePercentage);
		}

		if (jsonFixes.contains("enchantmentCost"))
		{
			jsonFixes.at("enchantmentCost").get_to(this->enchantmentCost);
		}

		if (jsonFixes.contains("harvestedFlags"))
		{
			jsonFixes.at("harvestedFlags").get_to(this->harvestedFlags);
		}

		if (jsonFixes.contains("hitEffectRaceCondition"))
		{
			jsonFixes.at("hitEffectRaceCondition").get_to(this->hitEffectRaceCondition);
		}

		if (jsonFixes.contains("impactEffectCrash"))
		{
			jsonFixes.at("impactEffectCrash").get_to(this->impactEffectCrash);
		}

		if (jsonFixes.contains("killCamera"))
		{
			jsonFixes.at("killCamera").get_to(this->killCamera);
		}

		if (jsonFixes.contains("leftHandPowerAttacks"))
		{
			jsonFixes.at("leftHandPowerAttacks").get_to(this->leftHandPowerAttacks);
		}

		if (jsonFixes.contains("magicEffectFlags"))
		{
			jsonFixes.at("magicEffectFlags").get_to(this->magicEffectFlags);
		}

		if (jsonFixes.contains("modifyArmorWeightPerkEntryPoint"))
		{
			jsonFixes.at("modifyArmorWeightPerkEntryPoint").get_to(this->modifyArmorWeightPerkEntryPoint);
		}

		if (jsonFixes.contains("powerCooldowns"))
		{
			jsonFixes.at("powerCooldowns").get_to(this->powerCooldowns);
		}

		if (jsonFixes.contains("projectileFadeDuration"))
		{
			jsonFixes.at("projectileFadeDuration").get_to(this->projectileFadeDuration);
		}

		if (jsonFixes.contains("quickShot"))
		{
			jsonFixes.at("quickShot").get_to(this->quickShot);
		}

		if (jsonFixes.contains("quickShotPlaybackSpeed"))
		{
			jsonFixes.at("quickShotPlaybackSpeed").get_to(this->quickShotPlaybackSpeed);
		}

		if (jsonFixes.contains("terrainDecals"))
		{
			jsonFixes.at("terrainDecals").get_to(this->terrainDecals);
		}

		if (jsonFixes.contains("trainingMenu"))
		{
			jsonFixes.at("trainingMenu").get_to(this->trainingMenu);
		}

		if (jsonFixes.contains("weaponCharge"))
		{
			jsonFixes.at("weaponCharge").get_to(this->weaponCharge);
		}

		return *this;
	}

	nlohmann::json Settings::Fixes::Serialize() const
	{
		nlohmann::json jsonFixes;

		jsonFixes["activateFurniture"]               = this->activateFurniture;
		jsonFixes["actorValuePercentage"]            = this->actorValuePercentage;
		jsonFixes["enchantmentCost"]                 = this->enchantmentCost;
		jsonFixes["harvestedFlags"]                  = this->harvestedFlags;
		jsonFixes["hitEffectRaceCondition"]          = this->hitEffectRaceCondition;
		jsonFixes["impactEffectCrash"]               = this->impactEffectCrash;
		jsonFixes["killCamera"]                      = this->killCamera;
		jsonFixes["leftHandPowerAttacks"]            = this->leftHandPowerAttacks;
		jsonFixes["magicEffectFlags"]                = this->magicEffectFlags;
		jsonFixes["modifyArmorWeightPerkEntryPoint"] = this->modifyArmorWeightPerkEntryPoint;
		jsonFixes["powerCooldowns"]                  = this->powerCooldowns;
		jsonFixes["projectileFadeDuration"]          = this->projectileFadeDuration;
		jsonFixes["quickShot"]                       = this->quickShot;
		jsonFixes["quickShotPlaybackSpeed"]          = this->quickShotPlaybackSpeed;
		jsonFixes["terrainDecals"]                   = this->terrainDecals;
		jsonFixes["trainingMenu"]                    = this->trainingMenu;
		jsonFixes["weaponCharge"]                    = this->weaponCharge;

		return jsonFixes;
	}

	Settings::Patches::DifficultyMultipliers& Settings::Patches::DifficultyMultipliers::Deserialize(const nlohmann::json& jsonDifficultyMultipliers)
	{
		if (jsonDifficultyMultipliers.contains("commandedActors"))
		{
			jsonDifficultyMultipliers.at("commandedActors").get_to(this->commandedActors);
		}

		if (jsonDifficultyMultipliers.contains("teammates"))
		{
			jsonDifficultyMultipliers.at("teammates").get_to(this->teammates);
		}

		return *this;
	}

	nlohmann::json Settings::Patches::DifficultyMultipliers::Serialize() const
	{
		nlohmann::json jsonDifficultyMultipliers;

		jsonDifficultyMultipliers["commandedActors"] = this->commandedActors;
		jsonDifficultyMultipliers["teammates"]       = this->teammates;

		return jsonDifficultyMultipliers;
	}

	Settings::Patches::PerkEntryPoints& Settings::Patches::PerkEntryPoints::Deserialize(const nlohmann::json& jsonPerkEntryPoints)
	{
		if (jsonPerkEntryPoints.contains("applyMultipleSpells"))
		{
			jsonPerkEntryPoints.at("applyMultipleSpells").get_to(this->applyMultipleSpells);
		}

		if (jsonPerkEntryPoints.contains("castSpells"))
		{
			jsonPerkEntryPoints.at("castSpells").get_to(this->castSpells);
		}

		return *this;
	}

	nlohmann::json Settings::Patches::PerkEntryPoints::Serialize() const
	{
		nlohmann::json jsonPerkEntryPoints;

		jsonPerkEntryPoints["applyMultipleSpells"] = this->applyMultipleSpells;
		jsonPerkEntryPoints["castSpells"]          = this->castSpells;

		return jsonPerkEntryPoints;
	}

	Settings::Patches::SoulGems& Settings::Patches::SoulGems::Deserialize(const nlohmann::json& jsonSoulGems)
	{
		if (jsonSoulGems.contains("black"))
		{
			jsonSoulGems.at("black").get_to(this->black);
		}

		if (jsonSoulGems.contains("underfilled"))
		{
			jsonSoulGems.at("underfilled").get_to(this->underfilled);
		}

		return *this;
	}

	nlohmann::json Settings::Patches::SoulGems::Serialize() const
	{
		nlohmann::json jsonSoulGems;

		jsonSoulGems["black"]       = this->black;
		jsonSoulGems["underfilled"] = this->underfilled;

		return jsonSoulGems;
	}

	Settings::Patches& Settings::Patches::Deserialize(const nlohmann::json& jsonPatches)
	{
		if (jsonPatches.contains("accumulatingMagnitude"))
		{
			jsonPatches.at("accumulatingMagnitude").get_to(this->accumulatingMagnitude);
		}

		if (jsonPatches.contains("alreadyCaughtPickpocketing"))
		{
			jsonPatches.at("alreadyCaughtPickpocketing").get_to(this->alreadyCaughtPickpocketing);
		}

		if (jsonPatches.contains("attachHitEffectArt"))
		{
			jsonPatches.at("attachHitEffectArt").get_to(this->attachHitEffectArt);
		}

		if (jsonPatches.contains("cloakHitEffects"))
		{
			jsonPatches.at("cloakHitEffects").get_to(this->cloakHitEffects);
		}

		if (jsonPatches.contains("difficultyMultipliers"))
		{
			this->difficultyMultipliers.Deserialize(jsonPatches.at("difficultyMultipliers"));
		}

		if (jsonPatches.contains("equipBestAmmunition"))
		{
			jsonPatches.at("equipBestAmmunition").get_to(this->equipBestAmmunition);
		}

		if (jsonPatches.contains("improveMultipleEnchantmentEffects"))
		{
			jsonPatches.at("improveMultipleEnchantmentEffects").get_to(this->improveMultipleEnchantmentEffects);
		}

		if (jsonPatches.contains("leveledCharacters"))
		{
			jsonPatches.at("leveledCharacters").get_to(this->leveledCharacters);
		}

		if (jsonPatches.contains("lockpickingExperience"))
		{
			jsonPatches.at("lockpickingExperience").get_to(this->lockpickingExperience);
		}

		if (jsonPatches.contains("pausedGameHitEffects"))
		{
			jsonPatches.at("pausedGameHitEffects").get_to(this->pausedGameHitEffects);
		}

		if (jsonPatches.contains("perkEntryPoints"))
		{
			this->perkEntryPoints.Deserialize(jsonPatches.at("perkEntryPoints"));
		}

		if (jsonPatches.contains("poisonResistance"))
		{
			jsonPatches.at("poisonResistance").get_to(this->poisonResistance);
		}

		if (jsonPatches.contains("powerAttackStamina"))
		{
			jsonPatches.at("powerAttackStamina").get_to(this->powerAttackStamina);
		}

		if (jsonPatches.contains("reflectDamage"))
		{
			jsonPatches.at("reflectDamage").get_to(this->reflectDamage);
		}

		if (jsonPatches.contains("scrollExperience"))
		{
			jsonPatches.at("scrollExperience").get_to(this->scrollExperience);
		}

		if (jsonPatches.contains("soulGems"))
		{
			this->soulGems.Deserialize(jsonPatches.at("soulGems"));
		}

		if (jsonPatches.contains("staffExperience"))
		{
			jsonPatches.at("staffExperience").get_to(this->staffExperience);
		}

		if (jsonPatches.contains("steepSlopes"))
		{
			jsonPatches.at("steepSlopes").get_to(this->steepSlopes);
		}

		return *this;
	}

	nlohmann::json Settings::Patches::Serialize() const
	{
		nlohmann::json jsonPatches;

		jsonPatches["accumulatingMagnitude"]             = this->accumulatingMagnitude;
		jsonPatches["alreadyCaughtPickpocketing"]        = this->alreadyCaughtPickpocketing;
		jsonPatches["attachHitEffectArt"]                = this->attachHitEffectArt;
		jsonPatches["cloakHitEffects"]                   = this->cloakHitEffects;
		jsonPatches["difficultyMultipliers"]             = this->difficultyMultipliers.Serialize();
		jsonPatches["equipBestAmmunition"]               = this->equipBestAmmunition;
		jsonPatches["improveMultipleEnchantmentEffects"] = this->improveMultipleEnchantmentEffects;
		jsonPatches["leveledCharacters"]                 = this->leveledCharacters;
		jsonPatches["lockpickingExperience"]             = this->lockpickingExperience;
		jsonPatches["pausedGameHitEffects"]              = this->pausedGameHitEffects;
		jsonPatches["perkEntryPoints"]                   = this->perkEntryPoints.Serialize();
		jsonPatches["poisonResistance"]                  = this->poisonResistance;
		jsonPatches["powerAttackStamina"]                = this->powerAttackStamina;
		jsonPatches["reflectDamage"]                     = this->reflectDamage;
		jsonPatches["scrollExperience"]                  = this->scrollExperience;
		jsonPatches["soulGems"]                          = this->soulGems.Serialize();
		jsonPatches["staffExperience"]                   = this->staffExperience;
		jsonPatches["steepSlopes"]                       = this->steepSlopes;

		return jsonPatches;
	}

	Settings::Settings(const std::filesystem::path& path)
	{
		try
		{
			this->Deserialize(nlohmann::json::parse(std::ifstream(path), nullptr, true, true));
		}
		catch (const nlohmann::json::exception& jsonException)
		{
			Utility::Log::Critical("{}", jsonException.what());

			throw;
		}
	}

	Settings& Settings::GetSingleton()
	{
		static Settings singleton(std::filesystem::path(Relocation::DynamicLinkLibrary::GetSingleton().GetPath()).replace_extension("json"));

		return singleton;
	}

	Settings& Settings::Deserialize(const nlohmann::json& jsonSettings)
	{
		if (jsonSettings.contains("fixes"))
		{
			this->fixes.Deserialize(jsonSettings.at("fixes"));
		}

		if (jsonSettings.contains("patches"))
		{
			this->patches.Deserialize(jsonSettings.at("patches"));
		}

		return *this;
	}

	void Settings::Initialize()
	{
		Utility::Log::Information("Initializing...\n{}", this->Serialize().dump(1, '\t'));

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

		if (this->fixes.harvestedFlags)
		{
			ScrambledBugs::Fixes::HarvestedFlags::Fix(this->fixes.harvestedFlags);
		}

		if (this->fixes.hitEffectRaceCondition)
		{
			ScrambledBugs::Fixes::HitEffectRaceCondition::Fix(this->fixes.hitEffectRaceCondition);
		}

		if (this->fixes.impactEffectCrash)
		{
			ScrambledBugs::Fixes::ImpactEffectCrash::Fix(this->fixes.impactEffectCrash);
		}

		if (this->fixes.killCamera)
		{
			ScrambledBugs::Fixes::KillCamera::Fix(this->fixes.killCamera);
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

		if (this->fixes.powerCooldowns)
		{
			ScrambledBugs::Fixes::PowerCooldowns::Fix(this->fixes.powerCooldowns);
		}

		if (this->fixes.projectileFadeDuration)
		{
			ScrambledBugs::Fixes::ProjectileFadeDuration::Fix(this->fixes.projectileFadeDuration);
		}

		if (this->fixes.quickShot && this->fixes.quickShotPlaybackSpeed > 0.0F)
		{
			ScrambledBugs::Fixes::QuickShot::Fix(this->fixes.quickShot, this->fixes.quickShotPlaybackSpeed);
		}

		if (this->fixes.terrainDecals)
		{
			ScrambledBugs::Fixes::TerrainDecals::Fix(this->fixes.terrainDecals);
		}

		if (this->fixes.trainingMenu)
		{
			ScrambledBugs::Fixes::TrainingMenu::Fix(this->fixes.trainingMenu);
		}

		if (this->fixes.weaponCharge)
		{
			ScrambledBugs::Fixes::WeaponCharge::Fix(this->fixes.weaponCharge);
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

		if (this->patches.difficultyMultipliers.commandedActors || this->patches.difficultyMultipliers.teammates)
		{
			ScrambledBugs::Patches::DifficultyMultipliers::Patch(this->patches.difficultyMultipliers.commandedActors, this->patches.difficultyMultipliers.teammates);
		}

		if (this->patches.equipBestAmmunition)
		{
			ScrambledBugs::Patches::EquipBestAmmunition::Patch(this->patches.equipBestAmmunition);
		}

		if (this->patches.improveMultipleEnchantmentEffects)
		{
			ScrambledBugs::Patches::ImproveMultipleEnchantmentEffects::Patch(this->patches.improveMultipleEnchantmentEffects);
		}

		if (this->patches.leveledCharacters)
		{
			ScrambledBugs::Patches::LeveledCharacters::Patch(this->patches.leveledCharacters);
		}

		if (this->patches.lockpickingExperience)
		{
			ScrambledBugs::Patches::LockpickingExperience::Patch(this->patches.lockpickingExperience);
		}

		if (this->patches.pausedGameHitEffects)
		{
			ScrambledBugs::Patches::PausedGameHitEffects::Patch(this->patches.pausedGameHitEffects);
		}

		if (this->patches.perkEntryPoints.applyMultipleSpells)
		{
			ScrambledBugs::Patches::PerkEntryPoints::ApplyMultipleSpells::Patch(this->patches.perkEntryPoints.applyMultipleSpells, this->patches.perkEntryPoints.castSpells);
		}
		else if (this->patches.perkEntryPoints.castSpells)
		{
			ScrambledBugs::Patches::PerkEntryPoints::CastSpells::Patch(this->patches.perkEntryPoints.castSpells);
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

		if (this->patches.soulGems.black || this->patches.soulGems.underfilled)
		{
			ScrambledBugs::Patches::SoulGems::Patch(this->patches.soulGems.black, this->patches.soulGems.underfilled);
		}

		if (this->patches.staffExperience)
		{
			ScrambledBugs::Patches::StaffExperience::Patch(this->patches.staffExperience);
		}

		if (this->patches.steepSlopes)
		{
			ScrambledBugs::Patches::SteepSlopes::Patch(this->patches.steepSlopes);
		}

		Utility::Log::Information("Initialized.\n{}", this->Serialize().dump(1, '\t'));
	}

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json jsonSettings;

		jsonSettings["fixes"]   = this->fixes.Serialize();
		jsonSettings["patches"] = this->patches.Serialize();

		return jsonSettings;
	}
}
