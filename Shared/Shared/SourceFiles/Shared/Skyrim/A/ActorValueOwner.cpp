#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValueOwner.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	float ActorValueOwner::GetDualCastingEffectiveness(float cost) const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&ActorValueOwner::GetDualCastingEffectiveness)>::type>(Addresses::ActorValueOwner::GetDualCastingEffectiveness) };

		return function(this, cost);
	}
}
