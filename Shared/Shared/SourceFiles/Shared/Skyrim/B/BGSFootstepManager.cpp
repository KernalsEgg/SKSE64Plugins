#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSFootstepManager.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	BGSFootstepManager* BGSFootstepManager::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<BGSFootstepManager**>(Addresses::BGSFootstepManager::Singleton()) };

		return *singleton;
	}
}
