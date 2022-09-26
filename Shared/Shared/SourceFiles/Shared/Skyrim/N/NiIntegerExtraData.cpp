#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiIntegerExtraData.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	NiIntegerExtraData* NiIntegerExtraData::CreateObject()
	{
		auto* function{ reinterpret_cast<decltype(&NiIntegerExtraData::CreateObject)>(Addresses::NiIntegerExtraData::CreateObject) };

		return function();
	}
}
