#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiMatrix33.h"
#include "Shared/Skyrim/N/NiPoint3.h"



namespace Skyrim
{
	class NiTransform
	{
	public:
		// Member variables
		NiMatrix33 rotation;    // 0
		NiPoint3   translation; // 24
		float      scale;       // 30
	};
	static_assert(offsetof(NiTransform, rotation) == 0x0);
	static_assert(offsetof(NiTransform, translation) == 0x24);
	static_assert(offsetof(NiTransform, scale) == 0x30);
	static_assert(sizeof(NiTransform) == 0x34);
}
