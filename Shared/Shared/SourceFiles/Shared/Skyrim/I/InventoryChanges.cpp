#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/InventoryChanges.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	InventoryEntryData* InventoryChanges::GetInventoryEntryData(TESBoundObject* item) const
	{
		auto* inventoryEntryDataList = this->inventoryEntryDataList;

		if (inventoryEntryDataList)
		{
			for (auto* inventoryEntryData : *inventoryEntryDataList)
			{
				if (!inventoryEntryData)
				{
					break;
				}

				if (inventoryEntryData->item == item)
				{
					return inventoryEntryData;
				}
			}
		}

		return nullptr;
	}

	void InventoryChanges::ResetWeight()
	{
		this->previousInventoryWeight = this->currentInventoryWeight;
		this->currentInventoryWeight  = -1.0F;

		auto* owner = this->owner;

		if (owner && owner->formType == FormType::kActor)
		{
			static_cast<Actor*>(owner)->equippedWeight = -1.0F;
		}
	}
}
