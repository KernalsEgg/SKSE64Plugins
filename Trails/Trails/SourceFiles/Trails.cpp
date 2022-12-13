#include "PrecompiledHeader.h"

#include "Events.h"
#include "Settings.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Skyrim/B/BGSFootstepManager.h"
#include "Shared/Skyrim/Events.h"
#include "Shared/Utility/Log.h"



namespace Trails
{
	void OnInitializeThread()
	{
		Utility::Log::Information("\n{}", Settings::GetSingleton().Serialize().dump(1, '\t'));

		Skyrim::BGSFootstepManager::GetSingleton()->AddEventSink(std::addressof(Events::FootstepEventSink::GetSingleton()));
	}

	bool Initialize()
	{
		Skyrim::Events::InitializeThread::GetSingleton().After().AddEventSink(Trails::OnInitializeThread);

		return true;
	}
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 1,
	.pluginName      = "Trails",
	.author          = "KernalsEgg and SparrowPrince",
	.addressLibrary  = true,
	.compatible16629 = true
};
#else
extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInformation* pluginInformation)
{
	pluginInformation->informationVersion = SKSE::PluginInformation::kVersion;
	pluginInformation->name               = "Trails";
	pluginInformation->version            = 1;

	if (queryInterface->IsEditor())
	{
		Utility::Log::Critical("Loading in editor.");

		return false;
	}

	auto runtimeVersion = queryInterface->RuntimeVersion();

	if (runtimeVersion < Relocation::Version<std::int32_t>(1, 5, 39, 0))
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
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Cache::GetSingleton().Initialize(loadInterface);

	return Trails::Initialize();
}
