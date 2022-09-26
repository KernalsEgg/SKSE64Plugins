#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpBroadPhaseHandle.h"



namespace Skyrim
{
	class hkpTypedBroadPhaseHandle :
		public hkpBroadPhaseHandle // 0
	{
	public:
		enum
		{
			kInvalidOffset = 127
		};

		// Member variables
		std::int8_t   type;                       // 4
		std::int8_t   ownerOffset;                // 5
		std::int8_t   objectQualityType;          // 6
		std::uint8_t  padding7;                   // 7
		std::uint32_t collisionFilterInformation; // 8
	};
	static_assert(offsetof(hkpTypedBroadPhaseHandle, type) == 0x4);
	static_assert(offsetof(hkpTypedBroadPhaseHandle, ownerOffset) == 0x5);
	static_assert(offsetof(hkpTypedBroadPhaseHandle, objectQualityType) == 0x6);
	static_assert(offsetof(hkpTypedBroadPhaseHandle, collisionFilterInformation) == 0x8);
	static_assert(sizeof(hkpTypedBroadPhaseHandle) == 0xC);
}
