#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"



namespace Skyrim
{
	class TESObjectREFR;

	struct BSAnimationGraphEvent
	{
	public:
		// Member variables
		BSFixedString  tag;     // 0
		TESObjectREFR* holder;  // 8
		BSFixedString  payload; // 10
	};
	static_assert(offsetof(BSAnimationGraphEvent, tag) == 0x0);
	static_assert(offsetof(BSAnimationGraphEvent, holder) == 0x8);
	static_assert(offsetof(BSAnimationGraphEvent, payload) == 0x10);
	static_assert(sizeof(BSAnimationGraphEvent) == 0x18);
}
