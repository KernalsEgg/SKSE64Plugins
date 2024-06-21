#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSDefaultObjectManager.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	BGSDefaultObjectManager* BGSDefaultObjectManager::GetSingleton()
	{
		auto* function{ reinterpret_cast<decltype(BGSDefaultObjectManager::GetSingleton)*>(
			Addresses::BGSDefaultObjectManager::GetSingleton()) };

		return function();
	}

	TESForm* BGSDefaultObjectManager::GetDefaultObject(Utility::Enumeration<DefaultObjects, std::uint32_t> defaultObject) const
	{
		return this->objectInitialized[defaultObject.underlying()] ? this->objects[defaultObject.underlying()] : nullptr;
	}
}
