#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEquipType.h"
#include "Shared/Skyrim/B/BGSMenuDisplayObject.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/M/MagicSystem.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class Actor;
	class BGSPerk;

	class SpellItem :
		public MagicItem,            // 0
		public BGSEquipType,         // 90
		public BGSMenuDisplayObject, // A0
		public TESDescription        // B0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                       = 0,
			kCostOverridden             = 1U << 0,
			kPlayerStartSpell           = 1U << 17,
			kAreaEffectIgnoresLOS       = 1U << 19,
			kIgnoreResistance           = 1U << 20,
			kDisallowSpellAbsorbReflect = 1U << 21,
			kNoDualCastModifications    = 1U << 23
		};
		static_assert(sizeof(Flags) == 0x4);

		struct Data
		{
		public:
			// Member variables
			std::int32_t                                                  spellCost;      // 0
			Utility::Enumeration<Flags, std::uint32_t>                    spellItemFlags; // 4
			Utility::Enumeration<MagicSystem::SpellType, std::uint32_t>   spellType;      // 8
			float                                                         chargeTime;     // C
			Utility::Enumeration<MagicSystem::CastingType, std::uint32_t> castingType;    // 10
			Utility::Enumeration<MagicSystem::Delivery, std::uint32_t>    delivery;       // 14
			float                                                         castDuration;   // 18
			float                                                         range;          // 1C
			BGSPerk*                                                      castingPerk;    // 20
		};
		static_assert(offsetof(Data, spellCost) == 0x0);
		static_assert(offsetof(Data, spellItemFlags) == 0x4);
		static_assert(offsetof(Data, spellType) == 0x8);
		static_assert(offsetof(Data, chargeTime) == 0xC);
		static_assert(offsetof(Data, castingType) == 0x10);
		static_assert(offsetof(Data, delivery) == 0x14);
		static_assert(offsetof(Data, castDuration) == 0x18);
		static_assert(offsetof(Data, range) == 0x1C);
		static_assert(offsetof(Data, castingPerk) == 0x20);
		static_assert(sizeof(Data) == 0x28);

		// Override
		virtual ~SpellItem() override; // 0

		// Override (MagicItem)
		virtual void                     InitializeData() override;                                                   // 4
		virtual void                     ClearData() override;                                                        // 5
		virtual void                     Unknown13(TESForm*) override;                                                // 13
		virtual MagicSystem::SpellType   GetSpellType() const override;                                               // 53
		virtual void                     Unknown54(MagicItem*) override;                                              // 54
		virtual MagicSystem::CastingType GetCastingType() const override;                                             // 55
		virtual void                     Unknown56(MagicItem*) override;                                              // 56
		virtual MagicSystem::Delivery    GetDelivery() const override;                                                // 57
		virtual void                     Unknown59(MagicItem*) override;                                              // 59
		virtual void                     Unknown5A(MagicItem*) override;                                              // 5A
		virtual void                     Unknown5B(MagicItem*) override;                                              // 5B
		virtual void                     Unknown5C(MagicItem*) override;                                              // 5C
		virtual void                     Unknown5E(MagicItem*) override;                                              // 5E
		virtual void                     Unknown5F(MagicItem*) override;                                              // 5F
		virtual bool                     GetSkillUsageData(MagicItem::SkillUsageData& skillUsageData) const override; // 60
		virtual void                     Unknown63(MagicItem*) override;                                              // 63
		virtual void                     Unknown64(MagicItem*) override;                                              // 64
		virtual void                     Unknown66(MagicItem*) override;                                              // 66
		virtual void                     Unknown67(MagicItem*) override;                                              // 67
		virtual void                     Unknown68(MagicItem*) override;                                              // 68
		virtual void                     Unknown69(MagicItem*) override;                                              // 69
		virtual void                     Unknown6A(MagicItem*) override;                                              // 6A
		virtual void                     Unknown6B(MagicItem*) override;                                              // 6B
		virtual const MagicItem::Data*   GetConstantData() const override;                                            // 6C
		virtual MagicItem::Data*         GetData() override;                                                          // 6D
		virtual std::uint32_t            GetDataSize() const override;                                                // 6E
		virtual void                     Unknown6F(MagicItem*) override;                                              // 6F
		virtual void                     Unknown70(MagicItem*) override;                                              // 70

		// Override (BGSMenuDisplayObject)
		virtual TESBoundObject* GetMenuDisplayObject() const override; // 4

		// Member functions
		void Apply(Actor* target, Actor* caster);

		// Member variables
		Data spellItemData; // C0
	};
	static_assert(offsetof(SpellItem, spellItemData) == 0xC0);
	static_assert(sizeof(SpellItem) == 0xE8);
}
