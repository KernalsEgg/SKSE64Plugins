#include "PrecompiledHeader.h"

#include "Events/SlowTimeEffect.h"

#include "Events/ScriptEffect.h"
#include "Shared/Utility/Memory.h"



namespace ConditionsTargetMagicEffects::Events
{
	void SlowTimeEffect::Register()
	{
		Utility::Memory::SafeWriteVirtualFunction(
			Skyrim::Addresses::SlowTimeEffect::VirtualFunctionTable(),
			0x20,
			reinterpret_cast<std::uintptr_t>(std::addressof(SlowTimeEffect::Start)));
	}

	void SlowTimeEffect::Start(Skyrim::SlowTimeEffect* slowTimeEffect)
	{
		static auto* vatsPlayerMagicTimeSlowdownMultiplier = Skyrim::GameSettingCollection::InitializeSetting("fVATSPlayerMagicTimeSlowdownMult");

		auto* targetActor             = slowTimeEffect->magicTarget->GetMagicTargetAsActor();
		auto* effectSetting           = slowTimeEffect->GetEffectSetting();
		auto* magicItem               = slowTimeEffect->magicItem;
		auto  playerMagicTimeSlowdown = vatsPlayerMagicTimeSlowdownMultiplier->GetFloat();

		bool modifiedPlayerMagicSlowdown{ false };

		Skyrim::BGSEntryPoint::HandleEntryPoint(
			Skyrim::BGSEntryPoint::EntryPoint::kModifyPlayerMagicSlowdown,
			targetActor,
			effectSetting,
			nullptr,
			magicItem,
			std::addressof(playerMagicTimeSlowdown),
			std::addressof(modifiedPlayerMagicSlowdown));

		if (!modifiedPlayerMagicSlowdown)
		{
			Skyrim::BGSEntryPoint::HandleEntryPoint(
				Skyrim::BGSEntryPoint::EntryPoint::kModifyPlayerMagicSlowdown,
				targetActor,
				magicItem,
				std::addressof(playerMagicTimeSlowdown));
		}

		auto* vats              = Skyrim::VATS::GetSingleton();
		auto  magicTimeSlowdown = slowTimeEffect->GetCurrentMagnitude();

		vats->SetMagicTimeSlowdown(magicTimeSlowdown, playerMagicTimeSlowdown);

		slowTimeEffect->duration *= vats->GetPlayerUpdateMultiplier();

		auto* audioManager = Skyrim::BSAudioManager::GetSingleton();

		audioManager->GetSoundHandleFromName(slowTimeEffect->soundHandle, "MAGShoutSlowTimeActiveLP", 0x802);
		slowTimeEffect->soundHandle.Play();

		ScriptEffect::Start(slowTimeEffect);
	}
}
