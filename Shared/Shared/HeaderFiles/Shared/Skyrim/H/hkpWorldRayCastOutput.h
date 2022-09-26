#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpShapeRayCastOutput.h"



namespace Skyrim
{
	class hkpCollidable;

	struct hkpWorldRayCastOutput :
		public hkpShapeRayCastOutput // 0
	{
	public:
		// Member functions
		constexpr bool HasHit() const noexcept
		{
			return this->rootCollidable != nullptr;
		}

		constexpr void Reset() noexcept
		{
			this->hkpShapeRayCastOutput::Reset();

			this->rootCollidable = nullptr;
		}

		// Member variables
		const hkpCollidable* rootCollidable{ nullptr }; // 50
		std::uint64_t        padding58;                 // 58
	};
	static_assert(offsetof(hkpWorldRayCastOutput, rootCollidable) == 0x50);
	static_assert(sizeof(hkpWorldRayCastOutput) == 0x60);
}
