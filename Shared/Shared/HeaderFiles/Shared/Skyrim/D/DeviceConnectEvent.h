#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/I/InputEvent.h"



namespace Skyrim
{
	class DeviceConnectEvent :
		public InputEvent // 0
	{
	public:
		// Override
		virtual ~DeviceConnectEvent() override; // 0

		// Member variables
		bool          connected; // 18
		std::uint8_t  padding19; // 19
		std::uint16_t padding1A; // 1A
		std::uint32_t padding1C; // 1C
	};
	static_assert(offsetof(DeviceConnectEvent, connected) == 0x18);
	static_assert(sizeof(DeviceConnectEvent) == 0x20);
}
