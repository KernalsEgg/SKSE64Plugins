#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/E/Effect.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	std::uint32_t Effect::GetArea() const
	{
		return this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoArea) ? 0 : this->area;
	}

	std::uint32_t Effect::GetDuration() const
	{
		return this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoDuration) ? 0 : this->duration;
	}

	float Effect::GetMagnitude() const
	{
		return this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoMagnitude) ? 0.0F : this->magnitude;
	}

	bool Effect::IsHostile() const
	{
		return this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kHostile);
	}

	bool Effect::SetDuration(std::uint32_t duration)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Effect::SetDuration)>::type>(Addresses::Effect::SetDuration) };

		return function(this, duration);
	}

	bool Effect::SetMagnitude(float magnitude)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Effect::SetMagnitude)>::type>(Addresses::Effect::SetMagnitude) };

		return function(this, magnitude);
	}
}
