#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	enum class InputDevice : std::uint32_t
	{
		kNone            = static_cast<std::underlying_type_t<InputDevice>>(-1),
		kKeyboard        = 0,
		kMouse           = 1,
		kGamepad         = 2,
		kVirtualKeyboard = 3,
		kTotal           = 4
	};
	static_assert(sizeof(InputDevice) == 0x4);
}
