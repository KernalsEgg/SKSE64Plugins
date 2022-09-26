#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPointFunctionData.h"
#include "Shared/Skyrim/P/PerkEntryVisitor.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class Actor;

	class HandleEntryPointVisitor :
		public PerkEntryVisitor // 0
	{
	public:
		// Override (PerkEntryVisitor)
		virtual PerkEntryVisitor::ReturnType Visit(BGSPerkEntry* perkEntry) override; // 0

		// Member variables
		Utility::Enumeration<BGSEntryPointFunctionData::ResultType, std::uint32_t> resultType;    // 8
		std::uint32_t                                                              paddingC;      // C
		void*                                                                      arguments;     // 10
		void*                                                                      results;       // 18
		Actor*                                                                     perkOwner;     // 20
		std::uint8_t                                                               argumentCount; // 28
		std::uint8_t                                                               resultCount;   // 29
		std::uint16_t                                                              padding2A;     // 2A
		std::uint32_t                                                              padding2C;     // 2C
	};
	static_assert(offsetof(HandleEntryPointVisitor, resultType) == 0x8);
	static_assert(offsetof(HandleEntryPointVisitor, arguments) == 0x10);
	static_assert(offsetof(HandleEntryPointVisitor, results) == 0x18);
	static_assert(offsetof(HandleEntryPointVisitor, perkOwner) == 0x20);
	static_assert(offsetof(HandleEntryPointVisitor, argumentCount) == 0x28);
	static_assert(offsetof(HandleEntryPointVisitor, resultCount) == 0x29);
	static_assert(sizeof(HandleEntryPointVisitor) == 0x30);
}
