#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSEquipType.h"
#include "Shared/Skyrim/B/BGSMessageIcon.h"
#include "Shared/Skyrim/B/BGSPickupPutdownSounds.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/T/TESIcon.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESWeightForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSSoundDescriptorForm;
	class SpellItem;

	class AlchemyItem :
		public MagicItem,                 // 0
		public TESModelTextureSwap,       // 90
		public TESIcon,                   // C8
		public BGSMessageIcon,            // D8
		public TESWeightForm,             // F0
		public BGSEquipType,              // 100
		public BGSDestructibleObjectForm, // 110
		public BGSPickupPutdownSounds     // 120
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                       = 0,
			kDontAutomaticallyCalculate = 1U << 0,
			kFoodItem                   = 1U << 1,
			kMedicine                   = 1U << 16,
			kPoison                     = 1U << 17
		};
		static_assert(sizeof(Flags) == 0x4);

		struct Data
		{
		public:
			// Member variables
			std::int32_t                               potionValue;      // 0
			Utility::Enumeration<Flags, std::uint32_t> alchemyItemFlags; // 4
			SpellItem*                                 addiction;        // 8
			float                                      addictionChance;  // 10
			std::uint32_t                              padding14;        // 14
			BGSSoundDescriptorForm*                    useSound;         // 18
		};
		static_assert(offsetof(Data, potionValue) == 0x0);
		static_assert(offsetof(Data, alchemyItemFlags) == 0x4);
		static_assert(offsetof(Data, addiction) == 0x8);
		static_assert(offsetof(Data, addictionChance) == 0x10);
		static_assert(offsetof(Data, useSound) == 0x18);
		static_assert(sizeof(Data) == 0x20);

		// Override
		virtual ~AlchemyItem() override; // 0

		// Override (MagicItem)
		virtual void                     InitializeData() override;       // 4
		virtual void                     ClearData() override;            // 5
		virtual void                     Unknown13(TESForm*) override;    // 13
		virtual MagicSystem::SpellType   GetSpellType() const override;   // 53
		virtual MagicSystem::CastingType GetCastingType() const override; // 55
		virtual MagicSystem::Delivery    GetDelivery() const override;    // 57
		virtual bool                     IsFood() const override;         // 5D
		virtual bool                     IsPoison() const override;       // 61
		virtual void                     Unknown62(MagicItem*) override;  // 62
		virtual void                     Unknown66(MagicItem*) override;  // 66
		virtual void                     Unknown68(MagicItem*) override;  // 68
		virtual void                     Unknown69(MagicItem*) override;  // 69
		virtual void                     Unknown6A(MagicItem*) override;  // 6A
		virtual const void*              GetData() const override;        // 6C
		virtual void*                    GetData() override;              // 6D
		virtual std::uint32_t            GetDataSize() const override;    // 6E
		virtual void                     Unknown6F(MagicItem*) override;  // 6F
		virtual void                     Unknown70(MagicItem*) override;  // 70

		// Override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override; // 5

		// Member variables
		Data    alchemyItemData; // 138
		TESIcon messageIcon;     // 158
	};
	static_assert(offsetof(AlchemyItem, alchemyItemData) == 0x138);
	static_assert(offsetof(AlchemyItem, messageIcon) == 0x158);
	static_assert(sizeof(AlchemyItem) == 0x168);
}
