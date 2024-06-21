#include "PrecompiledHeader.h"

#include "Events.h"
#include "Settings.h"
#include "Shared/Relocation/Module.h"



namespace Trails
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

	void OnInitializeThread()
	{
		SPDLOG_INFO("\n{}", Settings::GetSingleton().Serialize().dump(1, '\t'));

		Skyrim::BGSFootstepManager::GetSingleton()->RegisterSink(std::addressof(Events::FootstepEventSink::GetSingleton()));
	}

	void Load()
	{
		Skyrim::Events::InitializeThread::GetSingleton().After().RegisterSink(Trails::OnInitializeThread);
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

	return true;
}
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	Trails::Log::Load();
	SKSE::Storage::GetSingleton().Load(loadInterface);
	Trails::Load();

	return true;
}
