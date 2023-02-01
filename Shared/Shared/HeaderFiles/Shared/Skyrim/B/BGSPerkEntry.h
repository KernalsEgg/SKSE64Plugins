#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class Actor;

	class BGSPerkEntry
	{
	public:
		enum class PerkEntryFunction : std::uint32_t
		{
			kSetValue                          = 1,
			kAddValue                          = 2,
			kMultiplyValue                     = 3,
			kAddRangeToValue                   = 4,
			kAddActorValueMultiple             = 5,
			kAbsoluteValue                     = 6,
			kNegativeAbsoluteValue             = 7,
			kAddLeveledList                    = 8,
			kAddActivateChoice                 = 9,
			kSelectSpell                       = 10,
			kSelectText                        = 11,
			kSetToActorValueMultiple           = 12,
			kMultiplyActorValueMultiple        = 13,
			kMultiplyOnePlusActorValueMultiple = 14,
			kSetText                           = 15
		};
		static_assert(sizeof(PerkEntryFunction) == 0x4);

		enum class PerkEntryType : std::uint32_t
		{
			kQuest      = 0,
			kAbility    = 1,
			kEntryPoint = 2
		};
		static_assert(sizeof(PerkEntryType) == 0x4);

		// Add
		virtual bool              EvaluateConditions(std::uint32_t argumentCount, void* arguments) const; // 0
		virtual PerkEntryFunction GetFunction() const;                                                    // 1
		virtual void*             GetFunctionData() const;                                                // 2
		virtual ~BGSPerkEntry();                                                                          // 3
		virtual PerkEntryType GetType() const = 0;                                                        // 4
		virtual void          Unknown5(BGSPerkEntry*);                                                    // 5
		virtual void          Unknown6(BGSPerkEntry*);                                                    // 6
		virtual void          Unknown7(BGSPerkEntry*);                                                    // 7
		virtual void          Unknown8(BGSPerkEntry*);                                                    // 8
		virtual void          Unknown9(BGSPerkEntry*);                                                    // 9
		virtual void          ApplyPerkEntry(Actor* perkOwner)  = 0;                                      // A
		virtual void          RemovePerkEntry(Actor* perkOwner) = 0;                                      // B

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
