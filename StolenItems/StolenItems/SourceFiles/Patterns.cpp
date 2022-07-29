#include "PCH.h"

#include "Patterns.h"

#include "Addresses.h"
#include "Shared/Relocation/AddressLibrary.h"



namespace StolenItems::Patterns
{
	namespace Events
	{
		namespace Add
		{
			bool GetExtraDataList()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Events::Add::GetExtraDataList, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}    // call InventoryEntryData::GetExtraDataList
				);
			}

			bool RemoveItem()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Events::Add::RemoveItem, // 0x6
					0xFFui8, 0x95ui8, 0x2B0ui32         // call [rbp+2B0]
				);
			}
		}

		namespace Drop
		{
			bool GetExtraDataList()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Events::Drop::GetExtraDataList, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}     // call InventoryEntryData::GetExtraDataList
				);
			}

			bool DropItem()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Events::Drop::DropItem, // 0x6
					0xFFui8, 0x97ui8, 0x658ui32        // call [rdi+658]
				);
			}
		}

		namespace Remove
		{
			bool GetExtraDataList()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Events::Remove::GetExtraDataList, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}       // call InventoryEntryData::GetExtraDataList
				);
			}

			bool RemoveItem()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Events::Remove::RemoveItem, // 0x3 + 0x7 = 0x10
					0x49ui8, 0x8Bui8, 0x36ui8,             // mov rsi, [r14]
					0x48ui8, 0x81ui8, 0xC6ui8, 0x2B0ui32   // add rsi, 2B0
				);
			}
		}

		namespace RequestItemCardInformation
		{
			bool IsOwnedBy()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Events::RequestItemCardInformation::IsOwnedBy, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}                    // call InventoryEntryData::IsOwnedBy
				);
			}
		}

		namespace Sell
		{
			bool GetExtraDataList()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Events::Sell::GetExtraDataList, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}     // call InventoryEntryData::GetExtraDataList
				);
			}

			bool RemoveItem()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Events::Sell::RemoveItem, // 0x6
					0xFFui8, 0x96ui8, 0x2B0ui32          // call [rsi+2B0]
				);
			}
		}
	}
}
