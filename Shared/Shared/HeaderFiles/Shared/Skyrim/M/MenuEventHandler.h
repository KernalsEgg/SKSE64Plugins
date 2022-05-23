#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSIntrusiveRefCounted.h"



namespace Skyrim
{
	class ButtonEvent;
	class InputEvent;
	class KinectEvent;
	class MouseMoveEvent;
	class ThumbstickEvent;

	class MenuEventHandler :
		public BSIntrusiveRefCounted // 0
	{
	public:
		// Add
		virtual ~MenuEventHandler();                                      // 0
		virtual bool CanProcess(InputEvent* inputEvent) = 0;              // 1
		virtual bool ProcessKinect(KinectEvent* kinectEvent);             // 2
		virtual bool ProcessThumbstick(ThumbstickEvent* thumbstickEvent); // 3
		virtual bool ProcessMouseMove(MouseMoveEvent* mouseMoveEvent);    // 4
		virtual bool ProcessButton(ButtonEvent* buttonEvent);             // 5

		// Member variables
		bool          registered; // C
		std::uint8_t  unknownD;   // D
		std::uint16_t paddingE;   // E
	};
	static_assert(offsetof(MenuEventHandler, registered) == 0xC);
	static_assert(sizeof(MenuEventHandler) == 0x10);
}
