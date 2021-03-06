#include "PCH.h"

#include "Fixes/SpeechExperience/EnchantedItems.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"



namespace BugFixesSSE::Fixes::SpeechExperience
{
	void EnchantedItems::Fix(bool& enchantedItems)
	{
		if (!Patterns::Fixes::SpeechExperience::ItemStacks::Buy() ||
			!Patterns::Fixes::SpeechExperience::ItemStacks::Sell())
		{
			enchantedItems = false;

			return;
		}

		Utility::Memory::SafeWriteRelativeCall(Addresses::Fixes::SpeechExperience::ItemStacks::Buy, Skyrim::Addresses::InventoryEntryData::GetValue);
		Utility::Memory::SafeWriteRelativeCall(Addresses::Fixes::SpeechExperience::ItemStacks::Sell, Skyrim::Addresses::InventoryEntryData::GetValue);
	}
}
