#pragma once

#include "PCH.h"

#include "Shared/Skyrim/I/Inventory3DManager.h"
#include "Shared/Skyrim/M/MouseMoveEvent.h"
#include "Shared/Skyrim/T/ThumbstickEvent.h"



namespace LogInventoryItemRotation
{
	class Events
	{
	public:
		static void Register();

	private:
		static std::uint16_t AdjustRotation(float radians);
		static bool          ProcessMouseMove(Skyrim::Inventory3DManager* inventory3DManager, Skyrim::MouseMoveEvent* mouseMoveEvent);
		static bool          ProcessThumbstick(Skyrim::Inventory3DManager* inventory3DManager, Skyrim::ThumbstickEvent* thumbstickEvent);

		static decltype(&Events::ProcessMouseMove)  processMouseMove_;
		static decltype(&Events::ProcessThumbstick) processThumbstick_;
	};
}
