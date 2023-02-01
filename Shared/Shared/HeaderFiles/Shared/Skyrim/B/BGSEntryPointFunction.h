#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	namespace BGSEntryPointFunction
	{
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

		std::uint32_t GetEntryPointFunctionTypeArgumentCount(Utility::Enumeration<EntryPointFunctionType, std::uint32_t> entryPointFunctionType);
	}
}
