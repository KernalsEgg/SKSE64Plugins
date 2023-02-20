#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class SoulGems
	{
	public:
		static void Patch(bool& black, bool& underfilled);

	private:
		static Skyrim::ForEachResult FunctionCallOperator(Skyrim::InventoryChanges::FindBestSoulGemVisitor* findBestSoulGemVisitor, Skyrim::InventoryEntryData* inventoryEntryData);

		static bool black_;
		static bool underfilled_;
	};
}
