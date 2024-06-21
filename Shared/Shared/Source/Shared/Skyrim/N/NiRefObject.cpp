#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiRefObject.h"



namespace Skyrim
{
	void NiRefObject::DecrementReferenceCount()
	{
		std::atomic_ref referenceCount(const_cast<std::uint32_t&>(this->referenceCount_));

		if (--referenceCount == 0)
		{
			this->DeleteThis();
		}
	}

	void NiRefObject::IncrementReferenceCount()
	{
		std::atomic_ref referenceCount(const_cast<std::uint32_t&>(this->referenceCount_));

		++referenceCount;
	}
}
