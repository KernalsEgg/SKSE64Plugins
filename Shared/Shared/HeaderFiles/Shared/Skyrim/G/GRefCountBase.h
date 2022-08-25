#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GRefCountBaseStatImpl.h"
#include "Shared/Skyrim/G/GRefCountImpl.h"



namespace Skyrim
{
	template <class T, std::uint32_t StatisticType>
	class GRefCountBase :
		public GRefCountBaseStatImpl<GRefCountImpl, StatisticType> // 0
	{
	public:
		enum
		{
			kStatisticType = StatisticType
		};
	};
}
