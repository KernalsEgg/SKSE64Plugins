#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSHandleRefObject.h"



namespace Skyrim
{
	void BSHandleRefObject::DecrementReferenceCount()
	{
		std::atomic_ref referenceCount(const_cast<std::uint32_t&>(this->referenceCount_));

		if ((--referenceCount & BSHandleRefObject::kReferenceCountMask) == 0)
		{
			this->Dispose();
		}
	}

	std::uint32_t BSHandleRefObject::GetMaskedReferenceCount()
	{
		this->IncrementReferenceCount();

		return this->referenceCount_ & BSHandleRefObject::kReferenceCountMask;
	}

	void BSHandleRefObject::IncrementReferenceCount()
	{
		std::atomic_ref referenceCount(const_cast<std::uint32_t&>(this->referenceCount_));

		++referenceCount;
	}

	bool BSHandleRefObject::IsHandleValid()
	{
		return this->referenceCount_ & BSHandleRefObject::kValidHandle;
	}
}
