#include "Shared/PCH.h"

#include "Shared/Skyrim/A/ActorProcess.h"

#include "Shared/Skyrim/I/InventoryEntryData.h"
#include "Shared/Skyrim/M/MiddleHighProcessData.h"
#include "Shared/Skyrim/T/TESBoundObject.h"



namespace Skyrim
{
	bhkCharacterController* ActorProcess::GetCharacterController() const
	{
		auto middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->characterController.get() : nullptr;
	}

	ObjectReferenceHandle ActorProcess::GetCurrentFurniture() const
	{
		auto middleHighProcessData = this->middleHighProcessData;

		if (middleHighProcessData)
		{
			return middleHighProcessData->currentFurniture;
		}
		else
		{
			return {};
		}
	}

	InventoryEntryData* ActorProcess::GetEquippedWeapon(bool leftHand) const
	{
		auto middleHighProcessData = this->middleHighProcessData;

		if (!middleHighProcessData)
		{
			return nullptr;
		}

		auto inventoryEntryData = leftHand ? middleHighProcessData->leftHand : middleHighProcessData->rightHand;

		if (!inventoryEntryData)
		{
			return nullptr;
		}

		auto item = inventoryEntryData->item;

		if (!item)
		{
			return nullptr;
		}

		return item->formType == Skyrim::FormType::kWeapon ? inventoryEntryData : nullptr;
	}
}
