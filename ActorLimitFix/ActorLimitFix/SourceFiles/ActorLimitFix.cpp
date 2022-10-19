#include "PrecompiledHeader.h"

#include "Fixes/MorphLimit.h"
#include "Fixes/MoverLimit.h"
#include "Fixes/ReplaceStaticArray.h"
#include "Settings.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Trampoline.h"



void Settings()
{
	auto& settings = ActorLimitFix::Settings::GetSingleton();

	Utility::Log::Information("Initializing...\n{}", settings.Serialize().dump(1, '\t'));

	if (settings.fixes.replaceStaticArray)
	{
		ActorLimitFix::Fixes::ReplaceStaticArray::Fix(settings.fixes.replaceStaticArray);
	}

	// Must be installed after ActorLimitFix::Fixes::ReplaceStaticArray
	ActorLimitFix::Fixes::MorphLimit::Fix(settings.fixes.morphLimit, settings.fixes.replaceStaticArray);
	ActorLimitFix::Fixes::MoverLimit::Fix(settings.fixes.moverLimit);

	Utility::Log::Information("Initialized.\n{}", settings.Serialize().dump(1, '\t'));

	Utility::Trampoline::GetSingleton().Commit();
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 7,
	.pluginName      = "Actor Limit Fix",
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
