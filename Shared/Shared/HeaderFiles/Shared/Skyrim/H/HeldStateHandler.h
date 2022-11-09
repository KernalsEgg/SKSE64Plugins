#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/P/PlayerInputHandler.h"



namespace Skyrim
{
	class ButtonEvent;

	class HeldStateHandler :
		public PlayerInputHandler // 0
	{
	public:
		// Override
		virtual ~HeldStateHandler() override; // 0

		// Add
		virtual void UpdateHeldStateActive(const ButtonEvent* buttonEvent); // 5
		virtual void SetHeldStateActive(bool heldStateActive);              // 6

		// Member variables
		bool          heldStateActive;     // 10
		bool          triggerForceRelease; // 11
		std::uint16_t padding12;           // 12
		std::uint32_t padding14;           // 14
	};
	static_assert(offsetof(HeldStateHandler, heldStateActive) == 0x10);
	static_assert(offsetof(HeldStateHandler, triggerForceRelease) == 0x11);
	static_assert(sizeof(HeldStateHandler) == 0x18);
}
