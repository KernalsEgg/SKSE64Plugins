#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"



namespace Skyrim
{
	struct hkpShapeRayCastCollectorOutput;

	class hkpCdBody;

	class hkpRayHitCollector
	{
	public:
		// Add
		virtual void AddRayHit(const hkpCdBody& cdBody, const hkpShapeRayCastCollectorOutput& hitInformation) = 0;       // 0
		virtual ~hkpRayHitCollector()                                                                         = default; // 1

		// Member functions
		constexpr void Reset() noexcept
		{
			this->earlyOutHitFraction = 1.0F;
		}

		static std::int32_t ShapeKeysFromCdBody(hkpShapeKey* buffer, std::int32_t maximumKeys, const hkpCdBody& cdBody);

		// Member variables
		float         earlyOutHitFraction{ 1.0F }; // 8
		std::uint32_t paddingC;                    // C
	};
	static_assert(offsetof(hkpRayHitCollector, earlyOutHitFraction) == 0x8);
	static_assert(sizeof(hkpRayHitCollector) == 0x10);
}
