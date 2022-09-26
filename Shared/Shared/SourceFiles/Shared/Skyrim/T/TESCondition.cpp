#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESCondition.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool TESCondition::IsTrue(TESObjectREFR* subject, TESObjectREFR* target) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TESCondition::IsTrue)>::type>(Addresses::TESCondition::IsTrue) };

		return function(this, subject, target);
	}
}
