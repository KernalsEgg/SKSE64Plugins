#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <std::uint32_t MINIMUM_CAPACITY = 0, std::uint32_t GRANULARITY = 4, bool NEVER_SHRINK = false>
	struct GArrayConstantPolicy
	{
	public:
		using self_type = GArrayConstantPolicy<MINIMUM_CAPACITY, GRANULARITY, NEVER_SHRINK>;

		GArrayConstantPolicy() :
			capacity_(0)
		{
		}

		GArrayConstantPolicy(const self_type&) :
			capacity_(0)
		{
		}

		// Member functions
		UPInt GetMinimumCapacity() const
		{
			return MINIMUM_CAPACITY;
		}

		UPInt GetGranularity() const
		{
			return GRANULARITY;
		}

		bool NeverShrinking() const
		{
			return NEVER_SHRINK;
		}

		UPInt GetCapacity() const
		{
			return this->capacity_;
		}

		void SetCapacity(UPInt capacity)
		{
			this->capacity_ = capacity;
		}

	private:
		// Member variables
		UPInt capacity_; // 0
	};
	static_assert(sizeof(GArrayConstantPolicy<>) == 0x8);
}
