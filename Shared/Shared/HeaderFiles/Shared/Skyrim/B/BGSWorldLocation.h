#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiPoint3.h"



namespace Skyrim
{
	class TESForm;

	struct BGSWorldLocation
	{
	public:
		// Member variables
		NiPoint3 position;         // 0
		TESForm* cellOrWorldSpace; // 10
	};
	static_assert(offsetof(BGSWorldLocation, position) == 0x0);
	static_assert(offsetof(BGSWorldLocation, cellOrWorldSpace) == 0x10);
	static_assert(sizeof(BGSWorldLocation) == 0x18);
}
