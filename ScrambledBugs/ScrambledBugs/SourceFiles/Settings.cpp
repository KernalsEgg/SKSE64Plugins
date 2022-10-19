#include "PrecompiledHeader.h"

#include "Settings.h"

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
		jsonFixes["quickShot"]                       = this->quickShot;
		jsonFixes["quickShotPlaybackSpeed"]          = this->quickShotPlaybackSpeed;
		jsonFixes["terrainDecals"]                   = this->terrainDecals;
		jsonFixes["trainingMenu"]                    = this->trainingMenu;
		jsonFixes["weaponCharge"]                    = this->weaponCharge;

		return jsonFixes;
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

		if (jsonPatches.contains("blackSoulGems"))
		{
			jsonPatches.at("blackSoulGems").get_to(this->blackSoulGems);
		}

		if (jsonPatches.contains("cloakHitEffects"))
		{
			jsonPatches.at("cloakHitEffects").get_to(this->cloakHitEffects);
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

		if (jsonPatches.contains("staffExperience"))
		{
			jsonPatches.at("staffExperience").get_to(this->staffExperience);
		}

		if (jsonPatches.contains("steepSlopes"))
		{
			jsonPatches.at("steepSlopes").get_to(this->steepSlopes);
		}

		if (jsonPatches.contains("underfilledSoulGems"))
		{
			jsonPatches.at("underfilledSoulGems").get_to(this->underfilledSoulGems);
		}

		return *this;
	}

	nlohmann::json Settings::Patches::Serialize() const
	{
		nlohmann::json jsonPatches;

		jsonPatches["accumulatingMagnitude"]             = this->accumulatingMagnitude;
		jsonPatches["alreadyCaughtPickpocketing"]        = this->alreadyCaughtPickpocketing;
		jsonPatches["attachHitEffectArt"]                = this->attachHitEffectArt;
		jsonPatches["blackSoulGems"]                     = this->blackSoulGems;
		jsonPatches["cloakHitEffects"]                   = this->cloakHitEffects;
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
		jsonPatches["staffExperience"]                   = this->staffExperience;
		jsonPatches["steepSlopes"]                       = this->steepSlopes;
		jsonPatches["underfilledSoulGems"]               = this->underfilledSoulGems;

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

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json jsonSettings;

		jsonSettings["fixes"]   = this->fixes.Serialize();
		jsonSettings["patches"] = this->patches.Serialize();

		return jsonSettings;
	}
}
