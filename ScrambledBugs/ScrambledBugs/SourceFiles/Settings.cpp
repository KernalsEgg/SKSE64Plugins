#include "PCH.h"

#include "Settings.h"

#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Log.h"



namespace ScrambledBugs
{
	void Settings::Fixes::Deserialize(const json& fixes)
	{
		if (fixes.contains("activateFurniture"))
		{
			fixes.at("activateFurniture").get_to(this->activateFurniture);
		}

		if (fixes.contains("actorValuePercentage"))
		{
			fixes.at("actorValuePercentage").get_to(this->actorValuePercentage);
		}

		if (fixes.contains("enchantmentCost"))
		{
			fixes.at("enchantmentCost").get_to(this->enchantmentCost);
		}

		if (fixes.contains("harvestedFlags"))
		{
			fixes.at("harvestedFlags").get_to(this->harvestedFlags);
		}

		if (fixes.contains("hitEffectRaceCondition"))
		{
			fixes.at("hitEffectRaceCondition").get_to(this->hitEffectRaceCondition);
		}

		if (fixes.contains("impactEffectCrash"))
		{
			fixes.at("impactEffectCrash").get_to(this->impactEffectCrash);
		}

		if (fixes.contains("killCamera"))
		{
			fixes.at("killCamera").get_to(this->killCamera);
		}

		if (fixes.contains("magicEffectFlags"))
		{
			fixes.at("magicEffectFlags").get_to(this->magicEffectFlags);
		}

		if (fixes.contains("modArmorWeightPerkEntryPoint"))
		{
			fixes.at("modArmorWeightPerkEntryPoint").get_to(this->modArmorWeightPerkEntryPoint);
		}

		if (fixes.contains("quickShot"))
		{
			fixes.at("quickShot").get_to(this->quickShot);
		}

		if (fixes.contains("quickShotPlaybackSpeed"))
		{
			fixes.at("quickShotPlaybackSpeed").get_to(this->quickShotPlaybackSpeed);
		}

		if (fixes.contains("terrainDecals"))
		{
			fixes.at("terrainDecals").get_to(this->terrainDecals);
		}

		if (fixes.contains("trainingMenu"))
		{
			fixes.at("trainingMenu").get_to(this->trainingMenu);
		}

		if (fixes.contains("weaponCharge"))
		{
			fixes.at("weaponCharge").get_to(this->weaponCharge);
		}
	}

	json Settings::Fixes::Serialize() const
	{
		json fixes;

		fixes["activateFurniture"]            = this->activateFurniture;
		fixes["actorValuePercentage"]         = this->actorValuePercentage;
		fixes["enchantmentCost"]              = this->enchantmentCost;
		fixes["harvestedFlags"]               = this->harvestedFlags;
		fixes["hitEffectRaceCondition"]       = this->hitEffectRaceCondition;
		fixes["impactEffectCrash"]            = this->impactEffectCrash;
		fixes["killCamera"]                   = this->killCamera;
		fixes["magicEffectFlags"]             = this->magicEffectFlags;
		fixes["modArmorWeightPerkEntryPoint"] = this->modArmorWeightPerkEntryPoint;
		fixes["quickShot"]                    = this->quickShot;
		fixes["quickShotPlaybackSpeed"]       = this->quickShotPlaybackSpeed;
		fixes["terrainDecals"]                = this->terrainDecals;
		fixes["trainingMenu"]                 = this->trainingMenu;
		fixes["weaponCharge"]                 = this->weaponCharge;

		return fixes;
	}

	void Settings::Patches::PerkEntryPoints::Deserialize(const json& perkEntryPoints)
	{
		if (perkEntryPoints.contains("applyMultipleSpells"))
		{
			perkEntryPoints.at("applyMultipleSpells").get_to(this->applyMultipleSpells);
		}

		if (perkEntryPoints.contains("castSpells"))
		{
			perkEntryPoints.at("castSpells").get_to(this->castSpells);
		}
	}

	json Settings::Patches::PerkEntryPoints::Serialize() const
	{
		json perkEntryPoints;

		perkEntryPoints["applyMultipleSpells"] = this->applyMultipleSpells;
		perkEntryPoints["castSpells"]          = this->castSpells;

		return perkEntryPoints;
	}

	void Settings::Patches::Deserialize(const json& patches)
	{
		if (patches.contains("accumulatingMagnitude"))
		{
			patches.at("accumulatingMagnitude").get_to(this->accumulatingMagnitude);
		}

		if (patches.contains("alreadyCaughtPickpocketing"))
		{
			patches.at("alreadyCaughtPickpocketing").get_to(this->alreadyCaughtPickpocketing);
		}

		if (patches.contains("attachHitEffectArt"))
		{
			patches.at("attachHitEffectArt").get_to(this->attachHitEffectArt);
		}

		if (patches.contains("cloakHitEffects"))
		{
			patches.at("cloakHitEffects").get_to(this->cloakHitEffects);
		}

		if (patches.contains("equipBestAmmo"))
		{
			patches.at("equipBestAmmo").get_to(this->equipBestAmmo);
		}

		if (patches.contains("improveMultipleEnchantmentEffects"))
		{
			patches.at("improveMultipleEnchantmentEffects").get_to(this->improveMultipleEnchantmentEffects);
		}

		if (patches.contains("leveledCharacters"))
		{
			patches.at("leveledCharacters").get_to(this->leveledCharacters);
		}

		if (patches.contains("lockpickingExperience"))
		{
			patches.at("lockpickingExperience").get_to(this->lockpickingExperience);
		}

		if (patches.contains("pausedGameHitEffects"))
		{
			patches.at("pausedGameHitEffects").get_to(this->pausedGameHitEffects);
		}

		if (patches.contains("perkEntryPoints"))
		{
			this->perkEntryPoints.Deserialize(patches.at("perkEntryPoints"));
		}

		if (patches.contains("poisonResistance"))
		{
			patches.at("poisonResistance").get_to(this->poisonResistance);
		}

		if (patches.contains("powerAttackStamina"))
		{
			patches.at("powerAttackStamina").get_to(this->powerAttackStamina);
		}

		if (patches.contains("reflectDamage"))
		{
			patches.at("reflectDamage").get_to(this->reflectDamage);
		}

		if (patches.contains("scrollExperience"))
		{
			patches.at("scrollExperience").get_to(this->scrollExperience);
		}

		if (patches.contains("staffExperience"))
		{
			patches.at("staffExperience").get_to(this->staffExperience);
		}

		if (patches.contains("steepSlopes"))
		{
			patches.at("steepSlopes").get_to(this->steepSlopes);
		}

		if (patches.contains("teammateDifficulty"))
		{
			patches.at("teammateDifficulty").get_to(this->teammateDifficulty);
		}

		if (patches.contains("underfilledSoulGems"))
		{
			patches.at("underfilledSoulGems").get_to(this->underfilledSoulGems);
		}
	}

	json Settings::Patches::Serialize() const
	{
		json patches;

		patches["accumulatingMagnitude"]             = this->accumulatingMagnitude;
		patches["alreadyCaughtPickpocketing"]        = this->alreadyCaughtPickpocketing;
		patches["attachHitEffectArt"]                = this->attachHitEffectArt;
		patches["cloakHitEffects"]                   = this->cloakHitEffects;
		patches["equipBestAmmo"]                     = this->equipBestAmmo;
		patches["improveMultipleEnchantmentEffects"] = this->improveMultipleEnchantmentEffects;
		patches["leveledCharacters"]                 = this->leveledCharacters;
		patches["lockpickingExperience"]             = this->lockpickingExperience;
		patches["pausedGameHitEffects"]              = this->pausedGameHitEffects;
		patches["perkEntryPoints"]                   = this->perkEntryPoints.Serialize();
		patches["poisonResistance"]                  = this->poisonResistance;
		patches["powerAttackStamina"]                = this->powerAttackStamina;
		patches["reflectDamage"]                     = this->reflectDamage;
		patches["scrollExperience"]                  = this->scrollExperience;
		patches["staffExperience"]                   = this->staffExperience;
		patches["steepSlopes"]                       = this->steepSlopes;
		patches["teammateDifficulty"]                = this->teammateDifficulty;
		patches["underfilledSoulGems"]               = this->underfilledSoulGems;

		return patches;
	}

	Settings::Settings(const std::filesystem::path& path)
	{
		try
		{
			this->Deserialize(json::parse(std::ifstream(path), nullptr, true, true));
		}
		catch (const json::exception& exception)
		{
			Utility::Log::Error(exception.what());
		}
	}

	Settings& Settings::GetSingleton()
	{
		static Settings singleton(std::filesystem::path(Relocation::Plugin::GetSingleton().GetPath()).replace_extension("json"));

		return singleton;
	}

	void Settings::Deserialize(const json& settings)
	{
		if (settings.contains("fixes"))
		{
			this->fixes.Deserialize(settings.at("fixes"));
		}

		if (settings.contains("patches"))
		{
			this->patches.Deserialize(settings.at("patches"));
		}
	}

	json Settings::Serialize() const
	{
		json settings;

		settings["fixes"]   = this->fixes.Serialize();
		settings["patches"] = this->patches.Serialize();

		return settings;
	}
}
