#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class hkStringPtr
	{
	public:
		enum Flags : std::uint32_t
		{
			kOwned = 1U << 0
		};
		static_assert(sizeof(Flags) == 0x4);

		// Member functions
		const char* data() const;

	private:
		// Member variables
		const char* stringAndFlag_; // 0
	};
	static_assert(sizeof(hkStringPtr) == 0x8);
}
