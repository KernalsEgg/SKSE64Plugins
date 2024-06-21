#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	template <class T>
	class GRectangle
	{
	public:
		enum class BoundsType : std::uint32_t
		{
			kMinimum,
			kMaximum
		};
		static_assert(sizeof(BoundsType) == 0x4);

		// Member variables
		T left;   // 0
		T top;    // ?
		T right;  // ?
		T bottom; // ?
	};

	using GRectangleF = GRectangle<float>;
	static_assert(sizeof(GRectangleF) == 0x10);

	using GRectangleD = GRectangle<double>;
	static_assert(sizeof(GRectangleD) == 0x20);
}
