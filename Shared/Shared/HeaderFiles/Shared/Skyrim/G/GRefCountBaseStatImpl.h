#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GMemory.h"



namespace Skyrim
{
#define GFC_REFERENCECOUNTALLOCATION_CHECK_DELETE(className, pointer)

	template <class Base, std::uint32_t StatisticType>
	class GRefCountBaseStatImpl :
		public Base // 0
	{
		GFC_MEMORY_REDEFINE_NEW_IMPLEMENTATION(Base, GFC_REFERENCECOUNTALLOCATION_CHECK_DELETE, StatisticType)
	};
}
