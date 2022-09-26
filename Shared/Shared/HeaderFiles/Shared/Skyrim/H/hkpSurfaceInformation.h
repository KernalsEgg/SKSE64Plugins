#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkVector4.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct hkpSurfaceInformation
	{
	public:
		enum class SupportedState : std::uint32_t
		{
			kUnsupported = 0,
			kSliding     = 1,
			kSupported   = 2
		};
		static_assert(sizeof(SupportedState) == 0x4);

		// Member variables
		Utility::Enumeration<SupportedState, std::uint32_t> supportedState;        // 0
		std::uint32_t                                       padding4;              // 4
		std::uint64_t                                       padding8;              // 8
		hkVector4                                           surfaceNormal;         // 10
		hkVector4                                           surfaceVelocity;       // 20
		float                                               surfaceDistanceExcess; // 30
		bool                                                surfaceIsDynamic;      // 34
		std::uint8_t                                        padding35;             // 35
		std::uint16_t                                       padding36;             // 36
		std::uint64_t                                       padding38;             // 38
	};
	static_assert(offsetof(hkpSurfaceInformation, supportedState) == 0x0);
	static_assert(offsetof(hkpSurfaceInformation, surfaceNormal) == 0x10);
	static_assert(offsetof(hkpSurfaceInformation, surfaceVelocity) == 0x20);
	static_assert(offsetof(hkpSurfaceInformation, surfaceDistanceExcess) == 0x30);
	static_assert(offsetof(hkpSurfaceInformation, surfaceIsDynamic) == 0x34);
	static_assert(sizeof(hkpSurfaceInformation) == 0x40);
}
