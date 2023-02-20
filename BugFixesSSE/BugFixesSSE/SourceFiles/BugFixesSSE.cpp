#include "PrecompiledHeader.h"

#include "Settings.h"



namespace BugFixesSSE
{
	bool Load()
	{
		Settings::GetSingleton().Load();

		return true;
	}
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 10,
	.pluginName      = "Bug Fixes SSE",
	.author          = "meh321 and KernalsEgg",
	.addressLibrary  = true,
	.compatible16629 = true
};
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Storage::GetSingleton().Load(loadInterface);

	return BugFixesSSE::Load();
}
