#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class IUIMessageData;

	class UIMessage
	{
	public:
		enum class Type : std::uint32_t
		{
			kUpdate    = 0,
			kShow      = 1,
			kReshow    = 2,
			kHide      = 3,
			kForceHide = 4
		};
		static_assert(sizeof(Type) == 0x4);

		// Member variables
		BSFixedString                             menuName;  // 0
		Utility::Enumeration<Type, std::uint32_t> type;      // 8
		std::uint32_t                             paddingC;  // C
		IUIMessageData*                           data;      // 10
		bool                                      isPooled;  // 18
		std::uint8_t                              padding19; // 19
		std::uint16_t                             padding1A; // 1A
		std::uint32_t                             padding1C; // 1C
	};
	static_assert(offsetof(UIMessage, menuName) == 0x0);
	static_assert(offsetof(UIMessage, type) == 0x8);
	static_assert(offsetof(UIMessage, data) == 0x10);
	static_assert(offsetof(UIMessage, isPooled) == 0x18);
	static_assert(sizeof(UIMessage) == 0x20);
}
