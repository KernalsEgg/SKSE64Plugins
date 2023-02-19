#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GImageBase.h"
#include "Shared/Skyrim/G/GRefCountBaseNTS.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	class GImage :
		public GRefCountBaseNTS<GImage, Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticImageMemory)>, // 0
		public GImageBase                                                                                            // 10
	{
	public:
		// Override
		virtual ~GImage() override; // 0
	};
	static_assert(sizeof(GImage) == 0x48);
}
