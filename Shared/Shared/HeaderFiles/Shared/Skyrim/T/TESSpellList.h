#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class SpellItem;
	class TESLevSpell;
	class TESShout;

	class TESSpellList :
		public BaseFormComponent // 0
	{
	public:
		struct SpellList
		{
		public:
			// Member variables
			SpellItem**   spells;            // 0
			TESLevSpell** leveledSpells;     // 8
			TESShout**    shouts;            // 10
			std::uint32_t spellCount;        // 18
			std::uint32_t leveledSpellCount; // 1C
			std::uint32_t shoutCount;        // 20
			std::uint32_t padding24;         // 24
		};
		static_assert(offsetof(SpellList, spells) == 0x0);
		static_assert(offsetof(SpellList, leveledSpells) == 0x8);
		static_assert(offsetof(SpellList, shouts) == 0x10);
		static_assert(offsetof(SpellList, spellCount) == 0x18);
		static_assert(offsetof(SpellList, leveledSpellCount) == 0x1C);
		static_assert(offsetof(SpellList, shoutCount) == 0x20);
		static_assert(sizeof(SpellList) == 0x28);

		// Override
		virtual ~TESSpellList() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		SpellList* spellList; // 8
	};
	static_assert(offsetof(TESSpellList, spellList) == 0x8);
	static_assert(sizeof(TESSpellList) == 0x10);
}
