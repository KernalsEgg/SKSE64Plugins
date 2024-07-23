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
			auto logger = spdlog::basic_logger_mt(path.string(), path.string(), true);

			logger->flush_on(spdlog::level::info);
			logger->set_level(spdlog::level::info);
			logger->set_pattern("[%Y-%m-%d %T.%e %z] [%l] [%t] [%s:%#] %v");

			spdlog::set_default_logger(std::move(logger));
		}
	}

	bool InitializeThread()
	{
		SPDLOG_INFO("\n{}", Settings::GetSingleton().Serialize().dump(1, '\t'));

		Skyrim::BGSFootstepManager::GetSingleton()->RegisterSink(std::addressof(Events::FootstepEventSink::GetSingleton()));

		return true;
	}

	void Load()
	{
		Skyrim::Events::InitializeThread::GetSingleton().after.Subscribe(
			std::make_shared<decltype(Skyrim::Events::InitializeThread::after)::handler_type::element_type>(
				Trails::InitializeThread));
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
