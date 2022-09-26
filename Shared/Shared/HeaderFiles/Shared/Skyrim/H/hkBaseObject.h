#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class hkBaseObject
	{
	public:
		// Add
		virtual ~hkBaseObject(); // 0
	};
	static_assert(sizeof(hkBaseObject) == 0x8);
}
