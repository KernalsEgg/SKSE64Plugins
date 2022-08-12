#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/S/ScrapHeap.h"



namespace Skyrim
{
	namespace CompactingStore
	{
		class Store;
	}

	class BSSmallBlockAllocator;
	class IMemoryHeap;

	class MemoryManager
	{
	public:
		struct ThreadScrapHeap
		{
		public:
			// Member variables
			ScrapHeap        scrapHeap;    // 0
			ThreadScrapHeap* next;         // 90
			std::uint32_t    owningThread; // 98
			std::uint32_t    padding9C;    // 9C
		};
		static_assert(offsetof(ThreadScrapHeap, scrapHeap) == 0x0);
		static_assert(offsetof(ThreadScrapHeap, next) == 0x90);
		static_assert(offsetof(ThreadScrapHeap, owningThread) == 0x98);
		static_assert(sizeof(ThreadScrapHeap) == 0xA0);

		// Non-member functions
		static MemoryManager* GetSingleton();

		// Member functions
		void*      Allocate(std::size_t size, std::uint32_t alignment, bool aligned);
		void       Deallocate(void* pointer, bool aligned);
		ScrapHeap* GetThreadScrapHeap();
		void*      Reallocate(void* pointer, std::size_t size, std::uint32_t alignment, bool aligned);

		// Member variables
		bool                    initialized;                               // 0
		std::uint8_t            padding1;                                  // 1
		std::uint16_t           heapCount;                                 // 2
		std::uint16_t           physicalHeapCount;                         // 4
		IMemoryHeap**           heaps;                                     // 8
		bool*                   allowOtherContextAllocations;              // 10
		IMemoryHeap*            heapsByContext[127];                       // 18
		ThreadScrapHeap*        threadScrapHeap;                           // 410
		IMemoryHeap**           physicalHeaps;                             // 418
		IMemoryHeap*            bigAllocationHeap;                         // 420
		IMemoryHeap*            emergencyHeap;                             // 428
		BSSmallBlockAllocator*  smallBlockAllocator;                       // 430
		CompactingStore::Store* compactingStore;                           // 438
		IMemoryHeap*            externalHavokAllocator;                    // 440
		bool                    specialHeaps;                              // 448
		bool                    allowPooling;                              // 449
		std::uint16_t           padding44A;                                // 44A
		std::uint32_t           systemAllocatedSize;                       // 44C
		std::uint32_t           mallocSize;                                // 450
		std::uint32_t           poolAlignment;                             // 454
		std::uint32_t           mainThreadMemoryProblemPassSignal;         // 458
		std::uint32_t           padding45C;                                // 45C
		std::size_t             failedAllocationSize;                      // 460
		std::uint32_t           mainThreadMemoryProblemPassSignalCount;    // 468
		std::uint32_t           padding46C;                                // 46C
		std::size_t             lastMainThreadMemoryProblemPassSignalTime; // 470
		IMemoryHeap*            defaultHeap;                               // 478
	};
	static_assert(offsetof(MemoryManager, initialized) == 0x0);
	static_assert(offsetof(MemoryManager, heapCount) == 0x2);
	static_assert(offsetof(MemoryManager, physicalHeapCount) == 0x4);
	static_assert(offsetof(MemoryManager, heaps) == 0x8);
	static_assert(offsetof(MemoryManager, allowOtherContextAllocations) == 0x10);
	static_assert(offsetof(MemoryManager, heapsByContext) == 0x18);
	static_assert(offsetof(MemoryManager, threadScrapHeap) == 0x410);
	static_assert(offsetof(MemoryManager, physicalHeaps) == 0x418);
	static_assert(offsetof(MemoryManager, bigAllocationHeap) == 0x420);
	static_assert(offsetof(MemoryManager, emergencyHeap) == 0x428);
	static_assert(offsetof(MemoryManager, smallBlockAllocator) == 0x430);
	static_assert(offsetof(MemoryManager, compactingStore) == 0x438);
	static_assert(offsetof(MemoryManager, externalHavokAllocator) == 0x440);
	static_assert(offsetof(MemoryManager, specialHeaps) == 0x448);
	static_assert(offsetof(MemoryManager, allowPooling) == 0x449);
	static_assert(offsetof(MemoryManager, systemAllocatedSize) == 0x44C);
	static_assert(offsetof(MemoryManager, mallocSize) == 0x450);
	static_assert(offsetof(MemoryManager, poolAlignment) == 0x454);
	static_assert(offsetof(MemoryManager, mainThreadMemoryProblemPassSignal) == 0x458);
	static_assert(offsetof(MemoryManager, failedAllocationSize) == 0x460);
	static_assert(offsetof(MemoryManager, mainThreadMemoryProblemPassSignalCount) == 0x468);
	static_assert(offsetof(MemoryManager, lastMainThreadMemoryProblemPassSignalTime) == 0x470);
	static_assert(offsetof(MemoryManager, defaultHeap) == 0x478);
	static_assert(sizeof(MemoryManager) == 0x480);

	inline void* malloc(std::size_t size)
	{
		auto* memoryManager = MemoryManager::GetSingleton();

		return memoryManager ? memoryManager->Allocate(size, 0, false) : nullptr;
	}

	template <class T>
	inline T* malloc()
	{
		return static_cast<T*>(Skyrim::malloc(sizeof(T)));
	}

	inline void* aligned_malloc(std::size_t size, std::size_t alignment)
	{
		auto* memoryManager = MemoryManager::GetSingleton();

		return memoryManager ? memoryManager->Allocate(size, static_cast<std::uint32_t>(alignment), true) : nullptr;
	}

	template <class T>
	inline T* aligned_malloc()
	{
		return static_cast<T*>(Skyrim::aligned_malloc(sizeof(T), alignof(T)));
	}

	inline void free(void* pointer)
	{
		auto* memoryManager = MemoryManager::GetSingleton();

		if (memoryManager)
		{
			memoryManager->Deallocate(pointer, false);
		}
	}

	inline void aligned_free(void* pointer)
	{
		auto* memoryManager = MemoryManager::GetSingleton();

		if (memoryManager)
		{
			memoryManager->Deallocate(pointer, true);
		}
	}

#define TES_MEMORY_REDEFINE_NEW()                                                                      \
	/* 1 */                                                                                            \
	[[nodiscard]] void* operator new(std::size_t size)                                                 \
	{                                                                                                  \
		auto* pointer = Skyrim::malloc(size);                                                          \
                                                                                                       \
		if (!pointer)                                                                                  \
		{                                                                                              \
			throw std::bad_alloc{};                                                                    \
		}                                                                                              \
                                                                                                       \
		return pointer;                                                                                \
	}                                                                                                  \
                                                                                                       \
	/* 2 */                                                                                            \
	[[nodiscard]] void* operator new[](std::size_t size)                                               \
	{                                                                                                  \
		return operator new(size);                                                                     \
	}                                                                                                  \
                                                                                                       \
	/* 3 */                                                                                            \
	[[nodiscard]] void* operator new(std::size_t size, std::align_val_t alignment)                     \
	{                                                                                                  \
		auto* pointer = Skyrim::aligned_malloc(size, static_cast<std::size_t>(alignment));             \
                                                                                                       \
		if (!pointer)                                                                                  \
		{                                                                                              \
			throw std::bad_alloc{};                                                                    \
		}                                                                                              \
                                                                                                       \
		return pointer;                                                                                \
	}                                                                                                  \
                                                                                                       \
	/* 4 */                                                                                            \
	[[nodiscard]] void* operator new[](std::size_t size, std::align_val_t alignment)                   \
	{                                                                                                  \
		return operator new(size, alignment);                                                          \
	}                                                                                                  \
                                                                                                       \
	/* 9 */                                                                                            \
	[[nodiscard]] void* operator new([[maybe_unused]] std::size_t size, void* placement) noexcept      \
	{                                                                                                  \
		return placement;                                                                              \
	}                                                                                                  \
                                                                                                       \
	/* 10 */                                                                                           \
	[[nodiscard]] void* operator new[](std::size_t size, void* placement) noexcept                     \
	{                                                                                                  \
		return operator new(size, placement);                                                          \
	}                                                                                                  \
                                                                                                       \
	/* 1 */                                                                                            \
	void operator delete(void* pointer)                                                                \
	{                                                                                                  \
		Skyrim::free(pointer);                                                                         \
	}                                                                                                  \
                                                                                                       \
	/* 2 */                                                                                            \
	void operator delete[](void* pointer)                                                              \
	{                                                                                                  \
		operator delete(pointer);                                                                      \
	}                                                                                                  \
                                                                                                       \
	/* 3 */                                                                                            \
	void operator delete(void* pointer, [[maybe_unused]] std::align_val_t alignment)                   \
	{                                                                                                  \
		Skyrim::aligned_free(pointer);                                                                 \
	}                                                                                                  \
                                                                                                       \
	/* 4 */                                                                                            \
	void operator delete[](void* pointer, std::align_val_t alignment)                                  \
	{                                                                                                  \
		operator delete(pointer, alignment);                                                           \
	}                                                                                                  \
                                                                                                       \
	/* 5 */                                                                                            \
	void operator delete(void* pointer, [[maybe_unused]] std::size_t size)                             \
	{                                                                                                  \
		operator delete(pointer);                                                                      \
	}                                                                                                  \
                                                                                                       \
	/* 6 */                                                                                            \
	void operator delete[](void* pointer, std::size_t size)                                            \
	{                                                                                                  \
		operator delete(pointer, size);                                                                \
	}                                                                                                  \
                                                                                                       \
	/* 7 */                                                                                            \
	void operator delete(void* pointer, [[maybe_unused]] std::size_t size, std::align_val_t alignment) \
	{                                                                                                  \
		operator delete(pointer, alignment);                                                           \
	}                                                                                                  \
                                                                                                       \
	/* 8 */                                                                                            \
	void operator delete[](void* pointer, std::size_t size, std::align_val_t alignment)                \
	{                                                                                                  \
		operator delete(pointer, size, alignment);                                                     \
	}
}
