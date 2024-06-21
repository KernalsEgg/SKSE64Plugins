#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/HeldStateHandler.h"



namespace Skyrim
{
	class ActivateHandler :
		public HeldStateHandler // 0
	{
	public:
		// Override
		virtual ~ActivateHandler() override; // 0

		// Override (HeldStateHandler)
		virtual bool ShouldHandleEvent(InputEvent* event) override;                                       // 1
		virtual void HandleButtonEvent(ButtonEvent* buttonEvent, PlayerControlsData* playerControlsData); // 4

		// Member variables
		bool          pressed;       // 18
		bool          held;          // 19
		bool          heldActivated; // 1A
		bool          disabled;      // 1B
		std::uint32_t padding1C;     // 1C
	};
	static_assert(offsetof(ActivateHandler, pressed) == 0x18);
	static_assert(offsetof(ActivateHandler, held) == 0x19);
	static_assert(offsetof(ActivateHandler, heldActivated) == 0x1A);
	static_assert(offsetof(ActivateHandler, disabled) == 0x1B);
	static_assert(sizeof(ActivateHandler) == 0x20);
}
