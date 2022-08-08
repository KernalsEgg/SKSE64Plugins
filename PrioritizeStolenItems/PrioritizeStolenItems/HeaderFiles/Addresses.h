#pragma once

#include "PCH.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace PrioritizeStolenItems::Addresses
{
	namespace Events
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x85EBC0, 1.6.318.0: SkyrimSE.exe + 0x88C560 (ContainerMenu::ItemTransfer)</summary>
		inline const std::uintptr_t AddItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50212, 51141) + Relocation::AddressLibrary::GetOffset(0x2EE, 0x2D5) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x88E280, 1.6.318.0: SkyrimSE.exe + 0x8BDA00 (InventoryMenu::ItemDrop)</summary>
		inline const std::uintptr_t DropItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50978, 51857) + Relocation::AddressLibrary::GetOffset(0xD6, 0xD2) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x85EBC0, 1.6.318.0: SkyrimSE.exe + 0x88C560 (ContainerMenu::ItemTransfer)</summary>
		inline const std::uintptr_t GetExtraDataListToAddItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50212, 51141) + Relocation::AddressLibrary::GetOffset(0x2BA, 0x2A2) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x88E280, 1.6.318.0: SkyrimSE.exe + 0x8BDA00 (InventoryMenu::ItemDrop)</summary>
		inline const std::uintptr_t GetExtraDataListToDropItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50978, 51857) + Relocation::AddressLibrary::GetOffset(0xAD, 0xAF) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x85EBC0, 1.6.318.0: SkyrimSE.exe + 0x88C560 (ContainerMenu::ItemTransfer)</summary>
		inline const std::uintptr_t GetExtraDataListToRemoveItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50212, 51141) + Relocation::AddressLibrary::GetOffset(0x415, 0x515) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x8528D0, 1.6.318.0: SkyrimSE.exe + 0x87F4A0 (BarterMenu::ItemSelect)</summary>
		inline const std::uintptr_t GetExtraDataListToSellItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50007, 50951) + 0x1F9 };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x86B980, 1.6.318.0: SkyrimSE.exe + 0x899C10</summary>
		inline const std::uintptr_t GetIngredient{ Relocation::AddressLibrary::GetSingleton().GetAddress(50449, 51354) + Relocation::AddressLibrary::GetOffset(0x3E8, 0x41D) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1D7510, 1.6.318.0: SkyrimSE.exe + 0x1E2D50</summary>
		inline const std::uintptr_t IsOwnedBy{ Relocation::AddressLibrary::GetSingleton().GetAddress(15781, 16019) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x20AEF0, 1.6.318.0: SkyrimSE.exe + 0x217860</summary>
		inline const std::uintptr_t RemoveComponent{ Relocation::AddressLibrary::GetSingleton().GetAddress(16564, 16919) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x86B980, 1.6.318.0: SkyrimSE.exe + 0x899C10</summary>
		inline const std::uintptr_t RemoveIngredient{ Relocation::AddressLibrary::GetSingleton().GetAddress(50449, 51354) + Relocation::AddressLibrary::GetOffset(0x3EF, 0x424) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x85EBC0, 1.6.318.0: SkyrimSE.exe + 0x88C560 (ContainerMenu::ItemTransfer)</summary>
		inline const std::uintptr_t RemoveItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50212, 51141) + Relocation::AddressLibrary::GetOffset(0x3FE, 0x547) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x8528D0, 1.6.318.0: SkyrimSE.exe + 0x87F4A0 (BarterMenu::ItemSelect)</summary>
		inline const std::uintptr_t SellItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(50007, 50951) + 0x232 };
	}
}
