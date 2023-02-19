#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace SKSE
{
	struct CrosshairReferenceEvent
	{
	public:
		Skyrim::NiPointer<Skyrim::TESObjectREFR> crosshairReference;
	};
	static_assert(offsetof(CrosshairReferenceEvent, crosshairReference) == 0x0);
	static_assert(sizeof(CrosshairReferenceEvent) == 0x8);
}
