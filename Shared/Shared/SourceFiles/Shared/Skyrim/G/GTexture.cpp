#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GTexture.h"



namespace Skyrim
{
	void GTexture::AddReference()
	{
		this->referenceCount_.IncrementNoSynchronize();
	}

	bool GTexture::AddReferenceNotZero()
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

	std::int32_t GTexture::GetReferenceCount()
	{
		return this->referenceCount_.LoadAcquire();
	}

	void GTexture::Release()
	{
		if ((this->referenceCount_.ExchangeAddAcquire(-1) - 1) == 0)
		{
			delete this;
		}
	}
}
