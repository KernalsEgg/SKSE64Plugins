#include "PrecompiledHeader.h"

#include "Serialization.h"
#include "Shared/Relocation/Module.h"



namespace VendorRespawnFix
{
	namespace Log
	{
		void Load()
		{
			auto path   = std::filesystem::path(Relocation::DynamicLinkLibrary::GetSingleton().GetPath()).replace_extension("log");
			auto sink   = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path.string(), true);
			auto logger = std::make_shared<spdlog::logger>("logger", std::move(sink));

			logger->set_level(spdlog::level::info);
			logger->flush_on(spdlog::level::info);

			spdlog::set_default_logger(std::move(logger));
			spdlog::set_pattern("[%Y-%m-%d %T.%e %z] [%l] [%t] [%s:%#] %v");
		}
	}

	void Load()
	{
		const auto* serializationInterface = SKSE::Storage::GetSingleton().GetSerializationInterface();

		serializationInterface->SetUniqueID(Serialization::kUniqueID);
		serializationInterface->SetLoadCallback(std::addressof(Serialization::LoadGame));
		serializationInterface->SetSaveCallback(std::addressof(Serialization::SaveGame));
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

	return true;
}
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	VendorRespawnFix::Log::Load();
	SKSE::Storage::GetSingleton().Load(loadInterface);
	VendorRespawnFix::Load();

	return true;
}
