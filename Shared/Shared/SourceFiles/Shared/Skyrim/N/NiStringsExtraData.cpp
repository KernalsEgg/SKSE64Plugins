#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiStringsExtraData.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	NiStringsExtraData* NiStringsExtraData::CreateObject()
	{
		auto* function{ reinterpret_cast<decltype(&NiStringsExtraData::CreateObject)>(Addresses::NiStringsExtraData::CreateObject) };

		return function();
	}
}
