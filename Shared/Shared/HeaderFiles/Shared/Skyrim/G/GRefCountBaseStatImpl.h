#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class Base, std::uint32_t StatType>
	class GRefCountBaseStatImpl :
		public Base // 0
	{
	};
}
