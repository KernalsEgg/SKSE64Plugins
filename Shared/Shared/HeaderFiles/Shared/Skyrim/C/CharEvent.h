#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/I/InputEvent.h"



namespace Skyrim
{
	class CharEvent :
		public InputEvent // 0
	{
	public:
		// Override
		virtual ~CharEvent() override; // 0

		// Member variables
		std::uint32_t keyCode;   // 18
		std::uint32_t padding1C; // 1C
	};
	static_assert(offsetof(CharEvent, keyCode) == 0x18);
	static_assert(sizeof(CharEvent) == 0x20);
};
