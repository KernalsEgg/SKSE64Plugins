#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GSysAllocBase.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	class GSysAlloc :
		public GSysAllocBase // 0
	{
	public:
		// Override
		virtual ~GSysAlloc(); // 0

	protected:
		// Override (GSysAllocBase)
		virtual bool InitializeHeapEngine(const void* heapDescriptor); // 1
		virtual void ShutdownHeapEngine();                             // 2

	public:
		// Add
		virtual void* Allocate(UPInt size, UPInt alignment)                                       = 0; // 3
		virtual void  Free(void* pointer, UPInt size, UPInt alignment)                            = 0; // 4
		virtual void* Reallocate(void* oldPointer, UPInt oldSize, UPInt newSize, UPInt alignment) = 0; // 5
	};
	static_assert(sizeof(GSysAlloc) == 0x8);
}
