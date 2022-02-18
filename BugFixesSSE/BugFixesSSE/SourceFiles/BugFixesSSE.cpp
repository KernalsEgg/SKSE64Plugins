#include "PCH.h"

#include "Fixes/MagicEffectConditions.h"
#include "Fixes/SpeechExperience/EnchantedItems.h"
#include "Fixes/SpeechExperience/ItemStacks.h"
#include "Fixes/SpeedMultUpdates.h"
#include "Settings.h"
#include "Shared/Relocation/Module.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Trampoline.h"



void Settings()
{
	auto& settings = BugFixesSSE::Settings::GetSingleton();

	Utility::Log::Information("Initializing...\n{}", settings.Serialize().dump(1, '\t'));

	if (settings.fixes.magicEffectConditions)
	{
		settings.fixes.magicEffectConditions = BugFixesSSE::Fixes::MagicEffectConditions::Fix();
	}

	if (settings.fixes.speechExperience.enchantedItems)
	{
		settings.fixes.speechExperience.enchantedItems = BugFixesSSE::Fixes::SpeechExperience::EnchantedItems::Fix();
	}

	// Must be installed after BugFixesSSE::Fixes::Speechcraft::EnchantedItems
	if (settings.fixes.speechExperience.itemStacks)
	{
		settings.fixes.speechExperience.itemStacks = BugFixesSSE::Fixes::SpeechExperience::ItemStacks::Fix();
	}

	if (settings.fixes.speedMultUpdates)
	{
		settings.fixes.speedMultUpdates = BugFixesSSE::Fixes::SpeedMultUpdates::Fix();
	}

	Utility::Log::Information("Initialized.\n{}", settings.Serialize().dump(1, '\t'));

	Utility::Trampoline::GetSingleton().Commit();
}

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInfo* pluginInfo)
{
	static std::string name = Relocation::Plugin::GetSingleton().GetPath().stem().string();

	pluginInfo->infoVersion = SKSE::PluginInfo::kVersion;
	pluginInfo->name        = name.c_str();
	pluginInfo->version     = 4;

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

	return true;
}
