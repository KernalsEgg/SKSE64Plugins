#include "PrecompiledHeader.h"

#include "Patches/StaffExperience.h"

#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void StaffExperience::Patch(bool& staffExperience, bool& ignoreEnchantmentCost)
	{
		StaffExperience::ignoreEnchantmentCost_ = ignoreEnchantmentCost;

		StaffExperience::getSkillUsageDataEnchantment_ = reinterpret_cast<decltype(StaffExperience::getSkillUsageDataEnchantment_)>(
			Utility::Memory::ReadVirtualFunction(
				Skyrim::Addresses::EnchantmentItem::VirtualFunctionTable(),
				0x60));
		Utility::Memory::SafeWriteVirtualFunction(
			Skyrim::Addresses::EnchantmentItem::VirtualFunctionTable(),
			0x60,
			reinterpret_cast<std::uintptr_t>(std::addressof(StaffExperience::GetSkillUsageDataEnchantment)));
	}

	bool StaffExperience::GetSkillUsageDataEnchantment(Skyrim::EnchantmentItem* enchantmentItem, Skyrim::MagicItem::SkillUsageData& skillUsageData)
	{
		// enchantmentItem != nullptr

		switch (enchantmentItem->GetSpellType())
		{
			case Skyrim::MagicSystem::SpellType::kStaffEnchantment:
			{
				return StaffExperience::GetSkillUsageDataStaffEnchantment(enchantmentItem, skillUsageData);
			}
			default:
			{
				return StaffExperience::getSkillUsageDataEnchantment_(enchantmentItem, skillUsageData);
			}
		}
	}

	bool StaffExperience::GetSkillUsageDataStaffEnchantment(Skyrim::EnchantmentItem* enchantmentItem, Skyrim::MagicItem::SkillUsageData& skillUsageData)
	{
		if (!skillUsageData.costliestEffectItem)
		{
			skillUsageData.costliestEffectItem = enchantmentItem->GetCostliestEffectItem(Skyrim::MagicSystem::Delivery::kAny, false);

			if (!skillUsageData.costliestEffectItem)
			{
				return false;
			}
		}

		auto skillUsage = skillUsageData.costliestEffectItem->GetCost(nullptr);

		if (!StaffExperience::ignoreEnchantmentCost_ && !enchantmentItem->IsAutomaticallyCalculated())
		{
			auto enchantmentCost = static_cast<float>(reinterpret_cast<const Skyrim::EnchantmentItem::Data*>(enchantmentItem->GetConstantData())->enchantmentCost);

			if (skillUsage > enchantmentCost)
			{
				skillUsage = enchantmentCost;
			}
		}

		auto* costliestEffectSetting = skillUsageData.costliestEffectItem->effectSetting;

		skillUsageData.magicSkill           = costliestEffectSetting->magicSkill;
		skillUsageData.magnitude            = costliestEffectSetting->skillUsageMultiplier * skillUsage;
		skillUsageData.customSkillUseReward = Skyrim::EffectArchetypes::GetArchetype(costliestEffectSetting->effectArchetype)->flags.all(Skyrim::EffectArchetypes::Archetype::Flags::kCustomSkillUseReward);

		return Utility::Conversion::ToUnderlying(Skyrim::ActorValue::kSkills) <= skillUsageData.magicSkill.underlying() &&
		       skillUsageData.magicSkill.underlying() < Utility::Conversion::ToUnderlying(Skyrim::ActorValue::kDerivedAttributes);
	}

	bool                                                     StaffExperience::ignoreEnchantmentCost_{};
	decltype(StaffExperience::GetSkillUsageDataEnchantment)* StaffExperience::getSkillUsageDataEnchantment_{ nullptr };
}
