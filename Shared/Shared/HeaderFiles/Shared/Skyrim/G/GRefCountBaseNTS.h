#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRefCountBaseStatImpl.h"
#include "Shared/Skyrim/G/GRefCountNTSImpl.h"



namespace Skyrim
{
	template <class T, std::uint32_t STATISTIC_TYPE>
	class GRefCountBaseNTS :
		public GRefCountBaseStatImpl<GRefCountNTSImpl, STATISTIC_TYPE> // 0
	{
	public:
		enum
		{
			kStatisticType = STATISTIC_TYPE
		};
	};
}
