#include "PrecompiledHeader.h"

#include "Events/ActiveEffect.h"

#include "Shared/Utility/Memory.h"



namespace ConditionsTargetMagicEffects::Events
{
	void ActiveEffect::Register()
	{
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::AbsorbEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::AccumulatingValueModifierEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ActiveEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::BanishEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::BoundItemEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::CalmEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::CloakEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::CommandEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::CommandSummonedEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ConcussionEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::CureEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::DarknessEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::DemoralizeEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::DetectLifeEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::DisarmEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::DisguiseEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::DispelEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::EtherealizationEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::FrenzyEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::GrabActorEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::GuideEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::InvisibilityEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::LightEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::LockEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::NightEyeEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::OpenEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ParalysisEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::PeakValueModifierEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::RallyEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ReanimateEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ScriptedRefEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ScriptEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::SlowTimeEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::SoulTrapEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::SpawnHazardEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::StaggerEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::SummonCreatureEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::TargetValueModifierEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::TelekinesisEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::TurnUndeadEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ValueAndConditionsEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ValueModifierEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::VampireLordEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::WerewolfEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::WerewolfFeedEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffect::AdjustForPerks)));
	}

	void ActiveEffect::AdjustForPerks(Skyrim::ActiveEffect* activeEffect, Skyrim::Actor* caster, Skyrim::MagicTarget* magicTarget)
	{
		auto* effectSetting = activeEffect->GetEffectSetting();
		auto* magicItem     = activeEffect->magicItem;
		auto* targetActor   = magicTarget->GetMagicTargetAsActor();

		bool modifiedIncomingSpellDuration{ false };
		bool modifiedIncomingSpellMagnitude{ false };
		bool modifiedSpellDuration{ false };
		bool modifiedSpellMagnitude{ false };

		Skyrim::BGSEntryPoint::HandleEntryPoint(
			Skyrim::BGSEntryPoint::EntryPoint::kModifySpellDuration,
			caster,
			effectSetting,
			magicItem,
			nullptr,
			targetActor,
			std::addressof(activeEffect->duration),
			std::addressof(modifiedSpellDuration));

		if (!modifiedSpellDuration)
		{
			Skyrim::BGSEntryPoint::HandleEntryPoint(
				Skyrim::BGSEntryPoint::EntryPoint::kModifySpellDuration,
				caster,
				magicItem,
				targetActor,
				std::addressof(activeEffect->duration));
		}

		Skyrim::BGSEntryPoint::HandleEntryPoint(
			Skyrim::BGSEntryPoint::EntryPoint::kModifySpellMagnitude,
			caster,
			effectSetting,
			magicItem,
			nullptr,
			targetActor,
			std::addressof(activeEffect->magnitude),
			std::addressof(modifiedSpellMagnitude));

		if (!modifiedSpellMagnitude)
		{
			Skyrim::BGSEntryPoint::HandleEntryPoint(
				Skyrim::BGSEntryPoint::EntryPoint::kModifySpellMagnitude,
				caster,
				magicItem,
				targetActor,
				std::addressof(activeEffect->magnitude));
		}

		Skyrim::BGSEntryPoint::HandleEntryPoint(
			Skyrim::BGSEntryPoint::EntryPoint::kModifyIncomingSpellDuration,
			targetActor,
			effectSetting,
			nullptr,
			magicItem,
			std::addressof(activeEffect->duration),
			std::addressof(modifiedIncomingSpellDuration));

		if (!modifiedIncomingSpellDuration)
		{
			Skyrim::BGSEntryPoint::HandleEntryPoint(
				Skyrim::BGSEntryPoint::EntryPoint::kModifyIncomingSpellDuration,
				targetActor,
				magicItem,
				std::addressof(activeEffect->duration));
		}

		Skyrim::BGSEntryPoint::HandleEntryPoint(
			Skyrim::BGSEntryPoint::EntryPoint::kModifyIncomingSpellMagnitude,
			targetActor,
			effectSetting,
			nullptr,
			magicItem,
			std::addressof(activeEffect->magnitude),
			std::addressof(modifiedIncomingSpellMagnitude));

		if (!modifiedIncomingSpellMagnitude)
		{
			Skyrim::BGSEntryPoint::HandleEntryPoint(
				Skyrim::BGSEntryPoint::EntryPoint::kModifyIncomingSpellMagnitude,
				targetActor,
				magicItem,
				std::addressof(activeEffect->magnitude));
		}
	}
}
