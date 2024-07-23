#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPointFunction.h"



namespace Skyrim
{
	class Actor;
	class BGSEntryPointFunctionData;
	class TESForm;

	class BGSPerkEntry
	{
	public:
		enum class PerkEntryType : std::uint32_t
		{
			kQuest      = 0,
			kAbility    = 1,
			kEntryPoint = 2
		};
		static_assert(sizeof(PerkEntryType) == 0x4);

		// Add
		virtual bool                                      CheckConditionFilters(std::uint32_t argumentCount, TESForm** arguments) const; // 0
		virtual BGSEntryPointFunction::EntryPointFunction GetEntryPointFunction() const;                                                 // 1
		virtual BGSEntryPointFunctionData*                GetEntryPointFunctionData() const;                                             // 2
		virtual ~BGSPerkEntry();                                                                                                         // 3
		virtual PerkEntryType GetPerkEntryType() const = 0;                                                                              // 4
		virtual void          Unknown5(BGSPerkEntry*);                                                                                   // 5
		virtual void          Unknown6(BGSPerkEntry*);                                                                                   // 6
		virtual void          Unknown7(BGSPerkEntry*);                                                                                   // 7
		virtual void          Unknown8(BGSPerkEntry*);                                                                                   // 8
		virtual void          Unknown9(BGSPerkEntry*);                                                                                   // 9
		virtual void          ApplyPerkEntry(Actor* perkOwner)  = 0;                                                                     // A
		virtual void          RemovePerkEntry(Actor* perkOwner) = 0;                                                                     // B

		// Member variables
		std::uint8_t  rank;     // 8
		std::uint8_t  priority; // 9
		std::uint16_t paddingA; // A
		std::uint32_t paddingC; // C
	};
	static_assert(offsetof(BGSPerkEntry, rank) == 0x8);
	static_assert(offsetof(BGSPerkEntry, priority) == 0x9);
	static_assert(sizeof(BGSPerkEntry) == 0x10);
}
