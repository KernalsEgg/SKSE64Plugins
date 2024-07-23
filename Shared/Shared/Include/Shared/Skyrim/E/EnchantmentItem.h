#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/M/MagicSystem.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSListForm;

	class EnchantmentItem :
		public MagicItem // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                   = 0,
			kCostOverridden         = 1U << 0,
			kExtendDurationOnRecast = 1U << 2
		};
		static_assert(sizeof(Flags) == 0x4);

		struct Data
		{
		public:
			// Member variables
			std::int32_t                                                  enchantmentCost;      // 0
			Utility::Enumeration<Flags, std::uint32_t>                    enchantmentItemFlags; // 4
			Utility::Enumeration<MagicSystem::CastingType, std::uint32_t> castingType;          // 8
			std::int32_t                                                  enchantmentAmount;    // C
			Utility::Enumeration<MagicSystem::Delivery, std::uint32_t>    delivery;             // 10
			Utility::Enumeration<MagicSystem::SpellType, std::uint32_t>   spellType;            // 14
			float                                                         chargeTime;           // 18
			std::uint32_t                                                 padding1C;            // 1C
			EnchantmentItem*                                              baseEnchantmentItem;  // 20
			BGSListForm*                                                  wornRestrictions;     // 28
		};
		static_assert(offsetof(Data, enchantmentCost) == 0x0);
		static_assert(offsetof(Data, enchantmentItemFlags) == 0x4);
		static_assert(offsetof(Data, castingType) == 0x8);
		static_assert(offsetof(Data, enchantmentAmount) == 0xC);
		static_assert(offsetof(Data, delivery) == 0x10);
		static_assert(offsetof(Data, spellType) == 0x14);
		static_assert(offsetof(Data, chargeTime) == 0x18);
		static_assert(offsetof(Data, baseEnchantmentItem) == 0x20);
		static_assert(offsetof(Data, wornRestrictions) == 0x28);
		static_assert(sizeof(Data) == 0x30);

		// Override
		virtual ~EnchantmentItem() override; // 0

		// Override (MagicItem)
		virtual void                     InitializeData() override;        // 4
		virtual void                     ClearData() override;             // 5
		virtual void                     Unknown13(TESForm*) override;     // 13
		virtual MagicSystem::SpellType   GetSpellType() const override;    // 53
		virtual void                     Unknown54(MagicItem*) override;   // 54
		virtual MagicSystem::CastingType GetCastingType() const override;  // 55
		virtual void                     Unknown56(MagicItem*) override;   // 56
		virtual MagicSystem::Delivery    GetDelivery() const override;     // 57
		virtual void                     Unknown64(MagicItem*) override;   // 64
		virtual void                     Unknown66(MagicItem*) override;   // 66
		virtual void                     Unknown68(MagicItem*) override;   // 68
		virtual void                     Unknown69(MagicItem*) override;   // 69
		virtual const MagicItem::Data*   GetConstantData() const override; // 6C
		virtual MagicItem::Data*         GetData() override;               // 6D
		virtual std::uint32_t            GetDataSize() const override;     // 6E
		virtual void                     Unknown6F(MagicItem*) override;   // 6F
		virtual void                     Unknown70(MagicItem*) override;   // 70

		// Non-member functions
		static float ModifyPower(float power, float enchantingSkill);

		// Member variables
		Data enchantmentItemData; // 90
	};
	static_assert(offsetof(EnchantmentItem, enchantmentItemData) == 0x90);
	static_assert(sizeof(EnchantmentItem) == 0xC0);
}
