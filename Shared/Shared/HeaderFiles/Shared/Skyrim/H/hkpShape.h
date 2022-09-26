#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkReferencedObject.h"
#include "Shared/Skyrim/H/hkVector4.h"
#include "Shared/Skyrim/H/hkVector4Comparison.h"
#include "Shared/Skyrim/H/hkpShapeType.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct hkpShapeRayBundleCastInput;
	struct hkpShapeRayBundleCastOutput;
	struct hkpShapeRayCastInput;
	struct hkpShapeRayCastOutput;

	class hkAabb;
	class hkpCdBody;
	class hkpRayHitCollector;
	class hkpShapeContainer;
	class hkTransform;

	class hkpShape :
		public hkReferencedObject // 0
	{
	public:
		struct CalculateSizeForSPUInput
		{
			bool midPhaseAgent3Registered; // 0
			bool isFixedOrKeyframed;       // 1
			bool hasDynamicMotionSaved;    // 2
		};
		static_assert(offsetof(CalculateSizeForSPUInput, midPhaseAgent3Registered) == 0x0);
		static_assert(offsetof(CalculateSizeForSPUInput, isFixedOrKeyframed) == 0x1);
		static_assert(offsetof(CalculateSizeForSPUInput, hasDynamicMotionSaved) == 0x2);
		static_assert(sizeof(CalculateSizeForSPUInput) == 0x3);

		// Override
		virtual ~hkpShape() override; // 0

		// Add
		virtual float                    GetMaximumProjection(const hkVector4& direction) const;                                                                                           // 3
		virtual const hkpShapeContainer* GetContainer() const;                                                                                                                             // 4
		virtual bool                     IsConvex() const;                                                                                                                                 // 5
		virtual std::int32_t             CalculateSizeForSpu(const CalculateSizeForSPUInput& input, std::int32_t spuBufferSizeLeft) const;                                                 // 6
		virtual void                     GetAabbImplementation(const hkTransform& localToWorld, float tolerance, hkAabb& out) const                                          = 0;          // 7
		virtual bool                     CastRayImplementation(const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output) const                                       = 0;          // 8
		virtual void                     CastRayWithCollectorImplementation(const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector) const = 0;          // 9
		virtual hkVector4Comparison      CastRayBundleImplementation(const hkpShapeRayBundleCastInput& input, hkpShapeRayBundleCastOutput& output, const hkVector4Comparison& mask) const; // A

		// Member variables
		std::uint64_t                                     userData;  // 10
		Utility::Enumeration<hkpShapeType, std::uint32_t> shapeType; // 18
		std::uint32_t                                     padding1C; // 1C
	};
	static_assert(offsetof(hkpShape, userData) == 0x10);
	static_assert(offsetof(hkpShape, shapeType) == 0x18);
	static_assert(sizeof(hkpShape) == 0x20);
}
