#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkVector4.h"
#include "Shared/Skyrim/H/hkpCollisionFilter.h"



namespace Skyrim
{
	class hkpGroupFilter :
		public hkpCollisionFilter // 0
	{
	public:
		enum
		{
			kUseCollidableFilterInformation = 0xFFFFFFFF
		};

		enum SystemGroup : std::uint16_t
		{
			kTerrain = 1
		};
		static_assert(sizeof(SystemGroup) == 0x2);

		// Override
		virtual ~hkpGroupFilter() override; // 0

		// Override (hkpCollidableCollidableFilter)
		virtual bool IsCollisionEnabled(const hkpCollidable& collidableA, const hkpCollidable& collidableB) const override; // 1

		// Override (hkpShapeCollectionFilter)
		virtual bool IsCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& bodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeB, hkpShapeKey keyB) const override;                                                                       // 0
		virtual bool IsCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& collectionBodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA, const hkpShapeContainer& containerShapeB, hkpShapeKey keyA, hkpShapeKey keyB) const override; // 1

		// Override (hkpRayShapeCollectionFilter)
		virtual bool IsCollisionEnabled(const hkpShapeRayCastInput& inputA, const hkpShapeContainer& containerB, hkpShapeKey keyB) const override; // 0

		// Override (hkpRayCollidableFilter)
		virtual bool IsCollisionEnabled(const hkpWorldRayCastInput& inputA, const hkpCollidable& collidableB) const override; // 1

		// Add
		virtual std::int32_t DummyUnused(); // 4

		// Non-member variables
		static std::int32_t GetLayerFromFilterInformation(std::uint32_t filterInformation);
		static std::int32_t GetSubSystemDontCollideWithFromFilterInformation(std::uint32_t filterInformation);
		static std::int32_t GetSubSystemIDFromFilterInformation(std::uint32_t filterInformation);
		static std::int32_t GetSystemGroupFromFilterInformation(std::uint32_t filterInformation);

		// Member variables
		std::int32_t  nextFreeSystemGroup;      // 48
		std::uint32_t collisionLookupTable[32]; // 4C
		std::uint32_t paddingCC;                // CC
		hkVector4     paddingD0[4];             // D0
	};
	static_assert(offsetof(hkpGroupFilter, nextFreeSystemGroup) == 0x48);
	static_assert(offsetof(hkpGroupFilter, collisionLookupTable) == 0x4C);
	static_assert(sizeof(hkpGroupFilter) == 0x110);
}
