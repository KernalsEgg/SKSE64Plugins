#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FindAppropriateDisplaceEffect.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	ForEachResult FindAppropriateDisplaceEffect::operator()(ActiveEffect* activeEffect)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&FindAppropriateDisplaceEffect::operator())>::type>(
			Utility::Memory::ReadVirtualFunction(
				Addresses::FindAppropriateDisplaceEffect::VirtualFunctionTable(),
				0x1)) };

		return function(this, activeEffect);
	}
}
