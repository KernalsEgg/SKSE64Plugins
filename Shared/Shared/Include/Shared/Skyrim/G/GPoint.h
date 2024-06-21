#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	template <class T>
	class GPoint
	{
	public:
		enum class BoundsType : std::uint32_t
		{
			kMinimum,
			kMaximum
		};
		static_assert(sizeof(BoundsType) == 0x4);

		// Member variables
		T x; // 0
		T y; // ?
	};

	using GPointF = GPoint<float>;
	static_assert(sizeof(GPointF) == 0x8);

	using GPointD = GPoint<double>;
	static_assert(sizeof(GPointD) == 0x10);
}
