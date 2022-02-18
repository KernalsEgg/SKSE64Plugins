#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSEquipType.h"
#include "Shared/Skyrim/B/BGSMenuDisplayObject.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class SpellItem;
	class TESWordOfPower;

	class TESShout :
		public TESForm,              // 0
		public TESFullName,          // 20
		public BGSMenuDisplayObject, // 30
		public BGSEquipType,         // 40
		public TESDescription        // 50
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kTreatSpellsAsPowers = 1U << 7
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		enum class WordNumber : std::uint32_t
		{
			kNone  = static_cast<std::underlying_type_t<WordNumber>>(-1),
			kOne   = 0,
			kTwo   = 1,
			kThree = 2,
			kTotal = 3
		};
		static_assert(sizeof(WordNumber) == 0x4);

		struct Word
		{
		public:
			// Member variables
			TESWordOfPower* word;         // 0
			SpellItem*      spell;        // 8
			float           recoveryTime; // 10
			std::int32_t    padding14;    // 14
		};
		static_assert(offsetof(Word, word) == 0x0);
		static_assert(offsetof(Word, spell) == 0x8);
		static_assert(offsetof(Word, recoveryTime) == 0x10);
		static_assert(sizeof(Word) == 0x18);

		// Override
		virtual ~TESShout() override; // 0

		// Override (TESForm)
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13
		virtual void Unknown17(TESForm*) override; // 17

		// Override (BGSEquipType)
		virtual BGSEquipSlot* GetEquipSlot() const override;                  // 4
		virtual void          SetEquipSlot(BGSEquipSlot* equipSlot) override; // 5

		// Member variables
		Word words[Utility::ToUnderlying(WordNumber::kTotal)]; // 60
	};
	static_assert(offsetof(TESShout, words) == 0x60);
	static_assert(sizeof(TESShout) == 0xA8);
}
