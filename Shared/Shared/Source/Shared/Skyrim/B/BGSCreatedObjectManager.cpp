#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSCreatedObjectManager.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	BGSCreatedObjectManager* BGSCreatedObjectManager::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<BGSCreatedObjectManager**>(Addresses::BGSCreatedObjectManager::Singleton()) };

		return *singleton;
	}

	void BGSCreatedObjectManager::DecrementReference(AlchemyItem* alchemyItem)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BGSCreatedObjectManager::DecrementReference)>::type>(
			Addresses::BGSCreatedObjectManager::DecrementReference()) };

		function(this, alchemyItem);
	}
}
