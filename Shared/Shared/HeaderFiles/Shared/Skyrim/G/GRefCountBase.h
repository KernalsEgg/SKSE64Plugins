#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GRefCountBaseStatImpl.h"
#include "Shared/Skyrim/G/GRefCountImpl.h"



namespace Skyrim
{
	template <class T, std::uint32_t StatType>
	class GRefCountBase :
		public GRefCountBaseStatImpl<GRefCountImpl, StatType> // 0
	{
	public:
		enum
		{
			kStatType = StatType
		};
	};
}
