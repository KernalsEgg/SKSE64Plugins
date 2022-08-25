#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GArrayBase.h"
#include "Shared/Skyrim/G/GArrayDataDH.h"
#include "Shared/Skyrim/G/GArrayDefaultPolicy.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class GMemoryHeap;

	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory), class SizePolicy = GArrayDefaultPolicy>
	class GArrayDH :
		public GArrayBase<GArrayDataDH<T, GAllocatorDH<T, StatisticID>, SizePolicy>> // 0
	{
	public:
		using value_type       = T;
		using allocator_type   = GAllocatorDH<T, StatisticID>;
		using size_policy_type = SizePolicy;
		using self_type        = GArrayDH<T, StatisticID, SizePolicy>;
		using base_type        = GArrayBase<GArrayDataDH<T, GAllocatorDH<T, StatisticID>, SizePolicy>>;

		GArrayDH(GMemoryHeap* heap) :
			base_type(heap)
		{
		}

		GArrayDH(GMemoryHeap* heap, std::uint32_t size) :
			base_type(heap, size)
		{
		}

		GArrayDH(GMemoryHeap* heap, const size_policy_type& policy) :
			base_type(heap)
		{
			this->SetSizePolicy(policy);
		}

		GArrayDH(const self_type& array) :
			base_type(array)
		{
		}

		// Member functions
		const self_type& operator=(const self_type& array)
		{
			base_type::operator=(array);

			return *this;
		}
	};
	static_assert(sizeof(GArrayDH<void*>) == 0x20);
}
