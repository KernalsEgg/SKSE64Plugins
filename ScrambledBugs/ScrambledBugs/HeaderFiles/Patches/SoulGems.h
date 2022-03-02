#pragma once

#include "PCH.h"

#include "Shared/Skyrim/I/InventoryChanges.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"



namespace ScrambledBugs::Patches
{
	class SoulGems
	{
	public:
		static void Patch(bool& blackSoulGems, bool& underfilledSoulGems);

	private:
		static Skyrim::InventoryChanges::IItemChangeVisitor::ReturnType Visit(Skyrim::InventoryChanges::FindBestSoulGemVisitor* findBestSoulGemVisitor, Skyrim::InventoryEntryData* inventoryEntryData);

		static bool blackSoulGems_;
		static bool underfilledSoulGems_;
	};
}
