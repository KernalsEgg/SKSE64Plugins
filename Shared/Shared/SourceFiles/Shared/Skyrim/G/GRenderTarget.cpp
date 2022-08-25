#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GRenderTarget.h"



namespace Skyrim
{
	GRenderTarget::GRenderTarget()
	{
		this->referenceCount_.value = 1;
	}

	void GRenderTarget::AddReference()
	{
		this->referenceCount_.IncrementNoSynchronize();
	}

	bool GRenderTarget::AddReferenceNotZero()
	{
		while (true)
		{
			std::int32_t referenceCount = this->referenceCount_;

			if (referenceCount == 0)
			{
				return false;
			}

			if (this->referenceCount_.CompareAndSetNoSynchronize(referenceCount, referenceCount + 1))
			{
				break;
			}
		}

		return true;
	}

	void GRenderTarget::Release()
	{
		if ((this->referenceCount_.ExchangeAddAcquire(-1) - 1) == 0)
		{
			delete this;
		}
	}
}
