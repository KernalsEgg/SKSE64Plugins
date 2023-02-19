#include "PrecompiledHeader.h"

#include "Serialization.h"
#include "Settings.h"
#include "Shared/Utility/Log.h"



namespace ScrambledBugs
{
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

	bool Load()
	{
		if (!SKSE::Storage::GetSingleton().GetMessagingInterface()->RegisterListener(ScrambledBugs::MessageHandler))
		{
			return false;
		}

		const auto* serializationInterface = SKSE::Storage::GetSingleton().GetSerializationInterface();

		serializationInterface->SetUniqueID(ScrambledBugs::Serialization::kUniqueID);
		serializationInterface->SetLoadCallback(std::addressof(ScrambledBugs::Serialization::LoadGame));
		serializationInterface->SetSaveCallback(std::addressof(ScrambledBugs::Serialization::SaveGame));

		Settings::GetSingleton().Load();

		return true;
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
	SKSE::Storage::GetSingleton().Initialize(loadInterface);

	return ScrambledBugs::Load();
}
