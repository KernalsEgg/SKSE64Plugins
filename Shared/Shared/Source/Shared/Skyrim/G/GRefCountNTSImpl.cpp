#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRefCountNTSImpl.h"



namespace Skyrim
{
	void GRefCountNTSImpl::AddReference()
	{
		++this->referenceCount_;
	}

	void GRefCountNTSImpl::Release()
	{
		if (--this->referenceCount_ == 0)
		{
			delete this;
		}
	}
}
