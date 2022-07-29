#include "Shared/PCH.h"

#include "Shared/Skyrim/I/Inventory3DManager.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	Inventory3DManager* Inventory3DManager::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<Inventory3DManager**>(Addresses::Inventory3DManager::Singleton) };

		return *singleton;
	}
}
