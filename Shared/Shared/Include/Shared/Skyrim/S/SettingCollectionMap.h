#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/SettingCollection.h"



namespace Skyrim
{
	template <class T>
	class SettingCollectionMap :
		public SettingCollection<T> // 0
	{
	public:
		// Override
		virtual ~SettingCollectionMap() override; // 0

		// Override (SettingCollection<T>)
		virtual void Add(T* setting) override;    // 1
		virtual void Remove(T* setting) override; // 2
		virtual bool WriteSettings() override;    // 8
		virtual bool ReadSettings() override;     // 9

		// Member variables
		std::uint64_t unknown118; // 118
		std::uint64_t unknown120; // 120
		std::uint64_t unknown128; // 128
		std::uint64_t unknown130; // 130
		std::uint64_t unknown138; // 138
	};
	static_assert(sizeof(SettingCollectionMap<void*>) == 0x140);
}
