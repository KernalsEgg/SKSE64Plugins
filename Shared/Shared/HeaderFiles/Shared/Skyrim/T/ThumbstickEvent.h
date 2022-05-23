#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/I/IDEvent.h"



namespace Skyrim
{
	class ThumbstickEvent :
		public IDEvent // 0
	{
	public:
		// Override
		virtual ~ThumbstickEvent() override; // 0

		// Member variables
		float x; // 28
		float y; // 2C
	};
	static_assert(offsetof(ThumbstickEvent, x) == 0x28);
	static_assert(offsetof(ThumbstickEvent, y) == 0x2C);
	static_assert(sizeof(ThumbstickEvent) == 0x30);
}
