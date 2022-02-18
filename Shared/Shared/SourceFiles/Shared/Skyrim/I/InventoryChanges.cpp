#include "Shared/PCH.h"

#include "Shared/Skyrim/I/InventoryChanges.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/F/FormType.h"



namespace Skyrim
{
	void InventoryChanges::ResetWeight()
	{
		this->previousInventoryWeight = this->currentInventoryWeight;
		this->currentInventoryWeight  = -1.0F;

		auto owner = this->owner;

		if (owner)
		{
			if (owner->formType == FormType::kActor)
			{
				static_cast<Actor*>(owner)->equippedWeight = -1.0F;
			}
		}
	}
}
