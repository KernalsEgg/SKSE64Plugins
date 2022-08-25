#pragma once

#include "Shared/PCH.h"

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
		virtual void Unknown7(SettingCollection<Setting>*) override; // 7
		virtual void Unknown8(SettingCollection<Setting>*) override; // 8
		virtual void Unknown9(SettingCollection<Setting>*) override; // 9

		// Non-member functions
		static SettingT<INIPrefSettingCollection>* Decals();
	};
	static_assert(sizeof(INIPrefSettingCollection) == 0x128);
}
