#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiStringExtraData.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	NiStringExtraData* NiStringExtraData::CreateObject()
	{
		auto* function{ reinterpret_cast<decltype(NiStringExtraData::CreateObject)*>(Addresses::NiStringExtraData::CreateObject) };

		return function();
	}
}
