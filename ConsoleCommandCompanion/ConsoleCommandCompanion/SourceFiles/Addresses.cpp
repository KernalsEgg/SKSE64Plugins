#include "PrecompiledHeader.h"

#include "Addresses.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace ConsoleCommandCompanion::Addresses
{
	namespace Patches
	{
		std::uintptr_t IsLoggedIn()
		{
			static std::uintptr_t address{ Relocation::AddressLibrary::GetSingleton().GetAddress(51276) + 0x29 };

			return address;
		}
	}
}
