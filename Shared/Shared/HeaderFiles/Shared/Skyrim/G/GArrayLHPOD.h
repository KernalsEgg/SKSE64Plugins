#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GArrayBase.h"
#include "Shared/Skyrim/G/GArrayData.h"
#include "Shared/Skyrim/G/GArrayDefaultPolicy.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	template <class T, std::uint32_t STATISTIC_ID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory), class SizePolicy = GArrayDefaultPolicy>
	class GArrayLHPOD :
		public GArrayBase<GArrayData<T, GAllocatorLHPOD<T, STATISTIC_ID>, SizePolicy>> // 0
	{
	public:
		using value_type       = T;
		using allocator_type   = GAllocatorLH<T, STATISTIC_ID>;
		using size_policy_type = SizePolicy;
		using self_type        = GArrayLHPOD<T, STATISTIC_ID, SizePolicy>;
		using base_type        = GArrayBase<GArrayData<T, GAllocatorLHPOD<T, STATISTIC_ID>, SizePolicy>>;

		GArrayLHPOD() :
			base_type()
		{
		}

		GArrayLHPOD(std::uint32_t size) :
			base_type(size)
		{
		}

		GArrayLHPOD(const size_policy_type& policy) :
			base_type()
		{
			this->SetSizePolicy(policy);
		}

		GArrayLHPOD(const self_type& array) :
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
	static_assert(sizeof(GArrayLHPOD<void*>) == 0x18);
}
