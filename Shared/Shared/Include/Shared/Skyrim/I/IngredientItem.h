#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSEquipType.h"
#include "Shared/Skyrim/B/BGSPickupPutdownSounds.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/T/TESIcon.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESValueForm.h"
#include "Shared/Skyrim/T/TESWeightForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class IngredientItem :
		public MagicItem,                 // 0
		public TESModelTextureSwap,       // 90
		public TESIcon,                   // C8
		public TESWeightForm,             // D8
		public BGSEquipType,              // E8
		public BGSDestructibleObjectForm, // F8
		public BGSPickupPutdownSounds,    // 108
		public TESValueForm               // 120
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone              = 0,
			kCostOverridden    = 1U << 0,
			kFoodItem          = 1U << 1,
			kReferencesPersist = 1U << 8
		};
		static_assert(sizeof(Flags) == 0x4);

		struct Data
		{
		public:
			// Member variables
			std::int32_t                               ingredientValue;     // 0
			Utility::Enumeration<Flags, std::uint32_t> ingredientItemFlags; // 4
		};
		static_assert(offsetof(Data, ingredientValue) == 0x0);
		static_assert(offsetof(Data, ingredientItemFlags) == 0x4);
		static_assert(sizeof(Data) == 0x8);

		// Override
		virtual ~IngredientItem() override; // 0

		// Override (MagicItem)
		virtual void                     InitializeData() override;                                                   // 4
		virtual void                     ClearData() override;                                                        // 5
		virtual void                     SaveGame(BGSSaveFormBuffer* saveFormBuffer) override;                        // E
		virtual void                     LoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                        // F
		virtual void                     Revert(BGSLoadFormBuffer* loadFormBuffer) override;                          // 12
		virtual void                     Unknown13(TESForm*) override;                                                // 13
		virtual MagicSystem::SpellType   GetSpellType() const override;                                               // 53
		virtual MagicSystem::CastingType GetCastingType() const override;                                             // 55
		virtual MagicSystem::Delivery    GetDelivery() const override;                                                // 57
		virtual bool                     IsFood() const override;                                                     // 5D
		virtual bool                     GetSkillUsageData(MagicItem::SkillUsageData& skillUsageData) const override; // 60
		virtual void                     Unknown65(MagicItem*) override;                                              // 65
		virtual void                     Unknown66(MagicItem*) override;                                              // 66
		virtual void                     Unknown68(MagicItem*) override;                                              // 68
		virtual void                     Unknown69(MagicItem*) override;                                              // 69
		virtual void                     Unknown6A(MagicItem*) override;                                              // 6A
		virtual const MagicItem::Data*   GetConstantData() const override;                                            // 6C
		virtual MagicItem::Data*         GetData() override;                                                          // 6D
		virtual std::uint32_t            GetDataSize() const override;                                                // 6E
		virtual void                     Unknown6F(MagicItem*) override;                                              // 6F
		virtual void                     Unknown70(MagicItem*) override;                                              // 70

		// Override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override; // 5

		// Member variables
		Data          ingredientItemData; // 130
		std::uint32_t unknown138;         // 138
		std::uint32_t padding13C;         // 13C
	};
	static_assert(offsetof(IngredientItem, ingredientItemData) == 0x130);
	static_assert(sizeof(IngredientItem) == 0x140);
}
