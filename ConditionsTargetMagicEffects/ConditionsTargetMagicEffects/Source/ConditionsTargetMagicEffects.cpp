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
#include "Shared/Relocation/Module.h"



namespace ConditionsTargetMagicEffects
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

	void Load()
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

	return true;
}
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	ConditionsTargetMagicEffects::Log::Load();
	SKSE::Storage::GetSingleton().Load(loadInterface);
	ConditionsTargetMagicEffects::Load();

	return true;
}
