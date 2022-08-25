#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GRefCountImpl.h"



namespace Skyrim
{
	void GRefCountImpl::AddReference()
	{
		std::atomic_ref referenceCount(const_cast<std::int32_t&>(this->referenceCount_));

		++referenceCount;
	}

	void GRefCountImpl::Release()
	{
		std::atomic_ref referenceCount(const_cast<std::int32_t&>(this->referenceCount_));

		if (--referenceCount == 0)
		{
			delete this;
		}
	}
}
