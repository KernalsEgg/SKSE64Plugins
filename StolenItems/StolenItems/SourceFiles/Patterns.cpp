#include "PCH.h"

#include "Patterns.h"

#include "Addresses.h"
#include "Shared/Relocation/AddressLibrary.h"



namespace StolenItems::Patterns
{
	namespace Events
	{
		bool AddItem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::AddItem, // 0x6
				0xFFui8, 0x95ui8, 0x2B0ui32 // call [rbp+2B0] (TESObjectREFR::RemoveItem)
			);
		}

		bool DisenchantItem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::DisenchantItem, // 0x6
				0xFFui8, 0x90ui8, 0x2B0ui32        // call [rax+2B0] (PlayerCharacter::RemoveItem)
			);
		}

		bool DropItem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::DropItem,
				std::make_tuple(                  // 0x6
					0xFFui8, 0x97ui8, 0x658ui32), // call [rdi+658] (PlayerCharacter::DropItem)
				std::make_tuple(                  // 0x6
					0xFFui8, 0x96ui8, 0x658ui32)  // call [rsi+658] (PlayerCharacter::DropItem)
			);
		}

		bool GetExtraDataLists()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetExtraDataLists, // 0x4
				0x48ui8, 0x8Bui8, 0x48ui8, 0x08ui8    // mov rcx, [rax+8]
			);
		}

		bool GetExtraDataListToAddItem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetExtraDataListToAddItem, // 0x5
				0xE8ui8, std::optional<std::int32_t>{}        // call InventoryEntryData::GetExtraDataList
			);
		}

		bool GetExtraDataListToDropItem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetExtraDataListToDropItem, // 0x5
				0xE8ui8, std::optional<std::int32_t>{}         // call InventoryEntryData::GetExtraDataList
			);
		}

		bool GetExtraDataListToRemoveItem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetExtraDataListToRemoveItem, // 0x5
				0xE8ui8, std::optional<std::int32_t>{}           // call InventoryEntryData::GetExtraDataList
			);
		}

		bool GetExtraDataListToRemoveSoul()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetExtraDataListToRemoveSoul, // 0x3
				0x48ui8, 0x8Bui8, 0x09ui8                        // mov rcx, [rcx]
			);
		}

		bool GetExtraDataListToRemoveSoulGem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetExtraDataListToRemoveSoulGem, // 0x3
				0x48ui8, 0x8Bui8, 0x11ui8                           // mov rdx, [rcx]
			);
		}

		bool GetExtraDataListToSellItem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetExtraDataListToSellItem, // 0x5
				0xE8ui8, std::optional<std::int32_t>{}         // call InventoryEntryData::GetExtraDataList
			);
		}

		bool GetIngredientToRemove()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetIngredientToRemove, // 0x3
				0x4Cui8, 0x8Bui8, 0x07ui8                 // mov r8, [rdi]
			);
		}

		bool GetItemToDisenchant()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::GetItemToDisenchant, // 0x3
				0x4Dui8, 0x8Bui8, 0x06ui8               // mov r8, [r14]
			);
		}

		bool IsOwnedBy()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::IsOwnedBy,          // 0x5
				0xE8ui8, std::optional<std::int32_t>{} // call InventoryEntryData::IsOwnedBy
			);
		}

		bool RemoveIngredient()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::RemoveIngredient, // 0x6
				0xFFui8, 0x90ui8, 0x2B0ui32          // call [rax+2B0] (PlayerCharacter::RemoveItem)
			);
		}

		bool RemoveItem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::RemoveItem,
				std::make_tuple(                           // 0x3 + 0x7 = 0x10
					0x49ui8, 0x8Bui8, 0x36ui8,             // mov rsi, [r14] (PlayerCharacter::VirtualFunctionTable)
					0x48ui8, 0x81ui8, 0xC6ui8, 0x2B0ui32), // add rsi, 2B0 (PlayerCharacter::RemoveItem)
				std::make_tuple(                           // 0x6
					0xFFui8, 0x96ui8, 0x2B0ui32)           // call [rsi+2B0] (PlayerCharacter::RemoveItem)
			);
		}

		bool RemoveSoul()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::RemoveSoul,         // 0x5
				0xE8ui8, std::optional<std::int32_t>{} // call ExtraDataList::SetSoul
			);
		}

		bool RemoveSoulGem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::RemoveSoulGem, // 0x6
				0xFFui8, 0x90ui8, 0x2B0ui32       // call [rax+2B0] (PlayerCharacter::RemoveItem)
			);
		}

		bool SellItem()
		{
			return Relocation::AddressLibrary::MatchPattern(
				Addresses::Events::SellItem, // 0x6
				0xFFui8, 0x96ui8, 0x2B0ui32  // call [rsi+2B0] (PlayerCharacter::RemoveItem)
			);
		}
	}
}
