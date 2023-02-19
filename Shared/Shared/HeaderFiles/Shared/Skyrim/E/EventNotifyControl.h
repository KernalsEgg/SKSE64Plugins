#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class EventNotifyControl : std::uint32_t
	{
		kContinue = 0,
		kStop     = 1
	};
	static_assert(sizeof(EventNotifyControl) == 0x4);
}
