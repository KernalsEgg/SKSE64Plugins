#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/INIPrefSettingCollection.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	INIPrefSettingCollection* INIPrefSettingCollection::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<INIPrefSettingCollection**>(Addresses::INIPrefSettingCollection::Singleton) };

		return *singleton;
	}

	void INIPrefSettingCollection::InitializeCollection()
	{
		auto* function{ reinterpret_cast<decltype(INIPrefSettingCollection::InitializeCollection)*>(Addresses::INIPrefSettingCollection::InitializeCollection) };

		function();
	}

	Setting* INIPrefSettingCollection::InitializeSetting(const char* name)
	{
		INIPrefSettingCollection::InitializeCollection();

		return INIPrefSettingCollection::GetSingleton()->GetSetting(name);
	}
}
