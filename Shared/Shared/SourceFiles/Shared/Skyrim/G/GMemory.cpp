#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GMemory.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	void GMemory::SetGlobalHeap(GMemoryHeap* heap)
	{
		GMemory::GetGlobalHeapReference() = heap;
	}

	GMemoryHeap* GMemory::GetGlobalHeap()
	{
		return GMemory::GetGlobalHeapReference();
	}

	void GMemory::CreateArena(UPInt arena, GSysAllocPaged* systemAllocation)
	{
		GMemory::GetGlobalHeapReference()->CreateArena(arena, systemAllocation);
	}

	void GMemory::DestroyArena(UPInt arena)
	{
		GMemory::GetGlobalHeapReference()->DestroyArena(arena);
	}

	bool GMemory::ArenaIsEmpty(UPInt arena)
	{
		return GMemory::GetGlobalHeapReference()->ArenaIsEmpty(arena);
	}

	void* GMemory::Allocate(UPInt size)
	{
		return GMemory::GetGlobalHeapReference()->Allocate(size);
	}

	void* GMemory::Allocate(UPInt size, UPInt alignment)
	{
		return GMemory::GetGlobalHeapReference()->Allocate(size, alignment);
	}

	void* GMemory::AllocateAutomaticHeap(const void* pointer, UPInt size)
	{
		return GMemory::GetGlobalHeapReference()->AllocateAutomaticHeap(pointer, size);
	}

	void* GMemory::AllocateAutomaticHeap(const void* pointer, UPInt size, UPInt alignment)
	{
		return GMemory::GetGlobalHeapReference()->AllocateAutomaticHeap(pointer, size, alignment);
	}

	void* GMemory::AllocateInHeap(GMemoryHeap* heap, UPInt size)
	{
		return heap->Allocate(size);
	}

	void* GMemory::AllocateInHeap(GMemoryHeap* heap, UPInt size, UPInt alignment)
	{
		return heap->Allocate(size, alignment);
	}

	void* GMemory::Reallocate(void* pointer, UPInt newSize)
	{
		return GMemory::GetGlobalHeapReference()->Reallocate(pointer, newSize);
	}

	void GMemory::Free(void* pointer)
	{
		if (pointer)
		{
			GMemory::GetGlobalHeapReference()->Free(pointer);
		}
	}

	void GMemory::FreeInHeap(GMemoryHeap* heap, void* pointer)
	{
		if (pointer)
		{
			heap->Free(pointer);
		}
	}

	GMemoryHeap* GMemory::GetHeapByAddress(const void* pointer)
	{
		return GMemory::GetGlobalHeapReference()->GetAllocatedHeap(pointer);
	}

	bool GMemory::DetectMemoryLeaks()
	{
		return GMemory::GetGlobalHeapReference()->DumpMemoryLeaks();
	}

	GMemoryHeap*& GMemory::GetGlobalHeapReference()
	{
		auto** singleton{ reinterpret_cast<GMemoryHeap**>(Addresses::GMemory::GlobalHeap) };

		return *singleton;
	}
}
