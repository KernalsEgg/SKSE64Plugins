#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxResourceID.h"



namespace Skyrim
{
	UPInt GFxResourceID::HashOperation::operator()(const GFxResourceID& idReference)
	{
		return (idReference.id_ ^ (idReference.id_ >> (16 - 8)));
	}

	GFxResourceID::GFxResourceID() :
		id_(Utility::Conversion::ToUnderlying(IDTypeConstants::kInvalidID))
	{
	}

	GFxResourceID::GFxResourceID(const GFxResourceID& right) :
		id_(right.id_)
	{
	}

	GFxResourceID::GFxResourceID(std::uint32_t resourceID) :
		id_(resourceID)
	{
	}

	GFxResourceID GFxResourceID::operator=(const GFxResourceID& right)
	{
		this->id_ = right.id_;

		return *this;
	}

	bool GFxResourceID::operator==(const GFxResourceID& right) const
	{
		return this->id_ == right.id_;
	}

	bool GFxResourceID::operator!=(const GFxResourceID& right) const
	{
		return !this->operator==(right);
	}

	bool GFxResourceID::operator==(std::uint32_t idValue) const
	{
		return this->id_ == idValue;
	}

	bool GFxResourceID::operator!=(std::uint32_t idValue) const
	{
		return !this->operator==(idValue);
	}

	GFxResourceID GFxResourceID::GenerateNextID()
	{
		GFxResourceID result = *this;

		++this->id_;

		return result;
	}

	std::uint32_t GFxResourceID::GetIDIndex() const
	{
		return this->id_ & Utility::Conversion::ToUnderlying(IDTypeConstants::kIndexMask);
	}

	GFxResourceID::IDType GFxResourceID::GetIDType() const
	{
		return static_cast<IDType>(this->id_ & Utility::Conversion::ToUnderlying(IDTypeConstants::kTypeMask));
	}

	std::uint32_t GFxResourceID::GetIDValue() const
	{
		return this->id_;
	}
}
