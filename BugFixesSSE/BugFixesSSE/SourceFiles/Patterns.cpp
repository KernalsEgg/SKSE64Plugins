#include "PCH.h"

#include "Patterns.h"

#include "Addresses.h"
#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Utility/Convert.h"



namespace BugFixesSSE::Patterns
{
	namespace Fixes
	{
		namespace SpeechExperience
		{
			namespace ItemStacks
			{
				bool Buy()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Fixes::SpeechExperience::ItemStacks::Buy, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}               // call InventoryEntryData::GetBaseValue
					);
				}

				bool GetItemCount()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Fixes::SpeechExperience::ItemStacks::GetItemCount, // 0x5
						0x4Cui8, 0x89ui8, 0xB4ui8, 0x24ui8, 0xD0ui32                  // mov [rsp+D0], r14
					);
				}

				bool Sell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Fixes::SpeechExperience::ItemStacks::Sell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                // call InventoryEntryData::GetBaseValue
					);
				}
			}
		}

		namespace SpeedMultUpdates
		{
			bool SpeedMultSink()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::SpeedMultUpdates::ActorValueSinks + (sizeof(std::uintptr_t) * Utility::ToUnderlying(Skyrim::ActorValue::kSpeedMult)), // 0x8
					nullptr                                                                                                                                 // nullptr
				);
			}
		}
	}
}
