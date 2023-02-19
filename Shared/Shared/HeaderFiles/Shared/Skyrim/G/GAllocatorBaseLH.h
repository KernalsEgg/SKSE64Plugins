#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GMemory.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	// Local Allocator
	template <std::uint32_t STATISTIC_ID = Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	class GAllocatorBaseLH
	{
	public:
		enum
		{
			kStatisticID = STATISTIC_ID
		};

		static void* Allocate(const void* heapAddress, UPInt size)
		{
			return GMemory::AllocateAutomaticHeap(heapAddress, size);
		}

		static void Free(void* pointer)
		{
			GMemory::Free(pointer);
		}

		static void* Reallocate(void* pointer, UPInt newSize)
		{
			return GMemory::Reallocate(pointer, newSize);
		}
	};
	static_assert(std::is_empty_v<GAllocatorBaseLH<>>);
}
