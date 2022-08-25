#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	struct TESLoadGameEvent
	{
	};
	static_assert(std::is_empty_v<TESLoadGameEvent>);
}
