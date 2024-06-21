#include "PrecompiledHeader.h"

#include "Patches/EquipBestAmmunition.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void EquipBestAmmunition::Patch(bool& equipBestAmmunition)
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Addresses::Patches::EquipBestAmmunition::GetWorstAmmunition,
			reinterpret_cast<std::uintptr_t>(std::addressof(EquipBestAmmunition::GetBestAmmunition)));
	}

	Skyrim::InventoryEntryData* EquipBestAmmunition::GetBestAmmunition(Skyrim::InventoryChanges* inventoryChanges, bool crossbow)
	{
		Skyrim::TESAmmo* bestAmmunition{ nullptr };

		auto* owner     = inventoryChanges->owner;
		auto* container = owner ? owner->GetContainer() : nullptr;

		if (container)
		{
			for (auto* containerObject : *container)
			{
				if (!containerObject)
				{
					continue;
				}

				auto* boundObject = containerObject->object;

				if (boundObject && boundObject->formType == Skyrim::FormType::kAmmunition)
				{
					auto* ammunition = static_cast<Skyrim::TESAmmo*>(boundObject);
					auto  bolt       = ammunition->ammunitionFlags.none(Skyrim::TESAmmo::Flags::kArrow);

					if (bolt == crossbow && ammunition->IsPlayable())
					{
						auto* inventoryEntryData = inventoryChanges->GetInventoryEntryData(ammunition);

						if (!inventoryEntryData || containerObject->count + inventoryEntryData->itemCountDelta > 0 || containerObject->count < 0)
						{
							if (!bestAmmunition || ammunition->damage > bestAmmunition->damage)
							{
								bestAmmunition = ammunition;
							}
						}
					}
				}
			}
		}

		auto* inventoryEntryDataList = inventoryChanges->inventoryEntryDataList;

		if (inventoryEntryDataList)
		{
			for (auto* inventoryEntryData : *inventoryEntryDataList)
			{
				if (!inventoryEntryData)
				{
					continue;
				}

				auto* boundObject = inventoryEntryData->item;

				if (boundObject && boundObject->formType == Skyrim::FormType::kAmmunition)
				{
					auto* ammunition = static_cast<Skyrim::TESAmmo*>(boundObject);
					auto  bolt       = ammunition->ammunitionFlags.none(Skyrim::TESAmmo::Flags::kArrow);

					if (bolt == crossbow && ammunition->IsPlayable())
					{
						if (inventoryEntryData->IsLeveledItem() && inventoryEntryData->itemCountDelta < 0)
						{
							continue;
						}

						if (!inventoryEntryData->itemCountDelta)
						{
							continue;
						}

						if (container && container->HasItem(ammunition))
						{
							continue;
						}

						if (!bestAmmunition || ammunition->damage > bestAmmunition->damage)
						{
							bestAmmunition = ammunition;
						}
					}
				}
			}
		}

		auto* inventoryEntryData     = inventoryChanges->GetInventoryEntryData(bestAmmunition);
		auto* bestInventoryEntryData = bestAmmunition ? new Skyrim::InventoryEntryData() : nullptr;

		if (bestInventoryEntryData)
		{
			if (inventoryEntryData)
			{
				bestInventoryEntryData->item = inventoryEntryData->item;

				if (inventoryEntryData->extraDataLists)
				{
					bestInventoryEntryData->AddExtraDataList(inventoryEntryData->extraDataLists->front());
				}

				auto* bestExtraDataLists = bestInventoryEntryData->extraDataLists;

				if (bestExtraDataLists && bestExtraDataLists->front() && !bestExtraDataLists->front()->Stackable(true))
				{
					bestInventoryEntryData->itemCountDelta = inventoryEntryData->itemCountDelta;
				}
				else
				{
					bestInventoryEntryData->itemCountDelta = inventoryEntryData->itemCountDelta;

					if (container)
					{
						bestInventoryEntryData->itemCountDelta += container->GetItemCount(bestAmmunition);
					}
				}
			}
			else if (bestAmmunition)
			{
				bestInventoryEntryData->item = bestAmmunition;

				if (container)
				{
					bestInventoryEntryData->itemCountDelta = std::abs(container->GetItemCount(bestAmmunition));
				}
			}
		}

		return bestInventoryEntryData;
	}
}
