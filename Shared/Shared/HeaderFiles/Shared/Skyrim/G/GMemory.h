#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GMemoryHeap.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	class GSysAllocPaged;

	class GMemory
	{
	public:
		// Non-member functions
		static void         SetGlobalHeap(GMemoryHeap* heap);
		static GMemoryHeap* GetGlobalHeap();
		static void         CreateArena(UPInt arena, GSysAllocPaged* systemAllocation);
		static void         DestroyArena(UPInt arena);
		static bool         ArenaIsEmpty(UPInt arena);
		static void*        Allocate(UPInt size);
		static void*        Allocate(UPInt size, UPInt alignment);
		static void*        AllocateAutomaticHeap(const void* pointer, UPInt size);
		static void*        AllocateAutomaticHeap(const void* pointer, UPInt size, UPInt alignment);
		static void*        AllocateInHeap(GMemoryHeap* heap, UPInt size);
		static void*        AllocateInHeap(GMemoryHeap* heap, UPInt size, UPInt alignment);
		static void*        Reallocate(void* pointer, UPInt newSize);
		static void         Free(void* pointer);
		static void         FreeInHeap(GMemoryHeap* heap, void* pointer);
		static GMemoryHeap* GetHeapByAddress(const void* pointer);
		static bool         DetectMemoryLeaks();

	protected:
		static GMemoryHeap*& GetGlobalHeapReference();
	};
	static_assert(std::is_empty_v<GMemory>);

// Global heap
#define GALLOCATE(size)                    Skyrim::GMemory::Allocate((size))
#define GALLOCATE_ALIGNED(size, alignment) Skyrim::GMemory::Allocate((size), (alignment))
#define GREALLOCATE(pointer, newSize)      Skyrim::GMemory::Reallocate((pointer), (newSize))
#define GFREE(pointer)                     Skyrim::GMemory::Free((pointer))
#define GFREE_ALIGNED(pointer)             Skyrim::GMemory::Free((pointer))

// Local heap
#define GHEAP_ALLOCATE(heap, size)                    Skyrim::GMemory::AllocateInHeap((heap), (size))
#define GHEAP_ALLOCATE_ALIGNED(heap, size, alignment) Skyrim::GMemory::AllocateInHeap((heap), (size), (alignment))
#define GHEAP_AUTOMATIC_ALLOCATE(pointer, size)       Skyrim::GMemory::AllocateAutomaticHeap((pointer), (size))
#define GHEAP_FREE(heap, pointer)                     Skyrim::GMemory::FreeInHeap((heap), (pointer))

#define GFC_MEMORY_REDEFINE_NEW_IMPLEMENTATION(className, checkDelete, statisticType) \
	/* 1 */                                                                           \
	[[nodiscard]] void* operator new(Skyrim::UPInt size)                              \
	{                                                                                 \
		return GALLOCATE(size);                                                       \
	}                                                                                 \
                                                                                      \
	/* 2 */                                                                           \
	[[nodiscard]] void* operator new[](Skyrim::UPInt size)                            \
	{                                                                                 \
		return GALLOCATE(size);                                                       \
	}                                                                                 \
                                                                                      \
	/* 9 */                                                                           \
	[[nodiscard]] void* operator new(Skyrim::UPInt /* size */, void* placement)       \
	{                                                                                 \
		return placement;                                                             \
	}                                                                                 \
                                                                                      \
	/* 10 */                                                                          \
	[[nodiscard]] void* operator new[](Skyrim::UPInt /* size */, void* placement)     \
	{                                                                                 \
		return placement;                                                             \
	}                                                                                 \
                                                                                      \
	[[nodiscard]] void* operator new(Skyrim::UPInt size, Skyrim::GMemoryHeap* heap)   \
	{                                                                                 \
		return GHEAP_ALLOCATE(heap, size);                                            \
	}                                                                                 \
                                                                                      \
	[[nodiscard]] void* operator new[](Skyrim::UPInt size, Skyrim::GMemoryHeap* heap) \
	{                                                                                 \
		return GHEAP_ALLOCATE(heap, size);                                            \
	}                                                                                 \
                                                                                      \
	/* 1 */                                                                           \
	void operator delete(void* pointer)                                               \
	{                                                                                 \
		GFREE(pointer);                                                               \
	}                                                                                 \
                                                                                      \
	/* 2 */                                                                           \
	void operator delete[](void* pointer)                                             \
	{                                                                                 \
		GFREE(pointer);                                                               \
	}                                                                                 \
                                                                                      \
	/* 13 */                                                                          \
	void operator delete(void* /* pointer */, void* /* placement */)                  \
	{                                                                                 \
	}                                                                                 \
                                                                                      \
	/* 14 */                                                                          \
	void operator delete[](void* /* pointer */, void* /* placement */)                \
	{                                                                                 \
	}                                                                                 \
                                                                                      \
	void operator delete(void* pointer, Skyrim::GMemoryHeap* heap)                    \
	{                                                                                 \
		GHEAP_FREE(heap, pointer);                                                    \
	}

#define GFC_MEMORY_CHECK_DELETE_NONE(className, pointer)
#define GFC_MEMORY_REDEFINE_NEW(className, statisticType) GFC_MEMORY_REDEFINE_NEW_IMPLEMENTATION(className, GFC_MEMORY_CHECK_DELETE_NONE, statisticType)
}
