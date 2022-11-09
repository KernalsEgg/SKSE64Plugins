#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class ButtonEvent;
	class InputEvent;
	class MouseMoveEvent;
	class PlayerControlsData;
	class ThumbstickEvent;

	class PlayerInputHandler
	{
	public:
		// Add
		virtual ~PlayerInputHandler();                                                                                // 0
		virtual bool ShouldHandleEvent(InputEvent* event) = 0;                                                        // 1
		virtual void HandleThumbstickEvent(ThumbstickEvent* thumbstickEvent, PlayerControlsData* playerControlsData); // 2
		virtual void HandleMouseMoveEvent(MouseMoveEvent* mouseMoveEvent, PlayerControlsData* playerControlsData);    // 3
		virtual void HandleButtonEvent(ButtonEvent* buttonEvent, PlayerControlsData* playerControlsData);             // 4

		// Member variables
		bool          handleInputEvents; // 8
		std::uint8_t  padding9;          // 9
		std::uint16_t paddingA;          // A
		std::uint32_t paddingC;          // C
	};
	static_assert(offsetof(PlayerInputHandler, handleInputEvents) == 0x8);
	static_assert(sizeof(PlayerInputHandler) == 0x10);
}
