#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESSoulGem.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	std::int32_t TESSoulGem::GetSoulLevelValue(Utility::Enumeration<SoulLevel, std::uint32_t> soulLevel)
	{
		auto* function{ reinterpret_cast<decltype(TESSoulGem::GetSoulLevelValue)*>(Addresses::TESSoulGem::GetSoulLevelValue) };

		return function(soulLevel);
	}
}
