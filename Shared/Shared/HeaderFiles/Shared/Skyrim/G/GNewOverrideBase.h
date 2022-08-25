#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GMemory.h"



namespace Skyrim
{
	template <std::uint32_t StatisticType>
	class GNewOverrideBase
	{
	public:
		enum
		{
			kStatisticType = StatisticType
		};

		GFC_MEMORY_REDEFINE_NEW(GNewOverrideBase, StatisticType)
	};
}
