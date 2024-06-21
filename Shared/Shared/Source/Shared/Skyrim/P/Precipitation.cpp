#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/P/Precipitation.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	const NiPoint3& Precipitation::GetRainDirection()
	{
		auto* singleton{ reinterpret_cast<NiPoint3*>(Addresses::Precipitation::RainDirection()) };

		return *singleton;
	}

	bool Precipitation::HasActiveGeometry() const
	{
		return this->currentPrecipitation || this->previousPrecipitation;
	}
}
