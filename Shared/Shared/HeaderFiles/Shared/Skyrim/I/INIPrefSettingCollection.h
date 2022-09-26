#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/INISettingCollection.h"



namespace Skyrim
{
	class INIPrefSettingCollection :
		public INISettingCollection // 0
	{
	public:
		// Override
		virtual ~INIPrefSettingCollection() override; // 0

		// Override (INISettingCollection)
		virtual bool ReadSettingsFromProfile() override; // 7
		virtual bool WriteSettings() override;           // 8
		virtual bool ReadSettings() override;            // 9

		// Non-member functions
		static SettingT<INIPrefSettingCollection>* Decals();
	};
	static_assert(sizeof(INIPrefSettingCollection) == 0x128);
}
