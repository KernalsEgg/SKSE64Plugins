#include "PrecompiledHeader.h"

#include "Serialization.h"
#include "Settings.h"
#include "Shared/Relocation/Module.h"



namespace ScrambledBugs
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

	void PostLoad()
	{
		Settings::GetSingleton().PostLoad();
	}

	void MessageHandler(SKSE::MessagingInterface::Message* message)
	{
		switch (message->type)
		{
			case SKSE::MessagingInterface::kPostLoad:
			{
				ScrambledBugs::PostLoad();

				break;
			}
		}
	}

	void Load()
	{
		if (!SKSE::Storage::GetSingleton().GetMessagingInterface()->RegisterListener(ScrambledBugs::MessageHandler))
		{
			return;
		}

		const auto* serializationInterface = SKSE::Storage::GetSingleton().GetSerializationInterface();

		serializationInterface->SetUniqueID(ScrambledBugs::Serialization::kUniqueID);
		serializationInterface->SetLoadCallback(std::addressof(ScrambledBugs::Serialization::LoadGame));
		serializationInterface->SetSaveCallback(std::addressof(ScrambledBugs::Serialization::SaveGame));

		Settings::GetSingleton().Load();
	}
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 21,
	.pluginName      = "Scrambled Bugs",
	.author          = "KernalsEgg",
	.addressLibrary  = true,
	.compatible16629 = true
};
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	ScrambledBugs::Log::Load();
	SKSE::Storage::GetSingleton().Load(loadInterface);
	ScrambledBugs::Load();

	return true;
}
