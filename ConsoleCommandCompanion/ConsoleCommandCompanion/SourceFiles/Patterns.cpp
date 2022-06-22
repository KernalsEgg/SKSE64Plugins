#include "PCH.h"

#include "Patterns.h"

#include "Addresses.h"
#include "Shared/Relocation/AddressLibrary.h"



namespace ConsoleCommandCompanion::Patterns
{
	namespace Patches
	{
		bool IsLoggedIn()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Patches::IsLoggedIn, // 0x2
				0x74ui8, 0x09ui8                // je 9
			);
		}
	}
}
