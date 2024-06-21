#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/I/InputDevice.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	struct BSRemoteGamepadEvent;

	class BSIInputDevice;
	class InputEvent;

	class BSInputDeviceManager :
		public BSTEventSource<InputEvent*>,          // 0
		public BSTSingletonSDM<BSInputDeviceManager> // 58
	{
	public:
		// Non-member functions
		static BSInputDeviceManager* GetSingleton();

		// Member variables
		std::uint8_t                         padding59;                                                            // 59
		std::uint16_t                        padding5A;                                                            // 5A
		std::uint32_t                        padding5C;                                                            // 5C
		BSIInputDevice*                      inputDevices[Utility::Conversion::ToUnderlying(InputDevice::kTotal)]; // 60
		std::uint64_t                        unknown80;                                                            // 80
		BSTEventSource<BSRemoteGamepadEvent> remoteGamepadEventSource;                                             // 88
		std::uint64_t                        unknownE0;                                                            // E0
		std::uint64_t                        unknownE8;                                                            // E8
	};
	static_assert(offsetof(BSInputDeviceManager, inputDevices) == 0x60);
	static_assert(offsetof(BSInputDeviceManager, remoteGamepadEventSource) == 0x88);
	static_assert(sizeof(BSInputDeviceManager) == 0xF0);
}
