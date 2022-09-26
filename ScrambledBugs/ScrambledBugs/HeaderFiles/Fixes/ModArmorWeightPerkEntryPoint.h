#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/B/BGSEntryPointPerkEntry.h"
#include "Shared/Skyrim/I/InventoryChanges.h"



namespace ScrambledBugs::Fixes
{
	class ModArmorWeightPerkEntryPoint
	{
	public:
		static void Fix(bool& modArmorWeightPerkEntryPoint);

	private:
		static void  ApplyPerkEntry(Skyrim::BGSEntryPointPerkEntry* entryPointPerkEntry, Skyrim::Actor* perkOwner);
		static float GetInventoryWeight(Skyrim::InventoryChanges* inventoryChanges);
		static void  RemovePerkEntry(Skyrim::BGSEntryPointPerkEntry* entryPointPerkEntry, Skyrim::Actor* perkOwner);

		static decltype(&ModArmorWeightPerkEntryPoint::ApplyPerkEntry)  applyPerkEntry_;
		static decltype(&ModArmorWeightPerkEntryPoint::RemovePerkEntry) removePerkEntry_;
	};
}
