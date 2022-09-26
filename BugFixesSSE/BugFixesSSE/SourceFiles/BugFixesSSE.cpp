#include "PrecompiledHeader.h"

#include "Fixes/MagicEffectConditions.h"
#include "Fixes/MovementSpeed.h"
#include "Fixes/SpeechExperience/EnchantedItems.h"
#include "Fixes/SpeechExperience/ItemStacks.h"
#include "Settings.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Trampoline.h"



void Settings()
{
	auto& settings = BugFixesSSE::Settings::GetSingleton();

	Utility::Log::Information("Initializing...\n{}", settings.Serialize().dump(1, '\t'));

	if (settings.fixes.magicEffectConditions)
	{
		BugFixesSSE::Fixes::MagicEffectConditions::Fix(settings.fixes.magicEffectConditions);
	}

	if (settings.fixes.movementSpeed)
	{
		BugFixesSSE::Fixes::MovementSpeed::Fix(settings.fixes.movementSpeed);
	}

	if (settings.fixes.speechExperience.enchantedItems)
	{
		BugFixesSSE::Fixes::SpeechExperience::EnchantedItems::Fix(settings.fixes.speechExperience.enchantedItems);
	}

	// Must be installed after BugFixesSSE::Fixes::Speechcraft::EnchantedItems
	if (settings.fixes.speechExperience.itemStacks)
	{
		BugFixesSSE::Fixes::SpeechExperience::ItemStacks::Fix(settings.fixes.speechExperience.itemStacks);
	}

	Utility::Log::Information("Initialized.\n{}", settings.Serialize().dump(1, '\t'));

	Utility::Trampoline::GetSingleton().Commit();
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 7,
	.pluginName      = "Bug Fixes SSE",
	.author          = "meh321 and KernalsEgg",
	.addressLibrary  = true,
	.compatible16629 = true
};
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Cache::GetSingleton().Initialize(loadInterface);

	Settings();

	return true;
}
