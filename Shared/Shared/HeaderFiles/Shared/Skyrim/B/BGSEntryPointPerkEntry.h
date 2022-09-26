#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BGSPerkEntry.h"
#include "Shared/Skyrim/S/SimpleArray.h"
#include "Shared/Skyrim/T/TESCondition.h"
#include "Shared/Utility/Enumeration.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	class Actor;
	class BGSEntryPointFunctionData;
	class BGSPerk;

	class BGSEntryPointPerkEntry :
		public BGSPerkEntry // 0
	{
	public:
		// Override
		virtual ~BGSEntryPointPerkEntry() override; // 3

		// Override (BGSPerkEntry)
		virtual bool     EvaluateConditions(std::uint32_t argumentCount, void* arguments) const override; // 0
		virtual Function GetFunction() const override;                                                    // 1
		virtual void*    GetFunctionData() const override;                                                // 2
		virtual Type     GetType() const override;                                                        // 4
		virtual void     Unknown5(BGSPerkEntry*) override;                                                // 5
		virtual void     Unknown6(BGSPerkEntry*) override;                                                // 6
		virtual void     Unknown7(BGSPerkEntry*) override;                                                // 7
		virtual void     Unknown8(BGSPerkEntry*) override;                                                // 8
		virtual void     Unknown9(BGSPerkEntry*) override;                                                // 9
		virtual void     ApplyPerkEntry(Actor* perkOwner) override;                                       // A
		virtual void     RemovePerkEntry(Actor* perkOwner) override;                                      // B

		// Non-member functions
		template <class... Arguments>
		static void HandleEntryPoint(Utility::Enumeration<BGSPerkEntry::EntryPoint, std::uint32_t> entryPoint, Actor* perkOwner, Arguments... arguments)
		{
			auto* function{ reinterpret_cast<decltype(&BGSEntryPointPerkEntry::HandleEntryPoint<Arguments...>)>(Addresses::BGSEntryPointPerkEntry::HandleEntryPoint) };

			function(entryPoint, perkOwner, arguments...);
		}

		// Member variables
		Utility::Enumeration<EntryPoint, std::uint8_t> entryPoint;    // 10
		Utility::Enumeration<Function, std::uint8_t>   function;      // 11
		std::uint8_t                                   argumentCount; // 12
		std::uint8_t                                   unknown13;     // 13
		std::uint32_t                                  unknown14;     // 14
		BGSEntryPointFunctionData*                     functionData;  // 18
		SimpleArray<TESCondition>                      conditions;    // 20
		BGSPerk*                                       perk;          // 28
	};
	static_assert(offsetof(BGSEntryPointPerkEntry, entryPoint) == 0x10);
	static_assert(offsetof(BGSEntryPointPerkEntry, function) == 0x11);
	static_assert(offsetof(BGSEntryPointPerkEntry, argumentCount) == 0x12);
	static_assert(offsetof(BGSEntryPointPerkEntry, functionData) == 0x18);
	static_assert(offsetof(BGSEntryPointPerkEntry, conditions) == 0x20);
	static_assert(offsetof(BGSEntryPointPerkEntry, perk) == 0x28);
	static_assert(sizeof(BGSEntryPointPerkEntry) == 0x30);
}
