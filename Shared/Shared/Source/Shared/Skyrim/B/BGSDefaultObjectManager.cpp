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

	TESForm* BGSDefaultObjectManager::GetDefaultObject(Utility::Enumeration<DefaultObject, std::uint32_t> defaultObject) const
	{
		return this->defaultObjectInitialized[defaultObject.underlying()] ? this->defaultObjects[defaultObject.underlying()] : nullptr;
	}
}
