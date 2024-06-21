#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkStringPointer.h"



namespace Skyrim
{
	const char* hkStringPointer::data() const
	{
		return reinterpret_cast<const char*>(reinterpret_cast<std::uintptr_t>(this->stringAndFlag_) & ~static_cast<std::uintptr_t>(Flags::kOwned));
	}
}
