#include "PCH.h"

#include "Events.h"
#include "Patches.h"
#include "Settings.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Skyrim/B/BSInputDeviceManager.h"
#include "Shared/Skyrim/Events.h"
#include "Shared/Skyrim/I/InterfaceStrings.h"
#include "Shared/Skyrim/S/Script.h"
#include "Shared/Skyrim/S/ScriptEventSourceHolder.h"
#include "Shared/Skyrim/U/UI.h"
#include "Shared/Utility/Log.h"



void OnInitializeThread()
{
	// Create the Console menu to allow batch files to be run
	if (!Skyrim::UI::GetSingleton()->IsMenuOpen(Skyrim::InterfaceStrings::GetSingleton()->console))
	{
		Skyrim::Script::ExecuteCommand(fmt::format("ShowMenu {}", Skyrim::InterfaceStrings::GetSingleton()->console));
		Skyrim::Script::ExecuteCommand(fmt::format("HideMenu {}", Skyrim::InterfaceStrings::GetSingleton()->console));
	}

	for (const auto& consoleCommand : ConsoleCommandCompanion::Settings::GetSingleton().events.initialize.consoleCommands)
	{
		SKSE::Cache::GetSingleton().GetTaskInterface()->AddTask(
			[consoleCommand]()
			{
				Skyrim::Script::ExecuteCommand(consoleCommand);
			});
	}

	Skyrim::ScriptEventSourceHolder::GetSingleton()->GetEventSource<Skyrim::TESLoadGameEvent>()->AddEventSink(ConsoleCommandCompanion::Events::LoadGameEventSink::GetSingleton());
	Skyrim::BSInputDeviceManager::GetSingleton()->AddEventSink(ConsoleCommandCompanion::Events::ButtonEventSink::GetSingleton());
}

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInformation* pluginInformation)
{
	pluginInformation->informationVersion = SKSE::PluginInformation::kVersion;
	pluginInformation->name               = "Console Command Companion";
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
	.pluginName     = "Console Command Companion",
	.author         = "KernalsEgg",
	.addressLibrary = true
};

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Cache::GetSingleton().Initialize(loadInterface);

	Utility::Log::Information("Initializing...");

	auto patched = ConsoleCommandCompanion::Patches::Install();

	if (patched.has_value())
	{
		Utility::Log::Information("Patched Bethesda.net Login: {}", patched.value());

		if (!patched.value())
		{
			return false;
		}
	}

	Skyrim::Events::InitializeThread::GetSingleton().After().AddEventSink(OnInitializeThread);

	Utility::Log::Information("Initialized.\n{}", ConsoleCommandCompanion::Settings::GetSingleton().Serialize().dump(1, '\t'));

	return true;
}
