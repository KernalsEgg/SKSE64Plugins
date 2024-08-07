#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"
#include "Shared/Skyrim/H/hkpCdBody.h"
#include "Shared/Skyrim/H/hkpTypedBroadPhaseHandle.h"



namespace Skyrim
{
	struct hkAabbUInt32;

	class NiAVObject;

	class hkpCollidable :
		public hkpCdBody // 0
	{
	public:
		enum class ForceCollideOntoPPUReasons
		{
			kUserRequest     = 1U << 0,
			kShapeRequest    = 1U << 1,
			kModifierRequest = 1U << 2,
			kShapeUnchecked  = 1U << 3
		};

		struct BoundingVolumeData
		{
		public:
			// Member variables
			std::uint32_t minimum[3];                               // 0
			std::uint8_t  expansionMinimum[3];                      // C
			std::uint8_t  expansionShift;                           // F
			std::uint32_t maximum[3];                               // 10
			std::uint8_t  expansionMaximum[3];                      // 1C
			std::uint8_t  padding1F;                                // 1F
			std::uint16_t childShapeAxisAlignedBoundingBoxCount;    // 20
			std::uint16_t childShapeAxisAlignedBoundingBoxCapacity; // 22
			std::uint32_t padding24;                                // 24
			hkAabbUInt32* childShapeAxisAlignedBoundingBoxes;       // 28
			hkpShapeKey*  childShapeKeys;                           // 30
		};
		static_assert(offsetof(BoundingVolumeData, minimum) == 0x0);
		static_assert(offsetof(BoundingVolumeData, expansionMinimum) == 0xC);
		static_assert(offsetof(BoundingVolumeData, expansionShift) == 0xF);
		static_assert(offsetof(BoundingVolumeData, maximum) == 0x10);
		static_assert(offsetof(BoundingVolumeData, expansionMaximum) == 0x1C);
		static_assert(offsetof(BoundingVolumeData, childShapeAxisAlignedBoundingBoxCount) == 0x20);
		static_assert(offsetof(BoundingVolumeData, childShapeAxisAlignedBoundingBoxCapacity) == 0x22);
		static_assert(offsetof(BoundingVolumeData, childShapeAxisAlignedBoundingBoxes) == 0x28);
		static_assert(offsetof(BoundingVolumeData, childShapeKeys) == 0x30);
		static_assert(sizeof(BoundingVolumeData) == 0x38);

		// Member functions
		NiAVObject* Get3D() const;
		void*       GetOwner() const;

		template <class T>
		T* GetOwner() const
		{
			return static_cast<T*>(this->GetOwner());
		}

		// Member variables
		std::int8_t              ownerOffset;             // 20
		std::uint8_t             forceCollideOntoPPU;     // 21
		std::uint16_t            shapeSizeOnSPU;          // 22
		hkpTypedBroadPhaseHandle typedBroadPhaseHandle;   // 24
		BoundingVolumeData       boundingVolumeData;      // 30
		float                    allowedPenetrationDepth; // 68
		std::uint32_t            padding6C;               // 6C
	};
	static_assert(offsetof(hkpCollidable, ownerOffset) == 0x20);
	static_assert(offsetof(hkpCollidable, forceCollideOntoPPU) == 0x21);
	static_assert(offsetof(hkpCollidable, shapeSizeOnSPU) == 0x22);
	static_assert(offsetof(hkpCollidable, typedBroadPhaseHandle) == 0x24);
	static_assert(offsetof(hkpCollidable, boundingVolumeData) == 0x30);
	static_assert(offsetof(hkpCollidable, allowedPenetrationDepth) == 0x68);
	static_assert(sizeof(hkpCollidable) == 0x70);
}
