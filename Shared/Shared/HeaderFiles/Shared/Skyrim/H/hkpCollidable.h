#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"
#include "Shared/Skyrim/H/hkpCdBody.h"
#include "Shared/Skyrim/H/hkpTypedBroadPhaseHandle.h"



namespace Skyrim
{
	struct hkAabbUint32;

	class NiAVObject;

	class hkpCollidable :
		public hkpCdBody // 0
	{
	public:
		enum class ForceCollideOntoPPUReasons
		{
			kUserRequest     = 1 << 0,
			kShapeRequest    = 1 << 1,
			kModifierRequest = 1 << 2,
			kShapeUnchecked  = 1U << 3
		};

		struct BoundingVolumeData
		{
		public:
			// Member variables
			std::uint32_t minimum[3];              // 0
			std::uint8_t  expansionMinimum[3];     // C
			std::uint8_t  expansionShift;          // F
			std::uint32_t maximum[3];              // 10
			std::uint8_t  expansionMaximum[3];     // 1C
			std::uint8_t  padding1F;               // 1F
			std::uint16_t numberChildShapeAabbs;   // 20
			std::uint16_t capacityChildShapeAabbs; // 22
			std::uint32_t padding24;               // 24
			hkAabbUint32* childShapeAabbs;         // 28
			hkpShapeKey*  childShapeKeys;          // 30
		};
		static_assert(offsetof(BoundingVolumeData, minimum) == 0x0);
		static_assert(offsetof(BoundingVolumeData, expansionMinimum) == 0xC);
		static_assert(offsetof(BoundingVolumeData, expansionShift) == 0xF);
		static_assert(offsetof(BoundingVolumeData, maximum) == 0x10);
		static_assert(offsetof(BoundingVolumeData, expansionMaximum) == 0x1C);
		static_assert(offsetof(BoundingVolumeData, numberChildShapeAabbs) == 0x20);
		static_assert(offsetof(BoundingVolumeData, capacityChildShapeAabbs) == 0x22);
		static_assert(offsetof(BoundingVolumeData, childShapeAabbs) == 0x28);
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
		hkpTypedBroadPhaseHandle broadPhaseHandle;        // 24
		BoundingVolumeData       boundingVolumeData;      // 30
		float                    allowedPenetrationDepth; // 68
		std::uint32_t            padding6C;               // 6C
	};
	static_assert(offsetof(hkpCollidable, ownerOffset) == 0x20);
	static_assert(offsetof(hkpCollidable, forceCollideOntoPPU) == 0x21);
	static_assert(offsetof(hkpCollidable, shapeSizeOnSPU) == 0x22);
	static_assert(offsetof(hkpCollidable, broadPhaseHandle) == 0x24);
	static_assert(offsetof(hkpCollidable, boundingVolumeData) == 0x30);
	static_assert(offsetof(hkpCollidable, allowedPenetrationDepth) == 0x68);
	static_assert(sizeof(hkpCollidable) == 0x70);
}
