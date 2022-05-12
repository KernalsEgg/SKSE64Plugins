#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class hkpCollidable;

	class hkpCollidableCollidableFilter
	{
	public:
		// Add
		virtual ~hkpCollidableCollidableFilter();                                                                      // 0
		virtual bool IsCollisionEnabled(const hkpCollidable& collidableA, const hkpCollidable& collidableB) const = 0; // 1
	};
	static_assert(sizeof(hkpCollidableCollidableFilter) == 0x8);
}
