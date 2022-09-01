#include "PCH.h"

#include "Events.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Trampoline.h"



extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInformation* pluginInformation)
{
	pluginInformation->informationVersion = SKSE::PluginInformation::kVersion;
	pluginInformation->name               = "Barter Limit Fix";
	pluginInformation->version            = 1;

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
	.pluginName     = "Barter Limit Fix",
	.author         = "KernalsEgg",
	.addressLibrary = true
};

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Cache::GetSingleton().Initialize(loadInterface);

	Utility::Log::Information("Registered: {}", BarterLimitFix::Events::Register());

	Utility::Trampoline::GetSingleton().Commit();

	return true;
}
