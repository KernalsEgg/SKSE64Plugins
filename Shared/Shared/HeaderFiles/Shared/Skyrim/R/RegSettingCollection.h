#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/Setting.h"
#include "Shared/Skyrim/S/SettingCollectionList.h"



namespace Skyrim
{
	class RegSettingCollection :
		public SettingCollectionList<Setting> // 0
	{
	public:
		// Override
		virtual ~RegSettingCollection() override; // 0

		// Override (SettingCollection<Setting>)
		virtual bool WriteSetting(Setting& setting) override; // 3
		virtual bool ReadSetting(Setting& setting) override;  // 4
		virtual bool Open(bool write) override;               // 5
		virtual bool Close() override;                        // 6
	};
	static_assert(sizeof(RegSettingCollection) == 0x128);
}
