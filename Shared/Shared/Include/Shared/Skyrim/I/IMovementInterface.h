#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class IMovementInterface
	{
	public:
		// Add
		virtual ~IMovementInterface(); // 0
	};
	static_assert(sizeof(IMovementInterface) == 0x8);
}
