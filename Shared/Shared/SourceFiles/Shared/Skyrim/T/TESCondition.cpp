#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESCondition.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	TESCondition::~TESCondition()
	{
		this->Clear();
	}

	void TESCondition::Clear()
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&TESCondition::Clear)>::type>(Addresses::TESCondition::Clear) };

		function(this);
	}

	bool TESCondition::IsTrue(TESObjectREFR* subject, TESObjectREFR* target) const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&TESCondition::IsTrue)>::type>(Addresses::TESCondition::IsTrue) };

		return function(this, subject, target);
	}
}
