#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"
#include "Shared/Skyrim/H/hkVector4.h"



namespace Skyrim
{
	struct hkpShapeRayCastCollectorOutput
	{
	public:
		// Member functions
		constexpr bool HasHit() const noexcept
		{
			return this->hitFraction < 1.0F;
		}

		constexpr void Reset() noexcept
		{
			this->hitFraction      = 1.0F;
			this->extraInformation = -1;
			this->shapeKey         = HK_INVALID_SHAPE_KEY;
		}

		// Member variables
		hkVector4     normal;                           // 0
		float         hitFraction{ 1.0F };              // 10
		std::int32_t  extraInformation{ -1 };           // 14
		hkpShapeKey   shapeKey{ HK_INVALID_SHAPE_KEY }; // 18
		std::uint32_t padding1C;                        // 1C
	};
	static_assert(offsetof(hkpShapeRayCastCollectorOutput, normal) == 0x0);
	static_assert(offsetof(hkpShapeRayCastCollectorOutput, hitFraction) == 0x10);
	static_assert(offsetof(hkpShapeRayCastCollectorOutput, extraInformation) == 0x14);
	static_assert(offsetof(hkpShapeRayCastCollectorOutput, shapeKey) == 0x18);
	static_assert(sizeof(hkpShapeRayCastCollectorOutput) == 0x20);
}
