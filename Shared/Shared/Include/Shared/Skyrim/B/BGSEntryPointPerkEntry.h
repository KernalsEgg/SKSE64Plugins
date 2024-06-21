#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPoint.h"
#include "Shared/Skyrim/B/BGSPerkEntry.h"
#include "Shared/Skyrim/S/SimpleArray.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSEntryPointFunctionData;
	class BGSPerk;
	class TESCondition;

	class BGSEntryPointPerkEntry :
		public BGSPerkEntry // 0
	{
	public:
		// Override
		virtual ~BGSEntryPointPerkEntry() override; // 3

		// Override (BGSPerkEntry)
		virtual bool                                      CheckConditionFilters(std::uint32_t argumentCount, TESForm** arguments) const override; // 0
		virtual BGSEntryPointFunction::EntryPointFunction GetFunction() const override;                                                           // 1
		virtual BGSEntryPointFunctionData*                GetFunctionData() const override;                                                       // 2
		virtual PerkEntryType                             GetType() const override;                                                               // 4
		virtual void                                      Unknown5(BGSPerkEntry*) override;                                                       // 5
		virtual void                                      Unknown6(BGSPerkEntry*) override;                                                       // 6
		virtual void                                      Unknown7(BGSPerkEntry*) override;                                                       // 7
		virtual void                                      Unknown8(BGSPerkEntry*) override;                                                       // 8
		virtual void                                      Unknown9(BGSPerkEntry*) override;                                                       // 9
		virtual void                                      ApplyPerkEntry(Actor* perkOwner) override;                                              // A
		virtual void                                      RemovePerkEntry(Actor* perkOwner) override;                                             // B

		// Member variables
		Utility::Enumeration<BGSEntryPoint::EntryPoint, std::uint8_t>                 entryPoint;             // 10
		Utility::Enumeration<BGSEntryPointFunction::EntryPointFunction, std::uint8_t> entryPointFunction;     // 11
		std::uint8_t                                                                  argumentCount;          // 12
		std::uint8_t                                                                  unknown13;              // 13
		std::uint32_t                                                                 unknown14;              // 14
		BGSEntryPointFunctionData*                                                    entryPointFunctionData; // 18
		SimpleArray<TESCondition>                                                     conditions;             // 20
		BGSPerk*                                                                      perk;                   // 28
	};
	static_assert(offsetof(BGSEntryPointPerkEntry, entryPoint) == 0x10);
	static_assert(offsetof(BGSEntryPointPerkEntry, entryPointFunction) == 0x11);
	static_assert(offsetof(BGSEntryPointPerkEntry, argumentCount) == 0x12);
	static_assert(offsetof(BGSEntryPointPerkEntry, entryPointFunctionData) == 0x18);
	static_assert(offsetof(BGSEntryPointPerkEntry, conditions) == 0x20);
	static_assert(offsetof(BGSEntryPointPerkEntry, perk) == 0x28);
	static_assert(sizeof(BGSEntryPointPerkEntry) == 0x30);
}
