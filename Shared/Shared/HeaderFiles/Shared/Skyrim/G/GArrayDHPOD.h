#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GArrayBase.h"
#include "Shared/Skyrim/G/GArrayDataDH.h"
#include "Shared/Skyrim/G/GArrayDefaultPolicy.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class GMemoryHeap;

	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory), class SizePolicy = GArrayDefaultPolicy>
	class GArrayDHPOD :
		public GArrayBase<GArrayDataDH<T, GAllocatorDHPOD<T, STATISTIC_ID>, SizePolicy>> // 0
	{
	public:
		using value_type       = T;
		using allocator_type   = GAllocatorDH<T, STATISTIC_ID>;
		using size_policy_type = SizePolicy;
		using self_type        = GArrayDHPOD<T, STATISTIC_ID, SizePolicy>;
		using base_type        = GArrayBase<GArrayDataDH<T, GAllocatorDHPOD<T, STATISTIC_ID>, SizePolicy>>;

		GArrayDHPOD(GMemoryHeap* heap) :
			base_type(heap)
		{
		}

		GArrayDHPOD(GMemoryHeap* heap, std::uint32_t size) :
			base_type(heap, size)
		{
		}

		GArrayDHPOD(GMemoryHeap* heap, const size_policy_type& policy) :
			base_type(heap)
		{
			this->SetSizePolicy(policy);
		}

		GArrayDHPOD(const self_type& array) :
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
	static_assert(sizeof(GArrayDHPOD<void*>) == 0x20);
}
