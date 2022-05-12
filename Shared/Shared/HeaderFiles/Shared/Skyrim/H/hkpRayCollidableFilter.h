#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	struct hkpWorldRayCastInput;

	class hkpCollidable;

	class hkpRayCollidableFilter
	{
	public:
		// Add
		virtual ~hkpRayCollidableFilter();                                                                               // 0
		virtual bool IsCollisionEnabled(const hkpWorldRayCastInput& inputA, const hkpCollidable& collidableB) const = 0; // 1
	};
	static_assert(sizeof(hkpRayCollidableFilter) == 0x8);
}
