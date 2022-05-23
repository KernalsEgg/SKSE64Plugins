#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSInputDeviceManager.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	BSInputDeviceManager* BSInputDeviceManager::GetSingleton()
	{
		auto singleton{ reinterpret_cast<BSInputDeviceManager**>(Addresses::BSInputDeviceManager::Singleton) };

		return *singleton;
	}
}
