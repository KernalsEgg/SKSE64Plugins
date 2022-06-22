#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/I/IDEvent.h"



namespace Skyrim
{
	class ButtonEvent :
		public IDEvent // 0
	{
	public:
		// Override
		virtual ~ButtonEvent() override; // 0

		// Member functions
		bool IsPressed() const;
		bool IsReleased() const;

		// Member variables
		float value;        // 28
		float holdDuration; // 2C
	};
	static_assert(offsetof(ButtonEvent, value) == 0x28);
	static_assert(offsetof(ButtonEvent, holdDuration) == 0x2C);
	static_assert(sizeof(ButtonEvent) == 0x30);
}
