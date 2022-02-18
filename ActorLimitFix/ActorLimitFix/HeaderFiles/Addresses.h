#pragma once

#include "PCH.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace ActorLimitFix::Addresses
{
	namespace MoverLimit
	{
		inline const std::uintptr_t GetMoverLimit{ Relocation::AddressLibrary::GetSingleton().GetAddress(40296) + 0x90 };     // SkyrimSE.exe + 0x6D5080
		inline const std::uintptr_t CompareMoverLimit{ Relocation::AddressLibrary::GetSingleton().GetAddress(40296) + 0x9C }; // SkyrimSE.exe + 0x6D5080
	}

	namespace ReplaceStaticArray
	{
		inline const std::uintptr_t GetStaticArrayCapacityCommentOnPlayerAction{ Relocation::AddressLibrary::GetSingleton().GetAddress(40427) + 0x1BD }; // SkyrimSE.exe + 0x6E1010
		inline const std::uintptr_t GetStaticArrayCapacityContains{ Relocation::AddressLibrary::GetSingleton().GetAddress(40435) + 0x31 };               // SkyrimSE.exe + 0x6E18D0
		inline const std::uintptr_t GetStaticArrayCapacityCopy{ Relocation::AddressLibrary::GetSingleton().GetAddress(40277) + 0x22 };                   // SkyrimSE.exe + 0x6D2C40
		inline const std::uintptr_t GetStaticArrayCapacityErase{ Relocation::AddressLibrary::GetSingleton().GetAddress(6293) + 0x0 };                    // SkyrimSE.exe + 0x9EF30
		inline const std::uintptr_t GetStaticArrayCapacityInsert{ Relocation::AddressLibrary::GetSingleton().GetAddress(40434) + 0x70 };                 // SkyrimSE.exe + 0x6E1740
		inline const std::uintptr_t GetStaticArrayCommentOnPlayerAction{ Relocation::AddressLibrary::GetSingleton().GetAddress(40427) + 0x1C1 };         // SkyrimSE.exe + 0x6E1010
		inline const std::uintptr_t GetStaticArrayContains{ Relocation::AddressLibrary::GetSingleton().GetAddress(40435) + 0x21 };                       // SkyrimSE.exe + 0x6E18D0
		inline const std::uintptr_t GetStaticArrayCopy{ Relocation::AddressLibrary::GetSingleton().GetAddress(40277) + 0x26 };                           // SkyrimSE.exe + 0x6D2C40
		inline const std::uintptr_t GetStaticArrayErase{ Relocation::AddressLibrary::GetSingleton().GetAddress(6293) + 0x5 };                            // SkyrimSE.exe + 0x9EF30
		inline const std::uintptr_t GetStaticArrayInsert{ Relocation::AddressLibrary::GetSingleton().GetAddress(40434) + 0x61 };                         // SkyrimSE.exe + 0x6E1740
		inline const std::uintptr_t HasCapacityInsert{ Relocation::AddressLibrary::GetSingleton().GetAddress(40434) + 0x41 };                            // SkyrimSE.exe + 0x6E1740
	}
}
