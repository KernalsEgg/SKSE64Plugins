#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class EquipBestAmmunition
	{
	public:
		static void Patch(bool& equipBestAmmunition);

	private:
		static Skyrim::InventoryEntryData* GetBestAmmunition(Skyrim::InventoryChanges* inventoryChanges, bool crossbow);
	};
}
