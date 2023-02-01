#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/E/EnchantmentItem.h"
#include "Shared/Skyrim/M/MagicItem.h"



namespace ScrambledBugs::Patches
{
	class StaffExperience
	{
	public:
		static void Patch(bool& staffExperience, bool& staffExperienceIgnoreEnchantmentCost);

	private:
		static bool GetSkillUsageDataEnchantment(Skyrim::EnchantmentItem* enchantment, Skyrim::MagicItem::SkillUsageData& skillUsageData);
		static bool GetSkillUsageDataStaffEnchantment(Skyrim::EnchantmentItem* enchantment, Skyrim::MagicItem::SkillUsageData& skillUsageData);

		static bool                                                     ignoreEnchantmentCost_;
		static decltype(&StaffExperience::GetSkillUsageDataEnchantment) getSkillUsageDataEnchantment_;
	};
}
