#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiIntegersExtraData.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	NiIntegersExtraData* NiIntegersExtraData::CreateObject()
	{
		auto* function{ reinterpret_cast<decltype(&NiIntegersExtraData::CreateObject)>(Addresses::NiIntegersExtraData::CreateObject) };

		return function();
	}
}
