#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxResource.h"

#include "Shared/Skyrim/G/GFxResourceLibBase.h"



namespace Skyrim
{
	GFxResourceKey GFxResource::GetKey()
	{
		return GFxResourceKey();
	}

	std::uint32_t GFxResource::GetResourceTypeCode() const
	{
		return GFxResource::MakeTypeCode(ResourceType::kNone);
	}

	GFxResourceReport* GFxResource::GetResourceReport()
	{
		return nullptr;
	}

	GFxResource::GFxResource() :
		library_(nullptr)
	{
		this->referenceCount_.value = 1;
	}

	std::uint32_t GFxResource::MakeTypeCode(Utility::Enumeration<ResourceType, std::uint32_t> resourceType, Utility::Enumeration<ResourceUse, std::uint32_t> resourceUse)
	{
		return (resourceType.underlying() << Utility::ToUnderlying(ResourceType::kTypeCodeShift)) | resourceUse.underlying();
	}

	// Based on GTexture
	void GFxResource::AddReference()
	{
		this->referenceCount_.IncrementNoSynchronize();
	}

	bool GFxResource::AddReferenceNotZero()
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

	std::int32_t GFxResource::GetReferenceCount() const
	{
		return this->referenceCount_.LoadAcquire();
	}

	void GFxResource::Release()
	{
		if ((this->referenceCount_.ExchangeAddAcquire(-1) - 1) == 0)
		{
			delete this;
		}
	}

	void GFxResource::PinResource()
	{
		if (this->library_)
		{
			this->library_->PinResource(this);
		}
	}

	void GFxResource::UnpinResource()
	{
		if (this->library_)
		{
			this->library_->UnpinResource(this);
		}
	}

	void GFxResource::SetOwnerResourceLibrary(GFxResourceLibBase* library)
	{
		this->library_ = library;
	}

	GFxResource::ResourceType GFxResource::GetResourceType() const
	{
		return static_cast<ResourceType>((this->GetResourceTypeCode() & Utility::ToUnderlying(ResourceType::kTypeCodeMask)) >> Utility::ToUnderlying(ResourceType::kTypeCodeShift));
	}

	GFxResource::ResourceUse GFxResource::GetResourceUse() const
	{
		return static_cast<ResourceUse>(this->GetResourceTypeCode() & Utility::ToUnderlying(ResourceUse::kTypeCodeMask));
	}
}
