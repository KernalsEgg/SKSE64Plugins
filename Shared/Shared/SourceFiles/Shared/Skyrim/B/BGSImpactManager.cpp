#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSImpactManager.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	BGSImpactManager* BGSImpactManager::GetSingleton()
	{
		auto singleton{ reinterpret_cast<BGSImpactManager**>(Addresses::BGSImpactManager::Singleton) };

		return *singleton;
	}

	bool BGSImpactManager::PlaySound(const SoundData& soundData) const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&BGSImpactManager::PlaySound)>::type>(Addresses::BGSImpactManager::PlaySound) };

		return function(this, soundData);
	}
}
