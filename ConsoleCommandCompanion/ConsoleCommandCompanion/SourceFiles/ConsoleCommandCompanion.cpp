#include "PrecompiledHeader.h"

#include "Events.h"
#include "Patches.h"
#include "Settings.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Skyrim/B/BSInputDeviceManager.h"
#include "Shared/Skyrim/C/Console.h"
#include "Shared/Skyrim/Events.h"
#include "Shared/Skyrim/I/InterfaceStrings.h"
#include "Shared/Skyrim/S/ScriptEventSourceHolder.h"
#include "Shared/Skyrim/U/UI.h"
#include "Shared/Utility/Log.h"



void OnInitializeThread()
{
	// Create the Console menu to allow batch files to be run
	if (!Skyrim::UI::GetSingleton()->IsMenuOpen(Skyrim::InterfaceStrings::GetSingleton()->console))
	{
		Skyrim::Console::ExecuteCommand(std::vformat("ShowMenu {}", std::make_format_args(Skyrim::InterfaceStrings::GetSingleton()->console.data())));
		Skyrim::Console::ExecuteCommand(std::vformat("HideMenu {}", std::make_format_args(Skyrim::InterfaceStrings::GetSingleton()->console.data())));
	}

	for (const auto& consoleCommand : ConsoleCommandCompanion::Settings::GetSingleton().events.initialize.consoleCommands)
	{
		SKSE::Cache::GetSingleton().GetTaskInterface()->AddTask(
			[consoleCommand]()
			{
				Skyrim::Console::ExecuteCommand(consoleCommand);
			});
	}

	Skyrim::ScriptEventSourceHolder::GetSingleton()->GetEventSource<Skyrim::TESLoadGameEvent>()->AddEventSink(std::addressof(ConsoleCommandCompanion::Events::LoadGameEventSink::GetSingleton()));
	Skyrim::BSInputDeviceManager::GetSingleton()->AddEventSink(std::addressof(ConsoleCommandCompanion::Events::ButtonEventSink::GetSingleton()));
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
	pluginInformation->name               = "Console Command Companion";
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

	Utility::Log::Information("Initializing...");

#ifdef SKYRIM_ANNIVERSARY_EDITION
#else
	if (!ConsoleCommandCompanion::Patches::Install())
	{
		Utility::Log::Critical("Failed to patch Bethesda.net login.");

		return false;
	}
#endif

	Skyrim::Events::InitializeThread::GetSingleton().After().AddEventSink(OnInitializeThread);

	Utility::Log::Information("Initialized.\n{}", ConsoleCommandCompanion::Settings::GetSingleton().Serialize().dump(1, '\t'));

	return true;
}
