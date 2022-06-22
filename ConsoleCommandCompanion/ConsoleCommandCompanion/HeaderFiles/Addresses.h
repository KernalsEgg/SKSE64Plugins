#pragma once

#include "PCH.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace ConsoleCommandCompanion::Addresses
{
	namespace Patches
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x8A4930</summary>
		inline const std::uintptr_t IsLoggedIn{ Relocation::AddressLibrary::GetSingleton().GetAddress(51276) + 0x29 };
	}
}
