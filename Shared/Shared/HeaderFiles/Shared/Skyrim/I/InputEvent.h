#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/InputDevice.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BSFixedString;

	class InputEvent
	{
	public:
		enum class Type : std::uint32_t
		{
			kButton        = 0,
			kMouseMove     = 1,
			kChar          = 2,
			kThumbstick    = 3,
			kDeviceConnect = 4,
			kKinect        = 5
		};
		static_assert(sizeof(Type) == 0x4);

		// Add
		virtual ~InputEvent();                             // 0
		virtual bool                 HasIDCode() const;    // 1
		virtual const BSFixedString& GetUserEvent() const; // 2

		// Member variables
		Utility::Enumeration<InputDevice, std::uint32_t> inputDevice;    // 8
		Utility::Enumeration<Type, std::uint32_t>        inputEventType; // C
		InputEvent*                                      next;           // 10
	};
	static_assert(offsetof(InputEvent, inputDevice) == 0x8);
	static_assert(offsetof(InputEvent, inputEventType) == 0xC);
	static_assert(offsetof(InputEvent, next) == 0x10);
	static_assert(sizeof(InputEvent) == 0x18);
}
