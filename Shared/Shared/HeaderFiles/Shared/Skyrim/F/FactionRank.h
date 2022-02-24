#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class TESFaction;

	struct FactionRank
	{
		TESFaction*   faction;  // 0
		std::int8_t   rank;     // 8
		std::uint8_t  padding9; // 9
		std::uint16_t paddingA; // A
		std::uint32_t paddingC; // C
	};
	static_assert(offsetof(FactionRank, faction) == 0x0);
	static_assert(offsetof(FactionRank, rank) == 0x8);
	static_assert(sizeof(FactionRank) == 0x10);
}
