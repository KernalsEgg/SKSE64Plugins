#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSEntryPointFunctionData.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSPerk;
	class SpellItem;

	class BGSEntryPointFunctionDataActivateChoice :
		public BGSEntryPointFunctionData // 0
	{
	public:
		enum class Flags : std::uint16_t
		{
			kNone           = 0,
			kRunImmediately = 1U << 0,
			kReplaceDefault = 1U << 1
		};
		static_assert(sizeof(Flags) == 0x2);

		// Override
		virtual ~BGSEntryPointFunctionDataActivateChoice() override; // 0

		// Override (BGSEntryPointFunctionData)
		virtual Type GetType() const override;                      // 1
		virtual void Unknown2(BGSEntryPointFunctionData*) override; // 2
		virtual void Unknown3(BGSEntryPointFunctionData*) override; // 3
		virtual void Unknown5(BGSEntryPointFunctionData*) override; // 5
		virtual void Unknown6(BGSEntryPointFunctionData*) override; // 6
		virtual void Unknown7(BGSEntryPointFunctionData*) override; // 7

		// Member variables
		BSFixedString                              buttonLabel;         // 8
		BGSPerk*                                   perk;                // 10
		SpellItem*                                 applySpell;          // 18
		Utility::Enumeration<Flags, std::uint16_t> activateChoiceFlags; // 20
		std::int16_t                               unknown22;           // 22
		std::int32_t                               padding24;           // 24
	};
	static_assert(offsetof(BGSEntryPointFunctionDataActivateChoice, buttonLabel) == 0x8);
	static_assert(offsetof(BGSEntryPointFunctionDataActivateChoice, perk) == 0x10);
	static_assert(offsetof(BGSEntryPointFunctionDataActivateChoice, applySpell) == 0x18);
	static_assert(offsetof(BGSEntryPointFunctionDataActivateChoice, activateChoiceFlags) == 0x20);
	static_assert(sizeof(BGSEntryPointFunctionDataActivateChoice) == 0x28);
}
