#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESForm.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	EnchantmentItem* TESForm::GetEnchantment(ExtraDataList* extraDataList)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TESForm::GetEnchantment)>::type>(Addresses::TESForm::GetEnchantment) };

		return function(this, extraDataList);
	}

	const char* TESForm::GetFormName() const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TESForm::GetFormName)>::type>(Addresses::TESForm::GetFormName) };

		return function(this);
	}

	std::uint16_t TESForm::GetMaximumCharge(ExtraDataList* extraDataList) const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TESForm::GetMaximumCharge)>::type>(Addresses::TESForm::GetMaximumCharge) };

		return function(this, extraDataList);
	}
}
