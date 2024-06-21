#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Relocation/PreprocessorDirectives.h"



namespace LogInventoryItemRotation::Addresses
{
	namespace IMenu
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F4DF28, 1.6.318.0: SkyrimSE.exe + 0x2FE8BF8</summary>
		inline const std::uintptr_t MouseRotation{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(519620, 406167)) }; // IMenu::MouseRotation

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x856EC0, 1.6.318.0: SkyrimSE.exe + 0x883D20</summary>
		inline const std::uintptr_t StopMouseRotation{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(50107, 51038)) }; // IMenu::StopMouseRotation
	}
}
