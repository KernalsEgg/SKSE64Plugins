#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AIProcess.h"

#include "Shared/Skyrim/H/HighProcessData.h"
#include "Shared/Skyrim/M/MiddleHighProcessData.h"



namespace Skyrim
{
	bhkCharacterController* AIProcess::GetCharacterController() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->characterController.get() : nullptr;
	}

	ObjectReferenceHandle AIProcess::GetCurrentFurniture() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->currentFurniture : ObjectReferenceHandle{};
	}

	InventoryEntryData* AIProcess::GetEquippedItem(bool leftHand) const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		if (!middleHighProcessData)
		{
			return nullptr;
		}

		return leftHand ? middleHighProcessData->leftHand : middleHighProcessData->rightHand;
	}

	NiAVObject* AIProcess::GetHeadNode() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->headNode : nullptr;
	}

	NiAVObject* AIProcess::GetTorsoNode() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->torsoNode : nullptr;
	}

	HitData* AIProcess::GetLastHitData() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->lastHitData : nullptr;
	}

	float AIProcess::GetMaximumWardPower() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->maximumWardPower : -1.0F;
	}

	bool AIProcess::IsDualCasting() const
	{
		auto* highProcessData = this->highProcessData;

		return highProcessData && highProcessData->dualCasting;
	}

	void AIProcess::SetMaximumWardPower(float maximumWardPower)
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		if (!middleHighProcessData)
		{
			return;
		}

		middleHighProcessData->maximumWardPower = maximumWardPower;
	}
}
