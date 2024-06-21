#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	template <class T>
	class SettingCollection
	{
	public:
		// Add
		virtual ~SettingCollection();              // 0
		virtual void Add(T* setting)          = 0; // 1
		virtual void Remove(T* setting)       = 0; // 2
		virtual bool WriteSetting(T& setting) = 0; // 3
		virtual bool ReadSetting(T& setting)  = 0; // 4
		virtual bool Open(bool write);             // 5
		virtual bool Close();                      // 6
		virtual bool ReadSettingsFromProfile();    // 7
		virtual bool WriteSettings();              // 8
		virtual bool ReadSettings();               // 9

		// Member variables
		std::uint64_t unknown8;   // 8
		std::uint64_t unknown10;  // 10
		std::uint64_t unknown18;  // 18
		std::uint64_t unknown20;  // 20
		std::uint64_t unknown28;  // 28
		std::uint64_t unknown30;  // 30
		std::uint64_t unknown38;  // 38
		std::uint64_t unknown40;  // 40
		std::uint64_t unknown48;  // 48
		std::uint64_t unknown50;  // 50
		std::uint64_t unknown58;  // 58
		std::uint64_t unknown60;  // 60
		std::uint64_t unknown68;  // 68
		std::uint64_t unknown70;  // 70
		std::uint64_t unknown78;  // 78
		std::uint64_t unknown80;  // 80
		std::uint64_t unknown88;  // 88
		std::uint64_t unknown90;  // 90
		std::uint64_t unknown98;  // 98
		std::uint64_t unknownA0;  // A0
		std::uint64_t unknownA8;  // A8
		std::uint64_t unknownB0;  // B0
		std::uint64_t unknownB8;  // B8
		std::uint64_t unknownC0;  // C0
		std::uint64_t unknownC8;  // C8
		std::uint64_t unknownD0;  // D0
		std::uint64_t unknownD8;  // D8
		std::uint64_t unknownE0;  // E0
		std::uint64_t unknownE8;  // E8
		std::uint64_t unknownF0;  // F0
		std::uint64_t unknownF8;  // F8
		std::uint64_t unknown100; // 100
		std::uint64_t unknown108; // 108
		std::uint64_t unknown110; // 110
	};
	static_assert(sizeof(SettingCollection<void*>) == 0x118);
}
