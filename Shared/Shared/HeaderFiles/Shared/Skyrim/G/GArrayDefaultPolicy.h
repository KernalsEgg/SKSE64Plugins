#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	struct GArrayDefaultPolicy
	{
	public:
		GArrayDefaultPolicy();
		GArrayDefaultPolicy(const GArrayDefaultPolicy&);

		// Member functions
		UPInt GetMinimumCapacity() const;
		UPInt GetGranularity() const;
		bool  NeverShrinking() const;

		UPInt GetCapacity() const;
		void  SetCapacity(UPInt capacity);

	private:
		// Member variables
		UPInt capacity_; // 0
	};
	static_assert(sizeof(GArrayDefaultPolicy) == 0x8);
}
