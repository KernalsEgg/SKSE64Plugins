#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	using hkpShapeKey = std::uint32_t;
	using hkQuadReal  = ::__m128;
	using hkTime      = float;

	constexpr hkpShapeKey HK_INVALID_SHAPE_KEY = static_cast<hkpShapeKey>(-1);

	class hkFinishLoadedObjectFlag
	{
	public:
		// Member variables
		std::int32_t finishing{ 0 }; // 0
	};
	static_assert(offsetof(hkFinishLoadedObjectFlag, finishing) == 0x0);
	static_assert(sizeof(hkFinishLoadedObjectFlag) == 0x4);
}
