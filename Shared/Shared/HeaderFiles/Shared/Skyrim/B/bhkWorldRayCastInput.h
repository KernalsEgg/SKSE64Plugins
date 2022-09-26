#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkVector4.h"
#include "Shared/Skyrim/H/hkpWorldRayCastInput.h"
#include "Shared/Skyrim/H/hkpWorldRayCastOutput.h"



namespace Skyrim
{
	class hkpRayHitCollector;

	struct bhkWorldRayCastInput :
		public hkpWorldRayCastInput // 0
	{
	public:
		// Member variables
		hkpWorldRayCastOutput rayHit;                       // 30
		hkVector4             ray;                          // 90
		hkpRayHitCollector*   rayHitCollectorA0{ nullptr }; // A0
		hkpRayHitCollector*   rayHitCollectorA8{ nullptr }; // A8
		hkpRayHitCollector*   rayHitCollectorB0{ nullptr }; // B0
		hkpRayHitCollector*   rayHitCollectorB8{ nullptr }; // B8
		bool                  unknownC0{ false };           // C0
		std::uint8_t          paddingC1;                    // C1
		std::uint16_t         paddingC2;                    // C2
		std::uint32_t         paddingC4;                    // C4
		std::uint64_t         paddingC8;                    // C8
	};
	static_assert(offsetof(bhkWorldRayCastInput, rayHit) == 0x30);
	static_assert(offsetof(bhkWorldRayCastInput, ray) == 0x90);
	static_assert(offsetof(bhkWorldRayCastInput, rayHitCollectorA0) == 0xA0);
	static_assert(offsetof(bhkWorldRayCastInput, rayHitCollectorA8) == 0xA8);
	static_assert(offsetof(bhkWorldRayCastInput, rayHitCollectorB0) == 0xB0);
	static_assert(offsetof(bhkWorldRayCastInput, rayHitCollectorB8) == 0xB8);
	static_assert(sizeof(bhkWorldRayCastInput) == 0xD0);
}
