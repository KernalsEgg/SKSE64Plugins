#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class GMatrix3D
	{
	public:
		// Non-member variables
		static GMatrix3D Identity;

		// Member variables
		float elements[4][4]{
			{ 1.0F, 0.0F, 0.0F, 0.0F },
			{ 0.0F, 1.0F, 0.0F, 0.0F },
			{ 0.0F, 0.0F, 1.0F, 0.0F },
			{ 0.0F, 0.0F, 0.0F, 1.0F }
		}; // 0
	};
	static_assert(offsetof(GMatrix3D, elements) == 0x0);
	static_assert(sizeof(GMatrix3D) == 0x40);
}
