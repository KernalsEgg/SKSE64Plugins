#include "PCH.h"

#include "Fixes/SpeechExperience/EnchantedItems.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"



namespace BugFixesSSE::Fixes::SpeechExperience
{
	bool EnchantedItems::Fix()
	{
		if (!Patterns::Fixes::SpeechExperience::ItemStacks::Buy() ||
			!Patterns::Fixes::SpeechExperience::ItemStacks::Sell())
		{
			return false;
		}

		Utility::Memory::SafeWriteRelativeCall(Addresses::Fixes::SpeechExperience::ItemStacks::Buy, Skyrim::Addresses::InventoryEntryData::GetValue);
		Utility::Memory::SafeWriteRelativeCall(Addresses::Fixes::SpeechExperience::ItemStacks::Sell, Skyrim::Addresses::InventoryEntryData::GetValue);

		return true;
	}
}
