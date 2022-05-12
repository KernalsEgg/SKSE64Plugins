#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiNode.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	std::uint32_t NiNode::ApplyDecal(const BGSDecalManager::ApplicationData& applicationData)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&NiNode::ApplyDecal)>::type>(Addresses::NiNode::ApplyDecal) };

		return function(this, applicationData);
	}
}
