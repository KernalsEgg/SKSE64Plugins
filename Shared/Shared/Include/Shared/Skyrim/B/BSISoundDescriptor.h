#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class BSISoundDescriptor
	{
	public:
		// Add
		virtual ~BSISoundDescriptor();                  // 0
		virtual void Unknown1(BSISoundDescriptor*) = 0; // 1
		virtual void Unknown2(BSISoundDescriptor*) = 0; // 2
	};
	static_assert(sizeof(BSISoundDescriptor) == 0x8);
}
