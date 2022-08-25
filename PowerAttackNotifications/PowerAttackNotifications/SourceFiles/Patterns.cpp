#include "PCH.h"

#include "Patterns.h"

#include "Addresses.h"
#include "Shared/Relocation/AddressLibrary.h"



namespace PowerAttackNotifications::Patterns
{
	namespace Events
	{
		bool StartStaminaMeterBlinking()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::StartStaminaMeterBlinking,
				0xE8ui8, std::optional<std::int32_t>{}
			);
		}
	}
}
