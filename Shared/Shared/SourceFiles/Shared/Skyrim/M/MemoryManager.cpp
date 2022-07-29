#include "Shared/PCH.h"

#include "Shared/Skyrim/M/MemoryManager.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	MemoryManager* MemoryManager::GetSingleton()
	{
		auto* function{ reinterpret_cast<decltype(&MemoryManager::GetSingleton)>(Addresses::MemoryManager::GetSingleton) };

		return function();
	}

	void* MemoryManager::Allocate(std::size_t size, std::uint32_t alignment, bool aligned)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&MemoryManager::Allocate)>::type>(Addresses::MemoryManager::Allocate) };

		return function(this, size, alignment, aligned);
	}

	void MemoryManager::Deallocate(void* pointer, bool aligned)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&MemoryManager::Deallocate)>::type>(Addresses::MemoryManager::Deallocate) };

		function(this, pointer, aligned);
	}

	ScrapHeap* MemoryManager::GetThreadScrapHeap()
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&MemoryManager::GetThreadScrapHeap)>::type>(Addresses::MemoryManager::GetThreadScrapHeap) };

		return function(this);
	}

	void* MemoryManager::Reallocate(void* pointer, std::size_t size, std::uint32_t alignment, bool aligned)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&MemoryManager::Reallocate)>::type>(Addresses::MemoryManager::Reallocate) };

		return function(this, pointer, size, alignment, aligned);
	}
}
