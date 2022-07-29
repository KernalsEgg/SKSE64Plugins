#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSImpactDataSet.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	BGSImpactData* BGSImpactDataSet::GetImpactData(BGSMaterialType* materialType) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&BGSImpactDataSet::GetImpactData)>::type>(Addresses::BGSImpactDataSet::GetImpactData) };

		return function(this, materialType);
	}
}
