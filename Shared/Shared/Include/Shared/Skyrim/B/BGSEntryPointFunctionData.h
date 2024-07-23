#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class BGSEntryPointFunctionData
	{
	public:
		enum class EntryPointFunctionData : std::uint32_t
		{
			kInvalid              = 0,
			kOneValue             = 1,
			kTwoValue             = 2,
			kLeveledList          = 3,
			kActivateChoice       = 4,
			kSpellItem            = 5,
			kBooleanGraphVariable = 6,
			kText                 = 7
		};
		static_assert(sizeof(EntryPointFunctionData) == 0x4);

		// Add
		virtual ~BGSEntryPointFunctionData();                                     // 0
		virtual EntryPointFunctionData GetEntryPointFunctionDataType() const = 0; // 1
		virtual void                   Unknown2(BGSEntryPointFunctionData*)  = 0; // 2
		virtual void                   Unknown3(BGSEntryPointFunctionData*);      // 3
		virtual void                   Unknown4(BGSEntryPointFunctionData*);      // 4
		virtual void                   Unknown5(BGSEntryPointFunctionData*);      // 5
		virtual void                   Unknown6(BGSEntryPointFunctionData*);      // 6
		virtual void                   Unknown7(BGSEntryPointFunctionData*);      // 7
	};
	static_assert(sizeof(BGSEntryPointFunctionData) == 0x8);
}
