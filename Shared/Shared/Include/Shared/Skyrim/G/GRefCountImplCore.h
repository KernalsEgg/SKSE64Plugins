#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class GRefCountImplCore
	{
	public:
		// Add
		virtual ~GRefCountImplCore(); // 0

		// Member functions
		constexpr std::int32_t GetReferenceCount() const noexcept { return this->referenceCount_; }

	protected:
		// Member variables
		volatile std::int32_t referenceCount_{ 1 }; // 8
		std::uint32_t         paddingC_;            // C
	};
	static_assert(sizeof(GRefCountImplCore) == 0x10);
}
