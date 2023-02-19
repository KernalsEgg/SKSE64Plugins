#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiExtraData.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	NiExtraData* NiExtraData::CreateObject()
	{
		auto* function{ reinterpret_cast<decltype(NiExtraData::CreateObject)*>(Addresses::NiExtraData::CreateObject) };

		return function();
	}
}
