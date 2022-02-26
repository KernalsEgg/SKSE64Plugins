#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/B/BGSEntryPointPerkEntry.h"
#include "Shared/Skyrim/I/InventoryChanges.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"
#include "Shared/Skyrim/T/TESBoundObject.h"



namespace ScrambledBugs::Fixes
{
	class ModArmorWeightPerkEntryPoint
	{
	public:
		static bool Fix();

	private:
		static void                        ApplyPerkEntry(Skyrim::BGSEntryPointPerkEntry* entryPointPerkEntry, Skyrim::Actor* perkOwner);
		static Skyrim::InventoryEntryData* GetInventoryEntryData(Skyrim::InventoryChanges* inventoryChanges, Skyrim::TESBoundObject* item);
		static float                       GetInventoryWeight(Skyrim::InventoryChanges* inventoryChanges);
		static void                        RemovePerkEntry(Skyrim::BGSEntryPointPerkEntry* entryPointPerkEntry, Skyrim::Actor* perkOwner);

		static decltype(&ModArmorWeightPerkEntryPoint::ApplyPerkEntry)  applyPerkEntry_;
		static decltype(&ModArmorWeightPerkEntryPoint::RemovePerkEntry) removePerkEntry_;
	};
}
