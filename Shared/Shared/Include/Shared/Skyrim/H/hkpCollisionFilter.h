#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkEnumeration.h"
#include "Shared/Skyrim/H/hkpCollidableCollidableFilter.h"
#include "Shared/Skyrim/H/hkpRayCollidableFilter.h"
#include "Shared/Skyrim/H/hkpRayShapeCollectionFilter.h"
#include "Shared/Skyrim/H/hkpShapeCollectionFilter.h"
#include "Shared/Skyrim/H/hkReferencedObject.h"



namespace Skyrim
{
	class hkpWorld;

	class hkpCollisionFilter :
		public hkReferencedObject,            // 0
		public hkpCollidableCollidableFilter, // 10
		public hkpShapeCollectionFilter,      // 18
		public hkpRayShapeCollectionFilter,   // 20
		public hkpRayCollidableFilter         // 28
	{
	public:
		enum class hkpFilterType
		{
			kUnknown    = 0,
			kNull       = 1,
			kGroup      = 2,
			kList       = 3,
			kCustom     = 4,
			kPair       = 5,
			kConstraint = 6
		};

		// Override
		virtual ~hkpCollisionFilter() override; // 0

		// Override (hkpShapeCollectionFilter)
		virtual std::int32_t NumberShapeKeyHitsLimitBreached(const hkpCollisionInput& input, const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpBvTreeShape* bvTreeShapeB, hkAabb& aabb, hkpShapeKey* shapeKeysInOut, std::int32_t shapeKeysCapacity) const override; // 2

		// Add
		virtual void Initialize(hkpWorld* world); // 3

		// Member variables
		std::uint64_t                               padding30; // 30
		hkEnumeration<hkpFilterType, std::uint32_t> type;      // 38
		std::uint32_t                               padding3C; // 3C
		std::uint64_t                               padding40; // 40
	};
	static_assert(offsetof(hkpCollisionFilter, type) == 0x38);
	static_assert(sizeof(hkpCollisionFilter) == 0x48);
}
