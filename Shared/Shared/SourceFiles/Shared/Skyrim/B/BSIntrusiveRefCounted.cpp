#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSIntrusiveRefCounted.h"



namespace Skyrim
{
	std::uint32_t BSIntrusiveRefCounted::DecrementReferenceCount() const
	{
		std::atomic_ref referenceCount(const_cast<std::uint32_t&>(this->referenceCount_));

		return --referenceCount;
	}

	std::uint32_t BSIntrusiveRefCounted::IncrementReferenceCount() const
	{
		std::atomic_ref referenceCount(const_cast<std::uint32_t&>(this->referenceCount_));

		return ++referenceCount;
	}
}
