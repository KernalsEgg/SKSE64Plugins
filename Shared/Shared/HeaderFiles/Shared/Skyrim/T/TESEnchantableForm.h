#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/M/MagicSystem.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class EnchantmentItem;

	class TESEnchantableForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESEnchantableForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual MagicSystem::CastingType GetCastingType() const; // 4

		// Member variables
		EnchantmentItem*                                              enchantment;       // 8
		Utility::Enumeration<MagicSystem::CastingType, std::uint16_t> castingType;       // 10
		std::uint16_t                                                 enchantmentAmount; // 12
		std::int32_t                                                  padding14;         // 14
	};
	static_assert(offsetof(TESEnchantableForm, enchantment) == 0x8);
	static_assert(offsetof(TESEnchantableForm, castingType) == 0x10);
	static_assert(offsetof(TESEnchantableForm, enchantmentAmount) == 0x12);
	static_assert(sizeof(TESEnchantableForm) == 0x18);
}
