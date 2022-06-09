#include "PCH.h"

#include "Hooks.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Utility/Log.h"



extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInfo* pluginInfo)
{
	pluginInfo->infoVersion = SKSE::PluginInfo::kVersion;
	pluginInfo->name        = "Actor Base Perk Fix";
	pluginInfo->version     = 1;

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

extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion  = 1,
	.pluginName     = "Actor Base Perk Fix",
	.author         = "KernalsEgg",
	.addressLibrary = true
};

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Cache::GetSingleton().Initialize(loadInterface);

	ActorBasePerkFix::Hooks::Install();

	return true;
}
