#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class GMatrix2D
	{
	public:
		// Non-member variables
		static GMatrix2D Identity;

		// Member variables
		float elements[2][3]{
			{ 1.0F, 0.0F, 0.0F },
			{ 0.0F, 1.0F, 0.0F }
		}; // 0
	};
	static_assert(offsetof(GMatrix2D, elements) == 0x0);
	static_assert(sizeof(GMatrix2D) == 0x18);
}
