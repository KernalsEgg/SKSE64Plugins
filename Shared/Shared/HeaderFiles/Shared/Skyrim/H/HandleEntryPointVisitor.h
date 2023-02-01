#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPointFunction.h"
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
		Utility::Enumeration<BGSEntryPointFunction::EntryPointFunctionType, std::uint32_t> entryPointFunctionType;              // 8
		std::uint32_t                                                                      paddingC;                            // C
		void*                                                                              entryPointPerkEntryArguments;        // 10
		void*                                                                              entryPointFunctionTypeArguments;     // 18
		Actor*                                                                             perkOwner;                           // 20
		std::uint8_t                                                                       entryPointPerkEntryArgumentCount;    // 28
		std::uint8_t                                                                       entryPointFunctionTypeArgumentCount; // 29
		std::uint16_t                                                                      padding2A;                           // 2A
		std::uint32_t                                                                      padding2C;                           // 2C
	};
	static_assert(offsetof(HandleEntryPointVisitor, entryPointFunctionType) == 0x8);
	static_assert(offsetof(HandleEntryPointVisitor, entryPointPerkEntryArguments) == 0x10);
	static_assert(offsetof(HandleEntryPointVisitor, entryPointFunctionTypeArguments) == 0x18);
	static_assert(offsetof(HandleEntryPointVisitor, perkOwner) == 0x20);
	static_assert(offsetof(HandleEntryPointVisitor, entryPointPerkEntryArgumentCount) == 0x28);
	static_assert(offsetof(HandleEntryPointVisitor, entryPointFunctionTypeArgumentCount) == 0x29);
	static_assert(sizeof(HandleEntryPointVisitor) == 0x30);
}
