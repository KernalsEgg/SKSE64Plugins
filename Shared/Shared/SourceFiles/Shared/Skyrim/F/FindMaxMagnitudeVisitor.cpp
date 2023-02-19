#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FindMaxMagnitudeVisitor.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	ForEachResult FindMaxMagnitudeVisitor::operator()(ActiveEffect* activeEffect)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&FindMaxMagnitudeVisitor::operator())>::type>(Utility::Memory::ReadVirtualFunction(Addresses::FindMaxMagnitudeVisitor::VirtualFunctionTable, 0x1)) };

		return function(this, activeEffect);
	}
}
