#include "PrecompiledHeader.h"

#include "Patches/StaffExperience.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/E/EffectArchetypes.h"
#include "Shared/Skyrim/E/EffectItem.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Skyrim/M/MagicSystem.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void StaffExperience::Patch(bool& staffExperience, bool& staffExperienceIgnoreEnchantmentCost)
	{
		StaffExperience::ignoreEnchantmentCost_ = staffExperienceIgnoreEnchantmentCost;

		StaffExperience::getSkillUsageDataEnchantment_ = reinterpret_cast<decltype(StaffExperience::getSkillUsageDataEnchantment_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::EnchantmentItem::VirtualFunctionTable, 0x60));

		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::EnchantmentItem::VirtualFunctionTable, 0x60, reinterpret_cast<std::uintptr_t>(std::addressof(StaffExperience::GetSkillUsageDataEnchantment)));
	}

	bool StaffExperience::GetSkillUsageDataEnchantment(Skyrim::EnchantmentItem* enchantment, Skyrim::MagicItem::SkillUsageData& skillUsageData)
	{
		// enchantment != nullptr

		switch (enchantment->GetSpellType())
		{
			case Skyrim::MagicSystem::SpellType::kStaffEnchantment:
			{
				return StaffExperience::GetSkillUsageDataStaffEnchantment(enchantment, skillUsageData);
			}
			default:
			{
				return StaffExperience::getSkillUsageDataEnchantment_(enchantment, skillUsageData);
			}
		}
	}

	bool StaffExperience::GetSkillUsageDataStaffEnchantment(Skyrim::EnchantmentItem* enchantment, Skyrim::MagicItem::SkillUsageData& skillUsageData)
	{
		if (!skillUsageData.costliestEffect)
		{
			skillUsageData.costliestEffect = enchantment->GetCostliestEffect(Skyrim::MagicSystem::Delivery::kAny, false);

			if (!skillUsageData.costliestEffect)
			{
				return false;
			}
		}

		auto skillUsage = skillUsageData.costliestEffect->GetCost(nullptr);

		if (!StaffExperience::ignoreEnchantmentCost_ && !enchantment->IsAutomaticallyCalculated())
		{
			auto enchantmentCost = static_cast<float>(static_cast<const Skyrim::EnchantmentItem::Data*>(enchantment->GetConstantData())->enchantmentCost);

			if (skillUsage > enchantmentCost)
			{
				skillUsage = enchantmentCost;
			}
		}

		auto* costliestEffectSetting = skillUsageData.costliestEffect->effectSetting;

		skillUsageData.magicSkill = costliestEffectSetting->magicSkill;
		skillUsageData.magnitude  = costliestEffectSetting->skillUsageMultiplier * skillUsage;
		skillUsageData.custom     = Skyrim::EffectArchetypes::IsFlagSet(costliestEffectSetting->effectArchetype, Skyrim::EffectArchetypes::Archetype::Flags::kCustom);

		return skillUsageData.magicSkill.underlying() - Utility::ToUnderlying(Skyrim::ActorValue::kSkills) <= Utility::ToUnderlying(Skyrim::ActorValue::kSkillCount);
	}

	bool                                                     StaffExperience::ignoreEnchantmentCost_{ false };
	decltype(&StaffExperience::GetSkillUsageDataEnchantment) StaffExperience::getSkillUsageDataEnchantment_{ nullptr };
}
