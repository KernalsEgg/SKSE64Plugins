#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/ForEachResult.h"



namespace Skyrim
{
	class BGSPerkEntry;

	class PerkEntryVisitor
	{
	public:
		// Add
		virtual ForEachResult operator()(BGSPerkEntry* perkEntry) = 0; // 0
	};
	static_assert(sizeof(PerkEntryVisitor) == 0x8);
}
