#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class hkVector4Comparison
	{
	public:
		enum class Mask : std::uint32_t
		{
			kNone = 0,

			kX  = 1,
			kY  = 2,
			kXY = 3,

			kZ   = 4,
			kXZ  = 5,
			kYZ  = 6,
			kXYZ = 7,

			kW   = 8,
			kXW  = 9,
			kYW  = 10,
			kXYW = 11,

			kZW   = 12,
			kXZW  = 13,
			kYZW  = 14,
			kXYZW = 15
		};
		static_assert(sizeof(Mask) == 0x4);
	};
	static_assert(std::is_empty_v<hkVector4Comparison>);
}
