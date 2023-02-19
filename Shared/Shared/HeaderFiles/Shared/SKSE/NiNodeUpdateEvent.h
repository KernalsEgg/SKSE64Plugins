#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace SKSE
{
	struct NiNodeUpdateEvent
	{
	public:
		Skyrim::TESObjectREFR* reference;
	};
	static_assert(offsetof(NiNodeUpdateEvent, reference) == 0x0);
	static_assert(sizeof(NiNodeUpdateEvent) == 0x8);
}
