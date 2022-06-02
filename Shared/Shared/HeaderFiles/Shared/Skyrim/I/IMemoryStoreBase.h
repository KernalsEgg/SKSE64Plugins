#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	struct MemoryStatistics
	{
	public:
		// Member variables
		const char*   name;          // 0
		std::size_t   usedSize;      // 8
		std::size_t   committedSize; // 10
		std::size_t   reservedSize;  // 18
		std::uint32_t overhead;      // 20
		std::uint32_t padding24;     // 24
		std::size_t   freeSize;      // 28
	};
	static_assert(offsetof(MemoryStatistics, name) == 0x0);
	static_assert(offsetof(MemoryStatistics, usedSize) == 0x8);
	static_assert(offsetof(MemoryStatistics, committedSize) == 0x10);
	static_assert(offsetof(MemoryStatistics, reservedSize) == 0x18);
	static_assert(offsetof(MemoryStatistics, overhead) == 0x20);
	static_assert(offsetof(MemoryStatistics, freeSize) == 0x28);
	static_assert(sizeof(MemoryStatistics) == 0x30);

	class IMemoryStoreBase
	{
	public:
		// Add
		virtual ~IMemoryStoreBase();                                                     // 0
		virtual std::size_t Size(const void* memory) const                          = 0; // 1
		virtual void        GetMemoryStatistics(MemoryStatistics* memoryStatistics) = 0; // 2
		virtual bool        ContainsBlockImplementation(const void* block) const    = 0; // 3
	};
	static_assert(sizeof(IMemoryStoreBase) == 0x8);
}
