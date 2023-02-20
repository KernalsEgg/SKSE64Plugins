#include "PrecompiledHeader.h"

#include "Serialization.h"
#include "Shared/Relocation/Version.h"
#include "Shared/Utility/Log.h"



namespace VendorRespawnFix
{
	bool Load()
	{
		const auto* serializationInterface = SKSE::Storage::GetSingleton().GetSerializationInterface();

		serializationInterface->SetUniqueID(Serialization::kUniqueID);
		serializationInterface->SetLoadCallback(std::addressof(Serialization::LoadGame));
		serializationInterface->SetSaveCallback(std::addressof(Serialization::SaveGame));

		return true;
	}
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 1,
	.pluginName      = "Vendor Respawn Fix",
	.author          = "KernalsEgg",
	.addressLibrary  = true,
	.compatible16629 = true
};
#else
extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInformation* pluginInformation)
{
	pluginInformation->informationVersion = SKSE::PluginInformation::kVersion;
	pluginInformation->name               = "Vendor Respawn Fix";
	pluginInformation->version            = 1;

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

	return VendorRespawnFix::Load();
}
