#include "PrecompiledHeader.h"

#include "Events.h"
#include "Shared/Relocation/Module.h"



namespace BarterLimitFix
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
		if (!Events::Register())
		{
			SPDLOG_CRITICAL("Failed to register for events.");

			return;
		}
	}
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 2,
	.pluginName      = "Barter Limit Fix",
	.author          = "KernalsEgg",
	.addressLibrary  = true,
	.compatible16629 = true
};
#else
extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInformation* pluginInformation)
{
	pluginInformation->informationVersion = SKSE::PluginInformation::kVersion;
	pluginInformation->name               = "Barter Limit Fix";
	pluginInformation->version            = 2;

	return true;
}
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	BarterLimitFix::Log::Load();
	SKSE::Storage::GetSingleton().Load(loadInterface);
	BarterLimitFix::Load();

	return true;
}
