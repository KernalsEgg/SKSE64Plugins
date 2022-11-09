#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/I/InventoryChanges.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"



namespace ScrambledBugs::Patches
{
	class SoulGems
	{
	public:
		static void Patch(bool& black, bool& underfilled);

	private:
		static Skyrim::InventoryChanges::IItemChangeVisitor::ReturnType Visit(Skyrim::InventoryChanges::FindBestSoulGemVisitor* findBestSoulGemVisitor, Skyrim::InventoryEntryData* inventoryEntryData);

		static bool black_;
		static bool underfilled_;
	};
}
