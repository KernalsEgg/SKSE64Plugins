#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkVector4.h"



namespace Skyrim
{
	struct hkpWorldRayCastInput
	{
	public:
		// Member variables
		hkVector4     from;                                 // 0
		hkVector4     to;                                   // 10
		bool          enableShapeCollectionFilter{ false }; // 20
		std::uint8_t  padding21;                            // 21
		std::uint16_t padding22;                            // 22
		std::uint32_t filterInformation{ 0 };               // 24
		std::uint64_t padding28;                            // 28
	};
	static_assert(offsetof(hkpWorldRayCastInput, from) == 0x0);
	static_assert(offsetof(hkpWorldRayCastInput, to) == 0x10);
	static_assert(offsetof(hkpWorldRayCastInput, enableShapeCollectionFilter) == 0x20);
	static_assert(offsetof(hkpWorldRayCastInput, filterInformation) == 0x24);
	static_assert(sizeof(hkpWorldRayCastInput) == 0x30);
}
