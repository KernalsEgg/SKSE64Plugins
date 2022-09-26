#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Relocation/PreprocessorDirectives.h"



namespace BarterLimitFix::Addresses
{
	namespace Events
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EAA30, 1.6.318.0: SkyrimSE.exe + 0x1F62E0</summary>
		inline const std::uintptr_t GetCount1{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15895, 16135)) + SKYRIM_RELOCATE(0x4F6, 0x5D5) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EAA30, 1.6.318.0: SkyrimSE.exe + 0x1F62E0</summary>
		inline const std::uintptr_t GetCount2{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15895, 16135)) + SKYRIM_RELOCATE(0xA99, 0xB29) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EAA30, 1.6.318.0: SkyrimSE.exe + 0x1F62E0</summary>
		inline const std::uintptr_t GetCount3{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15895, 16135)) + SKYRIM_RELOCATE(0xB76, 0xC06) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EAA30, 1.6.318.0: SkyrimSE.exe + 0x1F62E0</summary>
		inline const std::uintptr_t GetCount4{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15895, 16135)) + SKYRIM_RELOCATE(0xC76, 0xD06) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EAA30, 1.6.318.0: SkyrimSE.exe + 0x1F62E0</summary>
		inline const std::uintptr_t GetCount5{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15895, 16135)) + SKYRIM_RELOCATE(0xE36, 0xE49) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x171790, 1.6.318.0: SkyrimSE.exe + 0x17C270</summary>
		inline const std::uintptr_t HasIterated{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(13661, 13771)) + 0x124 };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EAA30, 1.6.318.0: SkyrimSE.exe + 0x1F62E0</summary>
		inline const std::uintptr_t SetCount1{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15895, 16135)) + SKYRIM_RELOCATE(0x4FF, 0x5DE) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EAA30, 1.6.318.0: SkyrimSE.exe + 0x1F62E0</summary>
		inline const std::uintptr_t SetCount2{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15895, 16135)) + SKYRIM_RELOCATE(0xAA0, 0xB30) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EAA30, 1.6.318.0: SkyrimSE.exe + 0x1F62E0</summary>
		inline const std::uintptr_t SetCount3{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15895, 16135)) + SKYRIM_RELOCATE(0xB7E, 0xC0E) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EAA30, 1.6.318.0: SkyrimSE.exe + 0x1F62E0</summary>
		inline const std::uintptr_t SetCount4{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15895, 16135)) + SKYRIM_RELOCATE(0xC7E, 0xD0E) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EAA30, 1.6.318.0: SkyrimSE.exe + 0x1F62E0</summary>
		inline const std::uintptr_t SetCount5{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15895, 16135)) + SKYRIM_RELOCATE(0xE3D, 0xE50) };
	}
}
