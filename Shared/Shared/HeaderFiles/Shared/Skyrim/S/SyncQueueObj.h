#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSIntrusiveRefCounted.h"



namespace Skyrim
{
	class SyncQueueObj :
		public BSIntrusiveRefCounted // 0
	{
	public:
		// Add
		virtual ~SyncQueueObj();                           // 0
		virtual std::uint32_t QueuedSynchronization() = 0; // 1

		// Member variables
		std::uint32_t paddingC; // C
	};
	static_assert(sizeof(SyncQueueObj) == 0x10);
}
