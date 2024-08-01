#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/ScaleformInterface.h"

#include "Shared/Utility/InformationBox.h"



namespace SKSE
{
	bool ScaleformInterface::Register(const char* name, RegisterCallback* registerCallback)
	{
		auto result = this->register_(name, registerCallback);

		if (!result)
		{
			Utility::InformationBox::Error("Failed to register {} for a scaleform interface callback.", name);
		}

		return result;
	}

	void ScaleformInterface::RegisterInventory(RegisterInventoryCallback* registerInventoryCallback)
	{
		this->registerInventory_(registerInventoryCallback);
	}

	std::uint32_t ScaleformInterface::Version() const
	{
		return this->version_;
	}
}
