#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/E/EffectSetting.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	float EffectSetting::GetCost(float baseCost, std::int32_t area, std::int32_t duration, float magnitude, bool aimed, bool concentration)
	{
		auto* function{ reinterpret_cast<decltype(EffectSetting::GetCost)*>(Addresses::EffectSetting::GetCost) };

		return function(baseCost, area, duration, magnitude, aimed, concentration);
	}
}
