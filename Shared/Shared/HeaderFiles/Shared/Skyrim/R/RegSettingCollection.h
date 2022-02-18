#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/S/Setting.h"
#include "Shared/Skyrim/S/SettingCollectionList.h"



namespace Skyrim
{
	class RegSettingCollection :
		public SettingCollectionList<Setting>
	{
	public:
		// Override
		virtual ~RegSettingCollection() override; // 0

		// Override (SettingCollection<Setting>)
		virtual bool WriteSetting(Setting* setting) override;        // 3
		virtual bool ReadSetting(Setting* setting) override;         // 4
		virtual void Unknown5(SettingCollection<Setting>*) override; // 5
		virtual void Unknown6(SettingCollection<Setting>*) override; // 6
	};
	static_assert(sizeof(RegSettingCollection) == 0x128);
}
