#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GameSettingCollection.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	GameSettingCollection* GameSettingCollection::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<GameSettingCollection**>(Addresses::GameSettingCollection::Singleton()) };

		return *singleton;
	}

	void GameSettingCollection::InitializeCollection()
	{
		auto* function{ reinterpret_cast<decltype(GameSettingCollection::InitializeCollection)*>(
			Addresses::GameSettingCollection::InitializeCollection()) };

		function();
	}

	Setting* GameSettingCollection::InitializeSetting(const char* name)
	{
		GameSettingCollection::InitializeCollection();

		return GameSettingCollection::GetSingleton()->GetSetting(name);
	}

	Setting* GameSettingCollection::GetSetting(const char* name) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&GameSettingCollection::GetSetting)>::type>(
			Addresses::GameSettingCollection::GetSetting()) };

		return function(this, name);
	}
}
