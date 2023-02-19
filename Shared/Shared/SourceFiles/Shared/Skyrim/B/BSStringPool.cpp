#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSStringPool.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	void BSStringPool::Entry::Release(const char*& string)
	{
		auto* function{ reinterpret_cast<decltype(BSStringPool::Entry::Release)*>(Addresses::BSStringPool::Entry::Release) };

		function(string);
	}

	void BSStringPool::Entry::Acquire()
	{
		std::atomic_ref flags{ const_cast<std::uint16_t&>(this->flags_) };
		std::uint16_t   expected;

		do
		{
			expected = flags;
		} while (((expected & Entry::kReferenceCountMask) != Entry::kReferenceCountMask) && !flags.compare_exchange_weak(expected, static_cast<std::uint16_t>(expected + 1)));
	}
}
