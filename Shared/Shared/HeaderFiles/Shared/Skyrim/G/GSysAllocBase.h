#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class GSysAllocBase
	{
	public:
		// Add
		virtual ~GSysAllocBase();                                      // 0
		virtual bool InitializeHeapEngine(const void* heapDescriptor); // 1
		virtual void ShutdownHeapEngine();                             // 2
	};
	static_assert(sizeof(GSysAllocBase) == 0x8);
}
