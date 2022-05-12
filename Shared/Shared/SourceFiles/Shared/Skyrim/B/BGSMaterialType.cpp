#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSMaterialType.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	BGSMaterialType* BGSMaterialType::GetMaterialTypeFromMaterialID(std::uint32_t materialID)
	{
		auto function{ reinterpret_cast<decltype(&BGSMaterialType::GetMaterialTypeFromMaterialID)>(Addresses::BGSMaterialType::GetMaterialTypeFromMaterialID) };

		return function(materialID);
	}
}
