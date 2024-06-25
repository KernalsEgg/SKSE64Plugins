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

				auto* boundObject = containerObject->boundObject;

				if (boundObject && boundObject->formType == Skyrim::FormType::kAmmunition)
				{
					auto* ammunition = static_cast<Skyrim::TESAmmo*>(boundObject);
					auto  bolt       = ammunition->ammunitionFlags.none(Skyrim::TESAmmo::Flags::kArrow);

					if (bolt == crossbow && ammunition->IsPlayable())
					{
						auto* inventoryEntryData = inventoryChanges->GetInventoryEntryData(ammunition);

						if (!inventoryEntryData || containerObject->count + inventoryEntryData->countDelta > 0 || containerObject->count < 0)
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

				auto* boundObject = inventoryEntryData->boundObject;

				if (boundObject && boundObject->formType == Skyrim::FormType::kAmmunition)
				{
					auto* ammunition = static_cast<Skyrim::TESAmmo*>(boundObject);
					auto  bolt       = ammunition->ammunitionFlags.none(Skyrim::TESAmmo::Flags::kArrow);

					if (bolt == crossbow && ammunition->IsPlayable())
					{
						if (inventoryEntryData->IsLeveledBoundObject() && inventoryEntryData->countDelta < 0)
						{
							continue;
						}

						if (!inventoryEntryData->countDelta)
						{
							continue;
						}

						if (container && container->HasBoundObject(ammunition))
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
				bestInventoryEntryData->boundObject = inventoryEntryData->boundObject;

				if (inventoryEntryData->extraDataLists)
				{
					bestInventoryEntryData->AddExtraDataList(inventoryEntryData->extraDataLists->front());
				}

				auto* bestExtraDataLists = bestInventoryEntryData->extraDataLists;

				if (bestExtraDataLists && bestExtraDataLists->front() && !bestExtraDataLists->front()->Stackable(true))
				{
					bestInventoryEntryData->countDelta = inventoryEntryData->countDelta;
				}
				else
				{
					bestInventoryEntryData->countDelta = inventoryEntryData->countDelta;

					if (container)
					{
						bestInventoryEntryData->countDelta += container->GetBoundObjectCount(bestAmmunition);
					}
				}
			}
			else if (bestAmmunition)
			{
				bestInventoryEntryData->boundObject = bestAmmunition;

				if (container)
				{
					bestInventoryEntryData->countDelta = std::abs(container->GetBoundObjectCount(bestAmmunition));
				}
			}
		}

		return bestInventoryEntryData;
	}
}
