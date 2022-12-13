#include "PrecompiledHeader.h"

#include "Settings.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Utility/Trampoline.h"



namespace BugFixesSSE
{
	bool Initialize()
	{
		Settings::GetSingleton().Initialize();
		Utility::Trampoline::GetSingleton().Commit();

		return true;
	}
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 9,
	.pluginName      = "Bug Fixes SSE",
	.author          = "meh321 and KernalsEgg",
	.addressLibrary  = true,
	.compatible16629 = true
};
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Cache::GetSingleton().Initialize(loadInterface);

	return BugFixesSSE::Initialize();
}
