#include "PCH.h"

#include "Fixes/ActivateFurniture.h"
#include "Fixes/ActorValuePercentage.h"
#include "Fixes/EnchantmentCost.h"
#include "Fixes/HarvestedFlags.h"
#include "Fixes/HitEffectRaceCondition.h"
#include "Fixes/ImpactEffectCrash.h"
#include "Fixes/KillCamera.h"
#include "Fixes/MagicEffectFlags.h"
#include "Fixes/ModArmorWeightPerkEntryPoint.h"
#include "Fixes/QuickShot.h"
#include "Fixes/TerrainDecals.h"
#include "Fixes/TrainingMenu.h"
#include "Fixes/WeaponCharge.h"
#include "Patches/AccumulatingMagnitude.h"
#include "Patches/AlreadyCaughtPickpocketing.h"
#include "Patches/AttachHitEffectArt.h"
#include "Patches/CloakHitEffects.h"
#include "Patches/EquipBestAmmo.h"
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
#include "Patches/StaffExperience.h"
#include "Patches/TeammateDifficulty.h"
#include "Patches/UnderfilledSoulGems.h"
#include "Serialization.h"
#include "Settings.h"
#include "Shared/Relocation/Module.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Trampoline.h"



void Settings()
{
	auto& settings = ScrambledBugs::Settings::GetSingleton();

	Utility::Log::Information("Initializing...\n{}", settings.Serialize().dump(1, '\t'));

	if (settings.fixes.activateFurniture)
	{
		settings.fixes.activateFurniture = ScrambledBugs::Fixes::ActivateFurniture::Fix();
	}

	if (settings.fixes.actorValuePercentage)
	{
		settings.fixes.actorValuePercentage = ScrambledBugs::Fixes::ActorValuePercentage::Fix();
	}

	if (settings.fixes.enchantmentCost)
	{
		settings.fixes.enchantmentCost = ScrambledBugs::Fixes::EnchantmentCost::Fix();
	}

	if (settings.fixes.harvestedFlags)
	{
		settings.fixes.harvestedFlags = ScrambledBugs::Fixes::HarvestedFlags::Fix();
	}

	if (settings.fixes.hitEffectRaceCondition)
	{
		settings.fixes.hitEffectRaceCondition = ScrambledBugs::Fixes::HitEffectRaceCondition::Fix();
	}

	if (settings.fixes.impactEffectCrash)
	{
		settings.fixes.impactEffectCrash = ScrambledBugs::Fixes::ImpactEffectCrash::Fix();
	}

	if (settings.fixes.killCamera)
	{
		settings.fixes.killCamera = ScrambledBugs::Fixes::KillCamera::Fix();
	}

	if (settings.fixes.magicEffectFlags)
	{
		settings.fixes.magicEffectFlags = ScrambledBugs::Fixes::MagicEffectFlags::Fix();
	}

	if (settings.fixes.modArmorWeightPerkEntryPoint)
	{
		settings.fixes.modArmorWeightPerkEntryPoint = ScrambledBugs::Fixes::ModArmorWeightPerkEntryPoint::Fix();
	}

	if (settings.fixes.quickShot && settings.fixes.quickShotPlaybackSpeed > 0.0F)
	{
		settings.fixes.quickShot = ScrambledBugs::Fixes::QuickShot::Fix(settings.fixes.quickShotPlaybackSpeed);
	}

	if (settings.fixes.terrainDecals)
	{
		settings.fixes.terrainDecals = ScrambledBugs::Fixes::TerrainDecals::Fix();
	}

	if (settings.fixes.trainingMenu)
	{
		settings.fixes.trainingMenu = ScrambledBugs::Fixes::TrainingMenu::Fix();
	}

	if (settings.fixes.weaponCharge)
	{
		settings.fixes.weaponCharge = ScrambledBugs::Fixes::WeaponCharge::Fix();
	}

	if (settings.patches.accumulatingMagnitude)
	{
		settings.patches.accumulatingMagnitude = ScrambledBugs::Patches::AccumulatingMagnitude::Patch();
	}

	if (settings.patches.alreadyCaughtPickpocketing)
	{
		settings.patches.alreadyCaughtPickpocketing = ScrambledBugs::Patches::AlreadyCaughtPickpocketing::Patch();
	}

	if (settings.patches.attachHitEffectArt)
	{
		settings.patches.attachHitEffectArt = ScrambledBugs::Patches::AttachHitEffectArt::Patch();
	}

	if (settings.patches.cloakHitEffects)
	{
		settings.patches.cloakHitEffects = ScrambledBugs::Patches::CloakHitEffects::Patch();
	}

	if (settings.patches.equipBestAmmo)
	{
		settings.patches.equipBestAmmo = ScrambledBugs::Patches::EquipBestAmmo::Patch();
	}

	if (settings.patches.improveMultipleEnchantmentEffects)
	{
		settings.patches.improveMultipleEnchantmentEffects = ScrambledBugs::Patches::ImproveMultipleEnchantmentEffects::Patch();
	}

	if (settings.patches.leveledCharacters)
	{
		settings.patches.leveledCharacters = ScrambledBugs::Patches::LeveledCharacters::Patch();
	}

	if (settings.patches.lockpickingExperience)
	{
		settings.patches.lockpickingExperience = ScrambledBugs::Patches::LockpickingExperience::Patch();
	}

	if (settings.patches.pausedGameHitEffects)
	{
		settings.patches.pausedGameHitEffects = ScrambledBugs::Patches::PausedGameHitEffects::Patch();
	}

	if (settings.patches.perkEntryPoints.applyMultipleSpells)
	{
		settings.patches.perkEntryPoints.applyMultipleSpells = ScrambledBugs::Patches::PerkEntryPoints::ApplyMultipleSpells::Patch(settings.patches.perkEntryPoints.castSpells);
	}
	else if (settings.patches.perkEntryPoints.castSpells)
	{
		settings.patches.perkEntryPoints.castSpells = ScrambledBugs::Patches::PerkEntryPoints::CastSpells::Patch();
	}

	if (settings.patches.poisonResistance)
	{
		settings.patches.poisonResistance = ScrambledBugs::Patches::PoisonResistance::Patch();
	}

	if (settings.patches.powerAttackStamina)
	{
		settings.patches.powerAttackStamina = ScrambledBugs::Patches::PowerAttackStamina::Patch();
	}

	if (settings.patches.reflectDamage)
	{
		settings.patches.reflectDamage = ScrambledBugs::Patches::ReflectDamage::Patch();
	}

	if (settings.patches.scrollExperience)
	{
		settings.patches.scrollExperience = ScrambledBugs::Patches::ScrollExperience::Patch();
	}

	if (settings.patches.staffExperience)
	{
		settings.patches.staffExperience = ScrambledBugs::Patches::StaffExperience::Patch();
	}

	if (settings.patches.teammateDifficulty)
	{
		settings.patches.teammateDifficulty = ScrambledBugs::Patches::TeammateDifficulty::Patch();
	}

	if (settings.patches.underfilledSoulGems)
	{
		settings.patches.underfilledSoulGems = ScrambledBugs::Patches::UnderfilledSoulGems::Patch();
	}

	Utility::Log::Information("Initialized.\n{}", settings.Serialize().dump(1, '\t'));

	Utility::Trampoline::GetSingleton().Commit();
}

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInfo* pluginInfo)
{
	static std::string name = Relocation::Plugin::GetSingleton().GetPath().stem().string();

	pluginInfo->infoVersion = SKSE::PluginInfo::kVersion;
	pluginInfo->name        = name.c_str();
	pluginInfo->version     = 15;

	if (queryInterface->IsEditor())
	{
		Utility::Log::Critical("Loading in editor.");

		return false;
	}

	auto runtimeVersion = queryInterface->RuntimeVersion();

	if (runtimeVersion < Relocation::Version(1, 5, 39, 0))
	{
		Utility::Log::Critical(
			"Unsupported runtime version, {}.{}.{}.{}.",
			runtimeVersion.major,
			runtimeVersion.minor,
			runtimeVersion.revision,
			runtimeVersion.build);

		return false;
	}

	return true;
}

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Cache::GetSingleton().Initialize(loadInterface);

	Settings();

	auto serializationInterface = SKSE::Cache::GetSingleton().GetSerializationInterface();
	serializationInterface->SetUniqueID(ScrambledBugs::Serialization::kUniqueID);
	serializationInterface->SetSaveCallback(std::addressof(ScrambledBugs::Serialization::Save));
	serializationInterface->SetLoadCallback(std::addressof(ScrambledBugs::Serialization::Load));

	return true;
}
