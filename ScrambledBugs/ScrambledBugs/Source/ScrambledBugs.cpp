#include "PrecompiledHeader.h"

#include "Serialization.h"
#include "Settings.h"
#include "Shared/Relocation/Module.h"



namespace ScrambledBugs
{
	namespace Logger
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
	ScrambledBugs::Logger::Load();
	SKSE::Storage::GetSingleton().Load(loadInterface);
	ScrambledBugs::Load();

	return true;
}
