#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class BGSPerkEntry;

	class PerkEntryVisitor
	{
	public:
		enum class ReturnType : std::uint32_t
		{
			kStop     = 0,
			kContinue = 1
		};
		static_assert(sizeof(ReturnType) == 0x4);

		// Add
		virtual ReturnType Visit(BGSPerkEntry* perkEntry) = 0; // 0
	};
	static_assert(sizeof(PerkEntryVisitor) == 0x8);
}
