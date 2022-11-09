#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTMessageQueue.h"



namespace Skyrim
{
	struct BSPackedTask;

	struct BSPackedTaskQueue
	{
	public:
		using UnpackFunction = void(const BSPackedTask*);

		struct Semaphore
		{
		public:
			// Member variables
			void*         handle;   // 0
			std::uint32_t size;     // 8
			std::uint32_t capacity; // C
		};
		static_assert(offsetof(Semaphore, handle) == 0x0);
		static_assert(offsetof(Semaphore, size) == 0x8);
		static_assert(offsetof(Semaphore, capacity) == 0xC);
		static_assert(sizeof(Semaphore) == 0x10);

		// Member variables
		BSTCommonScrapHeapMessageQueue<BSPackedTask> queue;          // 0
		mutable Semaphore                            semaphore;      // 28
		UnpackFunction*                              unpackFunction; // 38
	};
	static_assert(offsetof(BSPackedTaskQueue, queue) == 0x0);
	static_assert(offsetof(BSPackedTaskQueue, semaphore) == 0x28);
	static_assert(offsetof(BSPackedTaskQueue, unpackFunction) == 0x38);
	static_assert(sizeof(BSPackedTaskQueue) == 0x40);
}
