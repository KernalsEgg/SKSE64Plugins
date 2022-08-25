#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	enum class GFxStatisticMovieData : std::uint32_t
	{
		kDefault = Utility::ToUnderlying(GStatisticGroup::kGStatisticGroupGFxMovieData),

		// Movie memory
		kMemory,
		kCharacterDefinitionsMemory,
		kShapeDataMemory,
		kTagsMemory,
		kFontsMemory,
		kImagesMemory,
		kSoundsMemory,
		kActionOperationsMemory,
		kOtherMemory,

		// Different
		kTime,
		kLoadTimer,
		kBindTimer
	};
	static_assert(sizeof(GFxStatisticMovieData) == 0x4);

	enum class GFxStatisticMovieView : std::uint32_t
	{
		kDefault = Utility::ToUnderlying(GStatisticGroup::kGStatisticGroupGFxMovieView),

		// MovieView memory
		kMemory,
		kMovieClipMemory,
		kActionScriptMemory,
		kTextMemory,
		kXMLMemory,
		kOtherMemory,

		// MovieView timings
		kTimer,
		kAdvanceTimer,
		kActionTimer,
		kTimelineTimer,
		kInputTimer,
		kMouseTimer,
		kScriptCommunicationTimer,
		kGetVariableTimer,
		kSetVariableTimer,
		kInvokeTimer,
		kDisplayTimer,
		kTessellateTimer,
		kGradientGeneratorTimer
	};
	static_assert(sizeof(GFxStatisticMovieView) == 0x4);

	enum class GFxStatisticIME : std::uint32_t
	{
		kDefault = Utility::ToUnderlying(GStatisticGroup::kGStatisticGroupGFxIME),

		kMemory
	};
	static_assert(sizeof(GFxStatisticIME) == 0x4);

	enum class GFxStatisticFontCache
	{
		kDefault = Utility::ToUnderlying(GStatisticGroup::kGStatisticGroupGFxFontCache),

		kMemory,
		kBatchMemory,
		kGlyphCacheMemory,
		kOtherMemory
	};
	static_assert(sizeof(GFxStatisticFontCache) == 0x4);
}
