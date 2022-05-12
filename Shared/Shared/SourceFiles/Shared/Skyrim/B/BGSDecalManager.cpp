#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSDecalManager.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	BGSDecalManager* BGSDecalManager::GetSingleton()
	{
		auto singleton{ reinterpret_cast<BGSDecalManager**>(Addresses::BGSDecalManager::Singleton) };

		return *singleton;
	}
}
