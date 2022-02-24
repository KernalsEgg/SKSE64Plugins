#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/C/CombatReaction.h"
#include "Shared/Skyrim/F/FormType.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESForm;

	class TESReactionForm :
		public BaseFormComponent // 0
	{
	public:
		struct GroupCombatReaction
		{
		public:
			// Member variables
			TESForm*                                            group;          // 0
			std::int32_t                                        modifier;       // 8
			Utility::Enumeration<CombatReaction, std::uint32_t> combatReaction; // C
		};
		static_assert(offsetof(GroupCombatReaction, group) == 0x0);
		static_assert(offsetof(GroupCombatReaction, modifier) == 0x8);
		static_assert(offsetof(GroupCombatReaction, combatReaction) == 0xC);
		static_assert(sizeof(GroupCombatReaction) == 0x10);

		// Override
		virtual ~TESReactionForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		BSSimpleList<GroupCombatReaction*>           groupCombatReaction; // 8
		Utility::Enumeration<FormType, std::uint8_t> groupFormType;       // 18
		std::uint8_t                                 padding19;           // 19
		std::uint16_t                                padding1A;           // 1A
		std::uint32_t                                padding1C;           // 1C
	};
	static_assert(offsetof(TESReactionForm, groupCombatReaction) == 0x8);
	static_assert(offsetof(TESReactionForm, groupFormType) == 0x18);
	static_assert(sizeof(TESReactionForm) == 0x20);
}
