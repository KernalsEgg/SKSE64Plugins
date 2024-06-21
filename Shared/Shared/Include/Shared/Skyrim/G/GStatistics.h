#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	enum class GStatisticGroup : std::uint32_t
	{
		kGStatisticGroupDefault = 0,

		kGStatisticGroupCore            = 16,
		kGStatisticGroupRenderer        = 1U << 6,
		kGStatisticGroupRenderGenerator = 2U << 6,

		kGStatisticGroupGFxFontCache   = 3U << 6,
		kGStatisticGroupGFxMovieData   = 4U << 6,
		kGStatisticGroupGFxMovieView   = 5U << 6,
		kGStatisticGroupGFxRenderCache = 6U << 6,
		kGStatisticGroupGFxPlayer      = 7U << 6,
		kGStatisticGroupGFxIME         = 8U << 6,

		// General memory
		kGStatisticMemory = kGStatisticGroupDefault + 1,
		kGStatisticDefaultMemory,
		kGStatisticImageMemory,
		kGStatisticSoundMemory,
		kGStatisticStringMemory,
		kGStatisticVideoMemory,

		// Debug memory
		kGStatisticDebugMemory,
		kGStatisticDebugHUDMemory,
		kGStatisticDebugTrackerMemory,
		kGStatisticStatisticBagMemory,

		kGStatisticHeapStart = kGStatisticGroupCore,

		kGStatisticMaximumID  = 64U << 6,
		kGStatisticEntryCount = 512
	};
	static_assert(sizeof(GStatisticGroup) == 0x4);

	enum class GStatisticRenderers : std::uint32_t
	{
		kDefault = Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticGroupDefault),

		kMemory,

		// Video memory
		kVideoMemory,
		kTextureVideoMemory,
		kBufferVideoMemory,

		// Counters
		kCounters,
		kTextureUploadCounter,
		kTextureUpdateCounter,
		kDPCounter,
		kDPLineCounter,
		kDPTriangleCounter,
		kTriangleCounter,
		kLineCounter,
		kMaskCounter,
		kFilterCounter
	};
	static_assert(sizeof(GStatisticRenderers) == 0x4);

	enum class GHeapID : UPInt
	{
		kReserved        = 0,
		kGlobal          = 1,
		kMovieDefinition = 2,
		kMovieView       = 3,
		kMovieData       = 4,
		kMeshCache       = 5,
		kFontCache       = 6,
		kImages          = 7,
		kOtherHeaps      = 8,
		kHUDHeaps        = 9
	};
	static_assert(sizeof(GHeapID) == 0x8);
}
