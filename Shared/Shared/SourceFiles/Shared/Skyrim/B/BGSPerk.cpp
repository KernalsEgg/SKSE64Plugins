#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSPerk.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void BGSPerk::ApplyPerk(Actor* perkOwner, std::uint8_t removeRank, std::uint8_t applyRank) const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&BGSPerk::ApplyPerk)>::type>(Addresses::BGSPerk::ApplyPerk) };

		function(this, perkOwner, removeRank, applyRank);
	}
}
