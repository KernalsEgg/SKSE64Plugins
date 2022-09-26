#include "PrecompiledHeader.h"

#include "Patches/StaffExperience.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void StaffExperience::Patch(bool& staffExperience)
	{
		StaffExperience::getSkillUsageDataEnchantmentItem_ = reinterpret_cast<decltype(StaffExperience::getSkillUsageDataEnchantmentItem_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::EnchantmentItem::VirtualFunctionTable, 0x60));
		StaffExperience::getSkillUsageDataSpellItem_       = reinterpret_cast<decltype(StaffExperience::getSkillUsageDataSpellItem_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::SpellItem::VirtualFunctionTable, 0x60));

		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::EnchantmentItem::VirtualFunctionTable, 0x60, reinterpret_cast<std::uintptr_t>(std::addressof(StaffExperience::GetSkillUsageData)));
	}

	bool StaffExperience::GetSkillUsageData(Skyrim::EnchantmentItem* enchantment, Skyrim::MagicItem::SkillUsageData& skillUsageData)
	{
		return enchantment->GetSpellType() == Skyrim::MagicSystem::SpellType::kStaffEnchantment ? StaffExperience::getSkillUsageDataSpellItem_(enchantment, skillUsageData) : StaffExperience::getSkillUsageDataEnchantmentItem_(enchantment, skillUsageData);
	}

	decltype(&StaffExperience::GetSkillUsageData) StaffExperience::getSkillUsageDataEnchantmentItem_;
	decltype(&StaffExperience::GetSkillUsageData) StaffExperience::getSkillUsageDataSpellItem_;
}
