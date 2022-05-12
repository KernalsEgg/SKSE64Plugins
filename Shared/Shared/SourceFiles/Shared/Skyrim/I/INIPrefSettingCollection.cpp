#include "Shared/PCH.h"

#include "Shared/Skyrim/I/INIPrefSettingCollection.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	SettingT<INIPrefSettingCollection>* INIPrefSettingCollection::Decals()
	{
		auto singleton{ reinterpret_cast<SettingT<INIPrefSettingCollection>*>(Addresses::INIPrefSettingCollection::Decals) };

		return singleton;
	}
}
