#pragma once

#include "PCH.h"



namespace LogInventoryItemRotation
{
	class Hooks
	{
	public:
		static void Install();

	private:
		static std::uint16_t AdjustRotation(float radians);
		static bool&         MouseRotation();
		static void          StopMouseRotation(void* unused);
	};
}
