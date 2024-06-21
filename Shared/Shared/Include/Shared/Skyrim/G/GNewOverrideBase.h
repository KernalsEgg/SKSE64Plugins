#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GMemory.h"



namespace Skyrim
{
	template <std::uint32_t STATISTIC_TYPE>
	class GNewOverrideBase
	{
	public:
		enum
		{
			kStatisticType = STATISTIC_TYPE
		};

		GFC_MEMORY_REDEFINE_NEW(GNewOverrideBase, STATISTIC_TYPE)
	};
}
