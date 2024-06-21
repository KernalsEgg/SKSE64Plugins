#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GArrayDefaultPolicy.h"



namespace Skyrim
{
	GArrayDefaultPolicy::GArrayDefaultPolicy() :
		capacity_(0)
	{
	}

	GArrayDefaultPolicy::GArrayDefaultPolicy(const GArrayDefaultPolicy&) :
		capacity_(0)
	{
	}

	UPInt GArrayDefaultPolicy::GetMinimumCapacity() const
	{
		return 0;
	}

	UPInt GArrayDefaultPolicy::GetGranularity() const
	{
		return 4;
	}

	bool GArrayDefaultPolicy::NeverShrinking() const
	{
		return false;
	}

	UPInt GArrayDefaultPolicy::GetCapacity() const
	{
		return this->capacity_;
	}

	void GArrayDefaultPolicy::SetCapacity(UPInt capacity)
	{
		this->capacity_ = capacity;
	}
}
