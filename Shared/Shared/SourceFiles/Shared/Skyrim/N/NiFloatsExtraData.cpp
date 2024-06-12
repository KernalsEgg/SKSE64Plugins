#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiFloatsExtraData.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	NiFloatsExtraData* NiFloatsExtraData::CreateObject()
	{
		auto* function{ reinterpret_cast<decltype(NiFloatsExtraData::CreateObject)*>(
			Addresses::NiFloatsExtraData::CreateObject()) };

		return function();
	}
}
