#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/C/Color.h"



namespace Skyrim
{
	struct DirectionalAmbientLighting
	{
	public:
		struct Axis
		{
			Color positive; // 0
			Color negative; // 4
		};
		static_assert(offsetof(Axis, positive) == 0x0);
		static_assert(offsetof(Axis, negative) == 0x4);
		static_assert(sizeof(Axis) == 0x8);

		Axis  x;                    // 0
		Axis  y;                    // 8
		Axis  z;                    // 10
		Color specular;             // 18
		float specularFresnelPower; // 1C
	};
	static_assert(offsetof(DirectionalAmbientLighting, x) == 0x0);
	static_assert(offsetof(DirectionalAmbientLighting, y) == 0x8);
	static_assert(offsetof(DirectionalAmbientLighting, z) == 0x10);
	static_assert(offsetof(DirectionalAmbientLighting, specular) == 0x18);
	static_assert(offsetof(DirectionalAmbientLighting, specularFresnelPower) == 0x1C);
	static_assert(sizeof(DirectionalAmbientLighting) == 0x20);
}
