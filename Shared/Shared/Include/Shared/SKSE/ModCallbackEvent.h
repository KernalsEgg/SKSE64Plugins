#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace SKSE
{
	struct ModCallbackEvent
	{
	public:
		Skyrim::BSFixedString eventName;
		Skyrim::BSFixedString stringArgument;
		float                 numericalArgument;
		Skyrim::TESForm*      sender;
	};
	static_assert(offsetof(ModCallbackEvent, eventName) == 0x0);
	static_assert(offsetof(ModCallbackEvent, stringArgument) == 0x8);
	static_assert(offsetof(ModCallbackEvent, numericalArgument) == 0x10);
	static_assert(offsetof(ModCallbackEvent, sender) == 0x18);
	static_assert(sizeof(ModCallbackEvent) == 0x20);
}
