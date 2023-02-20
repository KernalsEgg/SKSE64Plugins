#include "PrecompiledHeader.h"

#include "Settings.h"



namespace ActorLimitFix
{
	bool Load()
	{
		Settings::GetSingleton().Load();

		return true;
	}
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 9,
	.pluginName      = "Actor Limit Fix",
	.author          = "meh321 and KernalsEgg",
	.addressLibrary  = true,
	.compatible16629 = true
};
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Storage::GetSingleton().Load(loadInterface);

	return ActorLimitFix::Load();
}
