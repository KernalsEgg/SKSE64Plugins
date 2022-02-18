#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	struct BSIntrusiveRefCounted
	{
	public:
		// Member functions
		std::uint32_t DecrementReferenceCount() const;
		std::uint32_t IncrementReferenceCount() const;

	protected:
		// Member variables
		mutable volatile std::uint32_t referenceCount_{ 0 }; // 0
	};
	static_assert(sizeof(BSIntrusiveRefCounted) == 0x4);
}
