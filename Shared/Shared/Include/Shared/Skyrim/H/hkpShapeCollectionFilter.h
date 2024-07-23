#pragma once

#include "Shared/PrecompiledHeader.h"

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
		virtual bool         IsCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& collisionDetectionBodyA, const hkpCdBody& collectionCollisionDetectionBodyB, const hkpShapeContainer& shapeContainerB, hkpShapeKey shapeKeyB) const                                                                                      = 0; // 0
		virtual bool         IsCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& collectionCollisionDetectionBodyA, const hkpCdBody& collectionCollisionDetectionBodyB, const hkpShapeContainer& shapeContainerA, const hkpShapeContainer& shapeContainerB, hkpShapeKey shapeKeyA, hkpShapeKey shapeKeyB) const           = 0; // 1
		virtual std::int32_t NumberShapeKeyHitsLimitBreached(const hkpCollisionInput& input, const hkpCdBody& collisionDetectionBodyA, const hkpCdBody& collisionDetectionBodyB, const hkpBvTreeShape* boundingVolumeTreeShapeB, hkAabb& axisAlignedBoundingBox, hkpShapeKey* shapeKeysInputOutput, std::int32_t shapeKeysCapacity) const = 0; // 2
		virtual ~hkpShapeCollectionFilter();                                                                                                                                                                                                                                                                                                   // 3
	};
	static_assert(sizeof(hkpShapeCollectionFilter) == 0x8);
}
