#include "PrecompiledHeader.h"

#include "Serialization.h"
#include "Settings.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Utility/Log.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs
{
	bool Initialize()
	{
		const auto* serializationInterface = SKSE::Cache::GetSingleton().GetSerializationInterface();

		if (!serializationInterface)
		{
			Utility::Log::Critical()("Serialization interface not found.");

			return false;
		}

		serializationInterface->SetUniqueID(ScrambledBugs::Serialization::kUniqueID);
		serializationInterface->SetLoadCallback(std::addressof(ScrambledBugs::Serialization::LoadGame));
		serializationInterface->SetSaveCallback(std::addressof(ScrambledBugs::Serialization::SaveGame));

		Settings::GetSingleton().Initialize();
		Utility::Trampoline::GetSingleton().Commit();

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
	SKSE::Cache::GetSingleton().Initialize(loadInterface);

	return ScrambledBugs::Initialize();
}
