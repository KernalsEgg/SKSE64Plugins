#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiFloatExtraData.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	NiFloatExtraData* NiFloatExtraData::CreateObject()
	{
		auto* function{ reinterpret_cast<decltype(NiFloatExtraData::CreateObject)*>(Addresses::NiFloatExtraData::CreateObject) };

		return function();
	}
}
