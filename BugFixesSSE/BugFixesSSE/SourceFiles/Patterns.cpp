#include "PrecompiledHeader.h"

#include "Patterns.h"

#include "Addresses.h"
#include "Shared/Relocation/AddressLibrary.h"



namespace BugFixesSSE::Patterns
{
	namespace Fixes
	{
		namespace MovementSpeed
		{
			bool CompareMovementType()
			{
				return Relocation::AddressLibrary::MatchPattern()(
					Addresses::Fixes::MovementSpeed::CompareMovementType, // 5 + 5 = 0xA
					0x48ui8, 0x8Bui8, 0x44ui8, 0x24ui8, 0x30ui8,          // mov rax, [rsp+30]
					0x48ui8, 0x39ui8, 0x44ui8, 0x24ui8, 0x70ui8           // cmp [rsp+70], rax
				);
			}
		}

		namespace SpeechExperience
		{
			namespace ItemStacks
			{
				bool Buy()
				{
					return Relocation::AddressLibrary::MatchPattern()(
						Addresses::Fixes::SpeechExperience::ItemStacks::Buy, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}               // call InventoryEntryData::GetBaseValue
					);
				}

				bool GetItemCount()
				{
					return Relocation::AddressLibrary::MatchPattern()(
						Addresses::Fixes::SpeechExperience::ItemStacks::GetItemCount, // 0x5
						0x4Cui8, 0x89ui8, 0xB4ui8, 0x24ui8, 0xD0ui32                  // mov [rsp+D0], r14
					);
				}

				bool Sell()
				{
					return Relocation::AddressLibrary::MatchPattern()(
						Addresses::Fixes::SpeechExperience::ItemStacks::Sell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                // call InventoryEntryData::GetBaseValue
					);
				}
			}
		}
	}
}
