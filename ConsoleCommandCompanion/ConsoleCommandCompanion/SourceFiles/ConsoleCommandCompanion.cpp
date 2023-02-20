#include "PrecompiledHeader.h"

#include "Events.h"
#include "Settings.h"
#include "Shared/Relocation/Version.h"
#include "Shared/Utility/Log.h"

#ifdef SKYRIM_ANNIVERSARY_EDITION
#else
#	include "Patches.h"
#endif



namespace ConsoleCommandCompanion
{
	bool Load()
	{
#ifdef SKYRIM_ANNIVERSARY_EDITION
#else
		if (!Patches::Install())
		{
			Utility::Log::Critical()("Failed to patch Bethesda.net login.");

			return false;
		}
#endif
		Events::InitializeEventSink::RegisterSink();

		Utility::Log::Information()("\n{}", Settings::GetSingleton().Serialize().dump(1, '\t'));

		return true;
	}
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 1,
	.pluginName      = "Console Command Companion",
	.author          = "KernalsEgg",
	.addressLibrary  = true,
	.compatible16629 = true
};
#else
extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInformation* pluginInformation)
{
	pluginInformation->informationVersion = SKSE::PluginInformation::kVersion;
	pluginInformation->name = "Console Command Companion";
	pluginInformation->version = 1;

	if (queryInterface->IsEditor())
	{
		Utility::Log::Critical()("Loading in editor.");

		return false;
	}

	auto runtimeVersion = queryInterface->RuntimeVersion();

	if (runtimeVersion < Relocation::Version<std::int32_t>(1, 5, 39, 0))
	{
		Utility::Log::Critical()(
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
	SKSE::Storage::GetSingleton().Load(loadInterface);

	return ConsoleCommandCompanion::Load();
}
