#include "PrecompiledHeader.h"

#include "Events/DualValueModifierEffect.h"

#include "Events/ActiveEffect.h"
#include "Shared/Utility/Memory.h"



namespace ConditionsTargetMagicEffects::Events
{
	void DualValueModifierEffect::Register()
	{
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::DualValueModifierEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(DualValueModifierEffect::AdjustForPerks)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::EnhanceWeaponEffect::VirtualFunctionTable, 0x0, reinterpret_cast<std::uintptr_t>(std::addressof(DualValueModifierEffect::AdjustForPerks)));
	}

	void DualValueModifierEffect::AdjustForPerks(Skyrim::DualValueModifierEffect* dualValueModifierEffect, Skyrim::Actor* caster, Skyrim::MagicTarget* magicTarget)
	{
		ActiveEffect::AdjustForPerks(dualValueModifierEffect, caster, magicTarget);

		auto* effectSetting = dualValueModifierEffect->GetEffectSetting();
		auto* magicItem     = dualValueModifierEffect->magicItem;
		auto* targetActor   = magicTarget->GetMagicTargetAsActor();

		bool modifiedSecondaryValueWeight{ false };

		Skyrim::BGSEntryPoint::HandleEntryPoint(
			Skyrim::BGSEntryPoint::EntryPoint::kModifySecondaryValueWeight,
			caster,
			effectSetting,
			magicItem,
			nullptr,
			targetActor,
			std::addressof(dualValueModifierEffect->secondaryActorValueWeight),
			std::addressof(modifiedSecondaryValueWeight));

		if (!modifiedSecondaryValueWeight)
		{
			Skyrim::BGSEntryPoint::HandleEntryPoint(
				Skyrim::BGSEntryPoint::EntryPoint::kModifySecondaryValueWeight,
				caster,
				magicItem,
				targetActor,
				std::addressof(dualValueModifierEffect->secondaryActorValueWeight));
		}
	}
}
