#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"



namespace Skyrim
{
	struct hkpCollisionInput;

	class hkAabb;
	class hkpBvTreeShape;
	class hkpCdBody;
	class hkpShapeContainer;

	class hkpShapeCollectionFilter
	{
	public:
		// Add
		virtual bool         IsCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& bodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeB, hkpShapeKey keyB) const                                                                       = 0; // 0
		virtual bool         IsCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& collectionBodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA, const hkpShapeContainer& containerShapeB, hkpShapeKey keyA, hkpShapeKey keyB) const = 0; // 1
		virtual std::int32_t NumberShapeKeyHitsLimitBreached(const hkpCollisionInput& input, const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpBvTreeShape* bvTreeShapeB, hkAabb& aabb, hkpShapeKey* shapeKeysInOut, std::int32_t shapeKeysCapacity) const                 = 0; // 2
		virtual ~hkpShapeCollectionFilter();                                                                                                                                                                                                                                           // 3
	};
	static_assert(sizeof(hkpShapeCollectionFilter) == 0x8);
}
