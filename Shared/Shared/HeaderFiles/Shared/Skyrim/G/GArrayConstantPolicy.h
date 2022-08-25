#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <std::uint32_t MinimumCapacity = 0, std::uint32_t Granularity = 4, bool NeverShrink = false>
	struct GArrayConstantPolicy
	{
	public:
		using self_type = GArrayConstantPolicy<MinimumCapacity, Granularity, NeverShrink>;

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
			return MinimumCapacity;
		}

		UPInt GetGranularity() const
		{
			return Granularity;
		}

		bool NeverShrinking() const
		{
			return NeverShrink;
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
