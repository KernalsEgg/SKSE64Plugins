#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	struct TESLoadGameEvent
	{
	public:
	};
	static_assert(std::is_empty_v<TESLoadGameEvent>);
}
