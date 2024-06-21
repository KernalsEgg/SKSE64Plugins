#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"



namespace Skyrim
{
	struct BGSFootstepEvent
	{
	public:
		// Member variables
		ActorHandle   actor;    // 0
		std::uint32_t padding4; // 4
		BSFixedString tag;      // 8
	};
	static_assert(offsetof(BGSFootstepEvent, actor) == 0x0);
	static_assert(offsetof(BGSFootstepEvent, tag) == 0x8);
	static_assert(sizeof(BGSFootstepEvent) == 0x10);
}
