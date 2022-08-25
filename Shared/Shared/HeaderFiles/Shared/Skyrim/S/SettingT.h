#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/S/Setting.h"



namespace Skyrim
{
	template <class T>
	class SettingT :
		public Setting // 0
	{
	public:
		// Override
		virtual ~SettingT() override; // 0
	};
	static_assert(sizeof(SettingT<void>) == 0x18);
}
