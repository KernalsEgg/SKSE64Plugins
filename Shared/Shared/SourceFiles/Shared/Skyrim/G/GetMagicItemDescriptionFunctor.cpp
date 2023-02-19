#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GetMagicItemDescriptionFunctor.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	ForEachResult GetMagicItemDescriptionFunctor::operator()(EffectItem* effect)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&GetMagicItemDescriptionFunctor::operator())>::type>(Utility::Memory::ReadVirtualFunction(Addresses::GetMagicItemDescriptionFunctor::VirtualFunctionTable, 0x1)) };

		return function(this, effect);
	}
}
