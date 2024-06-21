#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSPickupPutdownSounds.h"
#include "Shared/Skyrim/S/SpellItem.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESValueForm.h"
#include "Shared/Skyrim/T/TESWeightForm.h"



namespace Skyrim
{
	class ScrollItem :
		public SpellItem,                 // 0
		public TESModelTextureSwap,       // E8
		public BGSDestructibleObjectForm, // 120
		public BGSPickupPutdownSounds,    // 130
		public TESWeightForm,             // 148
		public TESValueForm               // 158
	{
	public:
		// Override
		virtual ~ScrollItem() override; // 0

		// Override (SpellItem)
		virtual void                     Unknown13(TESForm*) override;                                     // 13
		virtual MagicSystem::SpellType   GetSpellType() const override;                                    // 53
		virtual MagicSystem::CastingType GetCastingType() const override;                                  // 55
		virtual bool                     GetSkillUsageData(SkillUsageData& skillUsageData) const override; // 60
		virtual void                     Unknown66(MagicItem*) override;                                   // 66
		virtual void                     Unknown6A(MagicItem*) override;                                   // 6A
	};
	static_assert(sizeof(ScrollItem) == 0x168);
}
