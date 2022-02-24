#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class GRefCountImplCore
	{
	public:
		// Add
		virtual ~GRefCountImplCore(); // 0

		// Member functions
		constexpr std::uint32_t GetReferenceCount() const noexcept { return this->referenceCount_; }

	protected:
		// Member variables
		volatile std::uint32_t referenceCount_; // 8
		std::uint32_t          paddingC;        // C
	};
	static_assert(sizeof(GRefCountImplCore) == 0x10);
}
