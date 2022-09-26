#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"
#include "Shared/Skyrim/H/hkpShapeRayCastCollectorOutput.h"



namespace Skyrim
{
	struct hkpShapeRayCastOutput :
		public hkpShapeRayCastCollectorOutput // 0
	{
	public:
		enum
		{
			kMaximumHierarchyDepth = 8
		};

		// Member functions
		constexpr void Reset() noexcept
		{
			this->hkpShapeRayCastCollectorOutput::Reset();

			this->shapeKeys[0]  = HK_INVALID_SHAPE_KEY;
			this->shapeKeyIndex = 0;
		}

		// Member variables
		hkpShapeKey   shapeKeys[kMaximumHierarchyDepth]{ HK_INVALID_SHAPE_KEY }; // 20
		std::int32_t  shapeKeyIndex{ 0 };                                        // 40
		std::uint32_t padding44;                                                 // 44
		std::uint64_t padding48;                                                 // 48
	};
	static_assert(offsetof(hkpShapeRayCastOutput, shapeKeys) == 0x20);
	static_assert(offsetof(hkpShapeRayCastOutput, shapeKeyIndex) == 0x40);
	static_assert(sizeof(hkpShapeRayCastOutput) == 0x50);
}
