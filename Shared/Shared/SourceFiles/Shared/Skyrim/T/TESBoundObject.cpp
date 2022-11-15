#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESBoundObject.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	float TESBoundObject::GetWeight() const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&TESBoundObject::GetWeight)>::type>(Addresses::TESBoundObject::GetWeight) };

		return function(this);
	}
}
