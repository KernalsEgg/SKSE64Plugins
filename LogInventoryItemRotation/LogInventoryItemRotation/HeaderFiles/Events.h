#pragma once

#include "PrecompiledHeader.h"



namespace LogInventoryItemRotation
{
	class Events
	{
	public:
		static void Register();

	private:
		static std::uint16_t AdjustRotation(float radians);
		static bool&         MouseRotation();
		static void          StopMouseRotation(void* unused);
	};
}
