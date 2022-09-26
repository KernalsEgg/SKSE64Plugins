#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace ActorLimitFix::Addresses
{
	namespace MoverLimit
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6D5080 + 0x90 (40296), 1.6.318.0: SkyrimSE.exe + 0x6FDA10</summary>
		inline const std::uintptr_t GetMoverLimit{ Relocation::AddressLibrary::GetSingleton().GetAddress(41306) + 0x92 };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6D5080 + 0x9C (40296), 1.6.318.0: SkyrimSE.exe + 0x6FDA10</summary>
		inline const std::uintptr_t CompareMoverLimit{ Relocation::AddressLibrary::GetSingleton().GetAddress(41306) + 0x9E };
	}

	namespace ReplaceStaticArray
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6E1010 + 0x1BD (40427), 1.6.318.0: SkyrimSE.exe + 0x709CF0</summary>
		inline const std::uintptr_t GetStaticArrayCapacityCommentOnPlayerAction{ Relocation::AddressLibrary::GetSingleton().GetAddress(41442) + 0x1CC };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6E18D0 + 0x31 (40435), 1.6.318.0: SkyrimSE.exe + 0x70A780</summary>
		inline const std::uintptr_t GetStaticArrayCapacityContains{ Relocation::AddressLibrary::GetSingleton().GetAddress(41452) + 0x31 };

		/// <summary>1.6.318.0: SkyrimSE.exe + 0x6FF3B0</summary>
		inline const std::uintptr_t GetStaticArrayCapacityContainsInline{ Relocation::AddressLibrary::GetSingleton().GetAddress(41318) + 0x6E };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6D2C40 + 0x22 (40277), 1.6.318.0: SkyrimSE.exe + 0x6FB160</summary>
		inline const std::uintptr_t GetStaticArrayCapacityCopy{ Relocation::AddressLibrary::GetSingleton().GetAddress(41286) + 0x22 };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6E1740 + 0x70 (40434), 1.6.318.0: SkyrimSE.exe + 0x70A5F0</summary>
		inline const std::uintptr_t GetStaticArrayCapacityInsert{ Relocation::AddressLibrary::GetSingleton().GetAddress(41450) + 0x70 };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6E1010 + 0x1C1 (40427), 1.6.318.0: SkyrimSE.exe + 0x709CF0</summary>
		inline const std::uintptr_t GetStaticArrayCommentOnPlayerAction{ Relocation::AddressLibrary::GetSingleton().GetAddress(41442) + 0x1D0 };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6E18D0 + 0x21 (40435), 1.6.318.0: SkyrimSE.exe + 0x70A780</summary>
		inline const std::uintptr_t GetStaticArrayContains{ Relocation::AddressLibrary::GetSingleton().GetAddress(41452) + 0x21 };

		/// <summary>1.6.318.0: SkyrimSE.exe + 0x6FF3B0</summary>
		inline const std::uintptr_t GetStaticArrayContainsInline{ Relocation::AddressLibrary::GetSingleton().GetAddress(41318) + 0x60 };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6D2C40 + 0x26 (40277), 1.6.318.0: SkyrimSE.exe + 0x6FB160</summary>
		inline const std::uintptr_t GetStaticArrayCopy{ Relocation::AddressLibrary::GetSingleton().GetAddress(41286) + 0x26 };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6E1740 + 0x61 (40434), 1.6.318.0: SkyrimSE.exe + 0x70A5F0</summary>
		inline const std::uintptr_t GetStaticArrayInsert{ Relocation::AddressLibrary::GetSingleton().GetAddress(41450) + 0x61 };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6E1740 + 0x41 (40434), 1.6.318.0: SkyrimSE.exe + 0x70A5F0</summary>
		inline const std::uintptr_t HasCapacityInsert{ Relocation::AddressLibrary::GetSingleton().GetAddress(41450) + 0x41 };
	}
}
