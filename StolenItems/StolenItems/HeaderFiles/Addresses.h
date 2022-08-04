#pragma once

#include "PCH.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace StolenItems::Addresses
{
	namespace Events
	{
		namespace Add
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x85EBC0</summary>
			inline const std::uintptr_t GetExtraDataList{ Relocation::AddressLibrary::GetSingleton().GetAddress(50212) + 0x2BA }; // ContainerMenu::ItemTransfer

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x85EBC0</summary>
			inline const std::uintptr_t RemoveItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50212) + 0x2EE }; // ContainerMenu::ItemTransfer
		}

		namespace Craft
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x20AEF0</summary>
			inline const std::uintptr_t RemoveRequiredItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(16564) };
		}

		namespace Drop
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x88E280</summary>
			inline const std::uintptr_t GetExtraDataList{ Relocation::AddressLibrary::GetSingleton().GetAddress(50978) + 0xAD }; // InventoryMenu::ItemDrop

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x88E280</summary>
			inline const std::uintptr_t DropItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50978) + 0xD6 }; // InventoryMenu::ItemDrop
		}

		namespace Remove
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x85EBC0</summary>
			inline const std::uintptr_t GetExtraDataList{ Relocation::AddressLibrary::GetSingleton().GetAddress(50212) + 0x415 }; // ContainerMenu::ItemTransfer

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x85EBC0</summary>
			inline const std::uintptr_t RemoveItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50212) + 0x3FE }; // ContainerMenu::ItemTransfer
		}

		namespace RequestItemCardInformation
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x890E70</summary>
			inline const std::uintptr_t IsOwnedBy{ Relocation::AddressLibrary::GetSingleton().GetAddress(51019) + 0x26B };
		}

		namespace Sell
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x8528D0</summary>
			inline const std::uintptr_t GetExtraDataList{ Relocation::AddressLibrary::GetSingleton().GetAddress(50007) + 0x1F9 }; // BarterMenu::ItemSelect

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x8528D0</summary>
			inline const std::uintptr_t RemoveItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50007) + 0x232 }; // BarterMenu::ItemSelect
		}
	}
}
