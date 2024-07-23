#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSEntryPointFunctionData;
	class TESObjectREFR;

	namespace BGSEntryPointFunction
	{
		enum class EntryPointFunction : std::uint32_t
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
		static_assert(sizeof(EntryPointFunction) == 0x4);

		enum class EntryPointFunctionType : std::uint32_t
		{
			kValue                = 0,
			kLeveledList          = 1,
			kActivateChoice       = 2,
			kSpellItem            = 4,
			kBooleanGraphVariable = 5,
			kText                 = 6
		};
		static_assert(sizeof(EntryPointFunctionType) == 0x4);

		void ExecuteFunction(
			Utility::Enumeration<EntryPointFunction, std::uint32_t>     entryPointFunction,
			TESObjectREFR*                                              perkOwner,
			Utility::Enumeration<EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
			std::uint8_t                                                entryPointFunctionArgumentCount,
			void**                                                      entryPointFunctionArguments,
			BGSEntryPointFunctionData*                                  entryPointFunctionData);
		std::uint32_t GetEntryPointFunctionArgumentCount(Utility::Enumeration<EntryPointFunctionType, std::uint32_t> entryPointFunctionType);
	}
}
