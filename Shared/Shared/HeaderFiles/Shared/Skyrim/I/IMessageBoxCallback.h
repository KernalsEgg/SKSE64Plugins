#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSIntrusiveRefCounted.h"



namespace Skyrim
{
	class IMessageBoxCallback :
		public BSIntrusiveRefCounted // 0
	{
	public:
		// Add
		virtual ~IMessageBoxCallback()            = default; // 0
		virtual void Run(std::int8_t buttonIndex) = 0;       // 1
	};
	static_assert(sizeof(IMessageBoxCallback) == 0x10);
}
