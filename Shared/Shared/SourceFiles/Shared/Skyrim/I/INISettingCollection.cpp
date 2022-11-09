#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/INISettingCollection.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	SettingT<INISettingCollection>* INISettingCollection::ForceAllDecals()
	{
		auto* singleton{ reinterpret_cast<SettingT<INISettingCollection>*>(Addresses::INISettingCollection::ForceAllDecals) };

		return singleton;
	}

	SettingT<INISettingCollection>* INISettingCollection::NumberActorsAllowedToMorph()
	{
		auto* singleton{ reinterpret_cast<SettingT<INISettingCollection>*>(Addresses::INISettingCollection::NumberActorsAllowedToMorph) };

		return singleton;
	}

	SettingT<INISettingCollection>* INISettingCollection::ZKeyDelay()
	{
		auto* singleton{ reinterpret_cast<SettingT<INISettingCollection>*>(Addresses::INISettingCollection::ZKeyDelay) };

		return singleton;
	}
}
