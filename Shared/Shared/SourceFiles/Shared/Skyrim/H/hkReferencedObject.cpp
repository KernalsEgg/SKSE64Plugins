#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkReferencedObject.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void hkReferencedObject::AddReference() const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&hkReferencedObject::AddReference)>::type>(Addresses::hkReferencedObject::AddReference) };

		function(this);
	}

	std::uint16_t hkReferencedObject::GetSize() const
	{
		return this->memorySizeAndFlags & hkReferencedObject::kMemorySizeMask;
	}

	std::int16_t hkReferencedObject::GetReferenceCount() const
	{
		return this->referenceCount;
	}

	void hkReferencedObject::RemoveReference() const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&hkReferencedObject::RemoveReference)>::type>(Addresses::hkReferencedObject::RemoveReference) };

		function(this);
	}
}
