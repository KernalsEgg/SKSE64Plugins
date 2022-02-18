#include "PCH.h"

#include "Fixes/MorphLimit.h"
#include "Fixes/MoverLimit.h"
#include "Fixes/ReplaceStaticArray.h"
#include "Settings.h"
#include "Shared/Relocation/Module.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Trampoline.h"



void Settings()
{
	auto& settings = ActorLimitFix::Settings::GetSingleton();

	Utility::Log::Information("Initializing...\n{}", settings.Serialize().dump(1, '\t'));

	if (settings.fixes.replaceStaticArray)
	{
		settings.fixes.replaceStaticArray = ActorLimitFix::Fixes::ReplaceStaticArray::Fix();
	}

	ActorLimitFix::Fixes::MorphLimit::Fix(settings.fixes.morphLimit, settings.fixes.replaceStaticArray);
	ActorLimitFix::Fixes::MoverLimit::Fix(settings.fixes.moverLimit);

	Utility::Log::Information("Initialized.\n{}", settings.Serialize().dump(1, '\t'));

	Utility::Trampoline::GetSingleton().Commit();
}

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInfo* pluginInfo)
{
	static std::string name = Relocation::Plugin::GetSingleton().GetPath().stem().string();

	pluginInfo->infoVersion = SKSE::PluginInfo::kVersion;
	pluginInfo->name        = name.c_str();
	pluginInfo->version     = 3;

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
