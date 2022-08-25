#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GRefCountBaseStatImpl.h"
#include "Shared/Skyrim/G/GRefCountNTSImpl.h"



namespace Skyrim
{
	template <class T, std::uint32_t StatisticType>
	class GRefCountBaseNTS :
		public GRefCountBaseStatImpl<GRefCountNTSImpl, StatisticType> // 0
	{
	public:
		enum
		{
			kStatisticType = StatisticType
		};
	};
}
