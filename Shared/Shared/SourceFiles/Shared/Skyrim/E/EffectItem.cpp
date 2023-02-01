#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/E/EffectItem.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	EffectItem::EffectItem(const EffectItem& right)
	{
		this->Copy(std::addressof(right));
	}

	EffectItem& EffectItem::operator=(const EffectItem& right)
	{
		if (this != std::addressof(right))
		{
			this->Copy(std::addressof(right));
		}

		return *this;
	}

	void EffectItem::Copy(const EffectItem* right)
	{
		this->effectSetting = right->effectSetting;

		this->ResetCost();

		this->SetArea(right->GetArea());
		this->SetDuration(right->GetDuration());
		this->SetMagnitude(right->GetMagnitude());

		this->SetConditions(std::addressof(right->conditions));
	}

	std::int32_t EffectItem::GetArea() const
	{
		return this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoArea) ? 0 : this->area;
	}

	float EffectItem::GetCost(Actor* caster) const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&EffectItem::GetCost)>::type>(Addresses::EffectItem::GetCost) };

		return function(this, caster);
	}

	std::int32_t EffectItem::GetDuration() const
	{
		return this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoDuration) ? 0 : this->duration;
	}

	float EffectItem::GetMagnitude() const
	{
		return this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoMagnitude) ? 0.0F : this->magnitude;
	}

	bool EffectItem::IsHostile() const
	{
		return this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kHostile);
	}

	void EffectItem::ResetCost()
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&EffectItem::ResetCost)>::type>(Addresses::EffectItem::ResetCost) };

		function(this);
	}

	bool EffectItem::SetArea(std::int32_t area)
	{
		if (this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoArea) || area < 0)
		{
			return false;
		}

		this->area = area;

		this->ResetCost();

		return true;
	}

	void EffectItem::SetConditions(const TESCondition* conditions)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&EffectItem::SetConditions)>::type>(Addresses::EffectItem::SetConditions) };

		function(this, conditions);
	}

	bool EffectItem::SetDuration(std::int32_t duration)
	{
		if (this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoDuration) || duration < 0)
		{
			return false;
		}

		this->duration = duration;

		this->ResetCost();

		return true;
	}

	bool EffectItem::SetMagnitude(float magnitude)
	{
		if (this->effectSetting->effectSettingFlags.all(EffectSetting::Flags::kNoMagnitude) || magnitude < 0.0F)
		{
			return false;
		}

		this->magnitude = magnitude;

		this->ResetCost();

		return true;
	}
}
