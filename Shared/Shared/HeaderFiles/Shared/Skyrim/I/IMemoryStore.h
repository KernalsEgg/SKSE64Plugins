#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/IMemoryStoreBase.h"



namespace Skyrim
{
	class IMemoryStore :
		public IMemoryStoreBase // 0
	{
	public:
		// Override
		virtual ~IMemoryStore() override; // 0

		// Add
		virtual void* AllocateAlignedImplementation(std::size_t size, std::uint32_t alignment) = 0; // 4
		virtual void  DeallocateAlignedImplementation(void*& block)                            = 0; // 5
		virtual void* TryAllocateAlignedImplementation(std::size_t size, std::uint32_t alignment);  // 6
	};
	static_assert(sizeof(IMemoryStore) == 0x8);
}
