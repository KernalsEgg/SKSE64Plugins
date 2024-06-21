#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/INISettingCollection.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	INISettingCollection* INISettingCollection::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<INISettingCollection**>(Addresses::INISettingCollection::Singleton()) };

		return *singleton;
	}

	void INISettingCollection::InitializeCollection()
	{
		auto* function{ reinterpret_cast<decltype(INISettingCollection::InitializeCollection)*>(
			Addresses::INISettingCollection::InitializeCollection()) };

		function();
	}

	Setting* INISettingCollection::InitializeSetting(const char* name)
	{
		INISettingCollection::InitializeCollection();

		return INISettingCollection::GetSingleton()->GetSetting(name);
	}

	Setting* INISettingCollection::GetSetting(const char* name) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&INISettingCollection::GetSetting)>::type>(
			Addresses::INISettingCollection::GetSetting()) };

		return function(this, name);
	}
}
