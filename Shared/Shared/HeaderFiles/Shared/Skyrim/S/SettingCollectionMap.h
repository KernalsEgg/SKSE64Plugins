#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/S/SettingCollection.h"



namespace Skyrim
{
	template <class T>
	class SettingCollectionMap :
		public SettingCollection<T>
	{
	public:
		// Override
		virtual ~SettingCollectionMap() override; // 0

		// Override (SettingCollection<T>)
		virtual void InsertSetting(T* setting) override;       // 1
		virtual void RemoveSetting(T* setting) override;       // 2
		virtual void Unknown8(SettingCollection<T>*) override; // 8
		virtual void Unknown9(SettingCollection<T>*) override; // 9

		// Member variables
		std::int64_t unknown118; // 118
		std::int64_t unknown120; // 120
		std::int64_t unknown128; // 128
		std::int64_t unknown130; // 130
		std::int64_t unknown138; // 138
	};
	static_assert(sizeof(SettingCollectionMap<void*>) == 0x140);
}
