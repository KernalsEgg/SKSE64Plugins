#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpRayHitCollector.h"
#include "Shared/Skyrim/H/hkpWorldRayCastOutput.h"



namespace Skyrim
{
	class hkpClosestRayHitCollector :
		public hkpRayHitCollector // 0
	{
	public:
		// Override
		virtual ~hkpClosestRayHitCollector() override = default; // 1

		// Override (hkpRayHitCollector)
		virtual void AddRayHit(const hkpCdBody& cdBody, const hkpShapeRayCastCollectorOutput& hitInformation) override; // 0

		// Member functions
		constexpr bool HasHit() noexcept
		{
			return this->rayHit.HasHit();
		}

		constexpr void Reset() noexcept
		{
			this->hkpRayHitCollector::Reset();
			this->rayHit.Reset();
		}

		// Member variables
		hkpWorldRayCastOutput rayHit; // 10
	};
	static_assert(offsetof(hkpClosestRayHitCollector, rayHit) == 0x10);
	static_assert(sizeof(hkpClosestRayHitCollector) == 0x70);
}
