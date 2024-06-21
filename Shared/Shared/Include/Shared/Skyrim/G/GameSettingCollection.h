#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/SettingCollectionMap.h"
#include "Shared/Skyrim/S/SettingT.h"



namespace Skyrim
{
	class TESFile;

	class GameSettingCollection :
		public SettingCollectionMap<Setting> // 0
	{
	public:
		// Override
		virtual ~GameSettingCollection() override; // 0

		// Override (SettingCollectionMap<Setting>)
		virtual bool WriteSetting(Setting& setting) override; // 3
		virtual bool ReadSetting(Setting& setting) override;  // 4
		virtual bool Open(bool write) override;               // 5
		virtual bool Close() override;                        // 6

		// Add
		virtual bool ReadSettingFromFile(TESFile* file, const char* name); // A

		// Non-member functions
		static GameSettingCollection* GetSingleton();
		static void                   InitializeCollection();
		static Setting*               InitializeSetting(const char* name);

		// Member functions
		Setting* GetSetting(const char* name) const;
	};
	static_assert(sizeof(GameSettingCollection) == 0x140);
}
