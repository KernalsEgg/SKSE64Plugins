#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GArrayBase.h"
#include "Shared/Skyrim/G/GArrayDataCC.h"
#include "Shared/Skyrim/G/GArrayDefaultPolicy.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory), class SizePolicy = GArrayDefaultPolicy>
	class GArrayCC :
		public GArrayBase<GArrayDataCC<T, GAllocatorLH<T, StatisticID>, SizePolicy>> // 0
	{
	public:
		using value_type       = T;
		using allocator_type   = GAllocatorLH<T, StatisticID>;
		using size_policy_type = SizePolicy;
		using self_type        = GArrayCC<T, StatisticID, SizePolicy>;
		using base_type        = GArrayBase<GArrayDataCC<T, GAllocatorLH<T, StatisticID>, SizePolicy>>;

		GArrayCC(const value_type& defaultValue) :
			base_type(defaultValue)
		{
		}

		GArrayCC(const value_type& defaultValue, std::uint32_t size) :
			base_type(defaultValue, size)
		{
		}

		GArrayCC(const value_type& defaultValue, const size_policy_type& policy) :
			base_type(defaultValue)
		{
			this->SetSizePolicy(policy);
		}

		GArrayCC(const self_type& array) :
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
	static_assert(sizeof(GArrayCC<void*>) == 0x20);
}
