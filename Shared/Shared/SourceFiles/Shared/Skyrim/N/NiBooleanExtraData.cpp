#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiBooleanExtraData.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	NiBooleanExtraData* NiBooleanExtraData::CreateObject()
	{
		auto* function{ reinterpret_cast<decltype(&NiBooleanExtraData::CreateObject)>(Addresses::NiBooleanExtraData::CreateObject) };

		return function();
	}
}
