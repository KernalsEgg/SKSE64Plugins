#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkStringPtr.h"



namespace Skyrim
{
	const char* hkStringPtr::data() const
	{
		return reinterpret_cast<const char*>(reinterpret_cast<std::uintptr_t>(this->stringAndFlag_) & ~Flags::kOwned);
	}
}
