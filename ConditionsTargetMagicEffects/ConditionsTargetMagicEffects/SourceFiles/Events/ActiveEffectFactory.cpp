#include "PrecompiledHeader.h"

#include "Events/ActiveEffectFactory.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ConditionsTargetMagicEffects::Events
{
	void ActiveEffectFactory::Register()
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Addresses::ActiveEffectFactory::CheckTargetLevelMagnitude,
			reinterpret_cast<std::uintptr_t>(std::addressof(ActiveEffectFactory::CheckTargetLevelMagnitude)));
	}

	bool ActiveEffectFactory::CheckTargetLevelMagnitude(std::int32_t targetLevel, Skyrim::ActiveEffectFactory::CheckTargetArguments& checkTargetArguments)
	{
		auto* targetActor = checkTargetArguments.magicTarget ? checkTargetArguments.magicTarget->GetMagicTargetAsActor() : nullptr;

		bool modifiedSpellMagnitude{ false };

		if (checkTargetArguments.effectSetting)
		{
			Skyrim::BGSEntryPoint::HandleEntryPoint(
				Skyrim::BGSEntryPoint::EntryPoint::kModifySpellMagnitude,
				checkTargetArguments.caster,
				checkTargetArguments.effectSetting,
				checkTargetArguments.magicItem,
				nullptr,
				targetActor,
				std::addressof(checkTargetArguments.magnitude),
				std::addressof(modifiedSpellMagnitude));
		}

		if (!modifiedSpellMagnitude)
		{
			Skyrim::BGSEntryPoint::HandleEntryPoint(
				Skyrim::BGSEntryPoint::EntryPoint::kModifySpellMagnitude,
				checkTargetArguments.caster,
				checkTargetArguments.magicItem,
				targetActor,
				std::addressof(checkTargetArguments.magnitude));
		}

		if (checkTargetArguments.dualCasted)
		{
			if (checkTargetArguments.caster)
			{
				if (checkTargetArguments.effectSetting && checkTargetArguments.effectSetting->effectSettingFlags.all(Skyrim::EffectSetting::Flags::kPowerAffectsMagnitude))
				{
					auto cost                     = checkTargetArguments.magicItem->GetCost(checkTargetArguments.caster);
					auto dualCastingEffectiveness = checkTargetArguments.caster->GetDualCastingEffectiveness(cost);

					checkTargetArguments.magnitude *= dualCastingEffectiveness;
				}
			}
		}

		if (targetLevel > checkTargetArguments.magnitude)
		{
			checkTargetArguments.reportAddTargetFailure = Skyrim::ActiveEffectFactory::CheckTargetArguments::ReportAddTargetFailure::kShowFailure;
		}

		return targetLevel <= checkTargetArguments.magnitude;
	}
}
