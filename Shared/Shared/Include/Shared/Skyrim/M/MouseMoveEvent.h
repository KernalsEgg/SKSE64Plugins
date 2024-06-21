#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/IDEvent.h"



namespace Skyrim
{
	class MouseMoveEvent :
		public IDEvent // 0
	{
	public:
		// Override
		virtual ~MouseMoveEvent() override; // 0

		// Member variables
		std::int32_t x; // 28
		std::int32_t y; // 2C
	};
	static_assert(offsetof(MouseMoveEvent, x) == 0x28);
	static_assert(offsetof(MouseMoveEvent, y) == 0x2C);
	static_assert(sizeof(MouseMoveEvent) == 0x30);
}
