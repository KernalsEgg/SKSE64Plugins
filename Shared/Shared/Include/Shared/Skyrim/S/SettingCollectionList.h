#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/S/SettingCollection.h"



namespace Skyrim
{
	template <class T>
	class SettingCollectionList :
		public SettingCollection<T> // 0
	{
	public:
		// Override
		virtual ~SettingCollectionList() override; // 0

		// Override (SettingCollection<T>)
		virtual void Add(T* setting) override;    // 1
		virtual void Remove(T* setting) override; // 2
		virtual bool WriteSettings() override;    // 8
		virtual bool ReadSettings() override;     // 9

		// Member variables
		BSSimpleList<T*> settings; // 118
	};
	static_assert(offsetof(SettingCollectionList<void*>, settings) == 0x118);
	static_assert(sizeof(SettingCollectionList<void*>) == 0x128);
}
