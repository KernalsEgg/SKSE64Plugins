#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	template <class T>
	class GPoint3
	{
	public:
		// Member variables
		T x; // 0
		T y; // ?
		T z; // ?
	};

	using GPoint3F = GPoint3<float>;
	static_assert(sizeof(GPoint3F) == 0xC);
}
