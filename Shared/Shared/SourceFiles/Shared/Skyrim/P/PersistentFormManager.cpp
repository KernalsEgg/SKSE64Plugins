#include "Shared/PCH.h"

#include "Shared/Skyrim/P/PersistentFormManager.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	PersistentFormManager* PersistentFormManager::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<PersistentFormManager**>(Addresses::PersistentFormManager::Singleton) };

		return *singleton;
	}
}
