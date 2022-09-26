#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiNode.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	std::uint32_t NiNode::AddDecal(const BGSDecalManager::AdditionData& applicationData)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&NiNode::AddDecal)>::type>(Addresses::NiNode::AddDecal) };

		return function(this, applicationData);
	}
}
