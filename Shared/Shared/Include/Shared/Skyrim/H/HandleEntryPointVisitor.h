#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPointFunction.h"
#include "Shared/Skyrim/P/PerkEntryVisitor.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class Actor;
	class TESForm;

	class HandleEntryPointVisitor :
		public PerkEntryVisitor // 0
	{
	public:
		// Override (PerkEntryVisitor)
		virtual ForEachResult operator()(BGSPerkEntry* perkEntry) override; // 0

		HandleEntryPointVisitor()                               = delete;
		HandleEntryPointVisitor(const HandleEntryPointVisitor&) = delete;
		HandleEntryPointVisitor(HandleEntryPointVisitor&&)      = delete;

		~HandleEntryPointVisitor() = default;

		HandleEntryPointVisitor& operator=(const HandleEntryPointVisitor&) = delete;
		HandleEntryPointVisitor& operator=(HandleEntryPointVisitor&&)      = delete;

		HandleEntryPointVisitor(
			Utility::Enumeration<BGSEntryPointFunction::EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
			TESForm**                                                                          conditionFilterArguments,
			void**                                                                             entryPointFunctionArguments,
			Actor*                                                                             perkOwner,
			std::uint8_t                                                                       conditionFilterArgumentCount,
			std::uint8_t                                                                       entryPointFunctionArgumentCount);

		// Member variables
		Utility::Enumeration<BGSEntryPointFunction::EntryPointFunctionType, std::uint32_t> entryPointFunctionType;          // 8
		TESForm**                                                                          conditionFilterArguments;        // 10
		void**                                                                             entryPointFunctionArguments;     // 18
		Actor*                                                                             perkOwner;                       // 20
		std::uint8_t                                                                       conditionFilterArgumentCount;    // 28
		std::uint8_t                                                                       entryPointFunctionArgumentCount; // 29
	};
	static_assert(offsetof(HandleEntryPointVisitor, entryPointFunctionType) == 0x8);
	static_assert(offsetof(HandleEntryPointVisitor, conditionFilterArguments) == 0x10);
	static_assert(offsetof(HandleEntryPointVisitor, entryPointFunctionArguments) == 0x18);
	static_assert(offsetof(HandleEntryPointVisitor, perkOwner) == 0x20);
	static_assert(offsetof(HandleEntryPointVisitor, conditionFilterArgumentCount) == 0x28);
	static_assert(offsetof(HandleEntryPointVisitor, entryPointFunctionArgumentCount) == 0x29);
	static_assert(sizeof(HandleEntryPointVisitor) == 0x30);
}
