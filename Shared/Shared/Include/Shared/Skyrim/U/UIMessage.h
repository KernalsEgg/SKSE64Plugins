#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class IUIMessageData;

	enum class UIMessageType : std::uint32_t
	{
		kUpdate    = 0,
		kShow      = 1,
		kReshow    = 2,
		kHide      = 3,
		kForceHide = 4
	};
	static_assert(sizeof(UIMessageType) == 0x4);

	class UIMessage
	{
	public:
		// Member variables
		BSFixedString                                      menuName;    // 0
		Utility::Enumeration<UIMessageType, std::uint32_t> messageType; // 8
		std::uint32_t                                      paddingC;    // C
		IUIMessageData*                                    messageData; // 10
		bool                                               isPooled;    // 18
		std::uint8_t                                       padding19;   // 19
		std::uint16_t                                      padding1A;   // 1A
		std::uint32_t                                      padding1C;   // 1C
	};
	static_assert(offsetof(UIMessage, menuName) == 0x0);
	static_assert(offsetof(UIMessage, messageType) == 0x8);
	static_assert(offsetof(UIMessage, messageData) == 0x10);
	static_assert(offsetof(UIMessage, isPooled) == 0x18);
	static_assert(sizeof(UIMessage) == 0x20);
}
