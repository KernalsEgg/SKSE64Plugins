#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRefCountBase.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class GFxResource;

	class GFxResourceLibBase :
		public GRefCountBase<GFxResourceLibBase, Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)> // 0
	{
	public:
		// Add
		virtual void RemoveResourceOnRelease(GFxResource* resource) = 0; // 1
		virtual void PinResource(GFxResource* resource)             = 0; // 2
		virtual void UnpinResource(GFxResource* resource)           = 0; // 3
	};
	static_assert(sizeof(GFxResourceLibBase) == 0x10);
}
