#include "PrecompiledHeader.h"

#include "Events/ActiveEffect.h"
#include "Events/ActiveEffectFactory.h"
#include "Events/BGSEntryPoint.h"
#include "Events/BGSEntryPointPerkEntry.h"
#include "Events/DualValueModifierEffect.h"
#include "Events/EffectItemReplaceTagsFunctor.h"
#include "Events/EnchantConstructMenu.h"
#include "Events/MagicSystem.h"
#include "Events/Script.h"
#include "Events/SlowTimeEffect.h"
#include "Shared/Relocation/Version.h"
#include "Shared/Utility/Log.h"



namespace ConditionsTargetMagicEffects
{
	bool Load()
	{
		Events::ActiveEffect::Register();
		Events::ActiveEffectFactory::Register();
		Events::BGSEntryPoint::Register();
		Events::BGSEntryPointPerkEntry::Register();
		Events::CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor::Register();
		Events::DualValueModifierEffect::Register();
		Events::EffectItemReplaceTagsFunctor::Register();
		Events::MagicSystem::Register();
		Events::Script::Register();
		Events::SlowTimeEffect::Register();

		return true;
	}
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = 1,
	.pluginName      = "Conditions Target Magic Effects",
	.author          = "KernalsEgg",
	.addressLibrary  = true,
	.compatible16629 = true
};
#else
extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Query(SKSE::Interface* queryInterface, SKSE::PluginInformation* pluginInformation)
{
	pluginInformation->informationVersion = SKSE::PluginInformation::kVersion;
	pluginInformation->name               = "Conditions Target Magic Effects";
	pluginInformation->version            = 1;

	if (queryInterface->IsEditor())
	{
		Utility::Log::Critical()("Loading in editor.");

		return false;
	}

	auto runtimeVersion = queryInterface->RuntimeVersion();

	if (runtimeVersion < Relocation::Version<std::int32_t>(1, 5, 39, 0))
	{
		Utility::Log::Critical()(
			"Unsupported runtime version, {}.{}.{}.{}.",
			runtimeVersion.major,
			runtimeVersion.minor,
			runtimeVersion.revision,
			runtimeVersion.build);

		return false;
	}

	return true;
}
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	SKSE::Storage::GetSingleton().Initialize(loadInterface);

	return ConditionsTargetMagicEffects::Load();
}
