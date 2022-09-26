#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpGroupFilter.h"



namespace Skyrim
{
	std::int32_t hkpGroupFilter::GetLayerFromFilterInformation(std::uint32_t filterInformation)
	{
		return filterInformation & 0x1F;
	}

	std::int32_t hkpGroupFilter::GetSubSystemDontCollideWithFromFilterInformation(std::uint32_t filterInformation)
	{
		return (filterInformation >> 10) & 0x1F;
	}

	std::int32_t hkpGroupFilter::GetSubSystemIDFromFilterInformation(std::uint32_t filterInformation)
	{
		return (filterInformation >> 5) & 0x1F;
	}

	std::int32_t hkpGroupFilter::GetSystemGroupFromFilterInformation(std::uint32_t filterInformation)
	{
		return filterInformation >> 16;
	}
}
