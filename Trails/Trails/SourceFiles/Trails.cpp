#include "PCH.h"

#include "Events.h"
#include "Settings.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Skyrim/B/BGSFootstepManager.h"
#include "Shared/Skyrim/Events.h"
#include "Shared/Utility/Log.h"



void OnInitializeThread()
{
	Utility::Log::Information("\n{}", Trails::Settings::GetSingleton().Serialize().dump(4));

	Skyrim::BGSFootstepManager::GetSingleton()->AddEventSink(Trails::Events::FootstepEventSink::GetSingleton());
}

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInfo* pluginInfo)
{
	pluginInfo->infoVersion = SKSE::PluginInfo::kVersion;
	pluginInfo->name        = "Trails";
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
	.pluginName     = "Trails",
	.author         = "KernalsEgg and SparrowPrince",
	.addressLibrary = true
};

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Cache::GetSingleton().Initialize(loadInterface);

	Skyrim::Events::InitializeThread::GetSingleton().After().AddEventSink(OnInitializeThread);

	return true;
}
