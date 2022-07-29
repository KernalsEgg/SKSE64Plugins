#include "Shared/PCH.h"

#include "Shared/Skyrim/S/ScrapHeap.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void* ScrapHeap::Allocate(std::size_t size, std::size_t alignment)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&ScrapHeap::Allocate)>::type>(Addresses::ScrapHeap::Allocate) };

		return function(this, size, alignment);
	}

	void ScrapHeap::Deallocate(void* pointer)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&ScrapHeap::Deallocate)>::type>(Addresses::ScrapHeap::Deallocate) };

		function(this, pointer);
	}
}
