#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"



namespace Skyrim
{
	class hkpShape;

	class hkpCdBody
	{
	public:
		// Member variables
		const hkpShape*  shape;    // 0
		hkpShapeKey      shapeKey; // 8
		std::uint32_t    paddingC; // C
		const void*      motion;   // 10
		const hkpCdBody* parent;   // 18
	};
	static_assert(offsetof(hkpCdBody, shape) == 0x0);
	static_assert(offsetof(hkpCdBody, shapeKey) == 0x8);
	static_assert(offsetof(hkpCdBody, motion) == 0x10);
	static_assert(offsetof(hkpCdBody, parent) == 0x18);
	static_assert(sizeof(hkpCdBody) == 0x20);
}
