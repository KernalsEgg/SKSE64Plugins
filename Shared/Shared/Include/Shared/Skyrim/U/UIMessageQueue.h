#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTMessageQueue.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/U/UIMessage.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BSFixedString;
	class IUIMessageData;
	class TESBoundObject;
	class TESObjectREFR;

	class UIMessageQueue :
		public BSTSingletonSDM<UIMessageQueue> // 0
	{
	public:
		enum
		{
			kPoolSize = 64
		};

		// Non-member functions
		static void            AddInventoryUpdateMessage(TESObjectREFR* reference, TESBoundObject* boundObject);
		static UIMessageQueue* GetSingleton();

		// Member functions
		void AddMessage(const BSFixedString& menuName, Utility::Enumeration<UIMessage::Type, std::uint32_t> type, IUIMessageData* data);

		// Member variables
		std::uint8_t                                 padding1;               // 1
		std::uint16_t                                padding2;               // 2
		std::uint32_t                                padding4;               // 4
		BSTCommonStaticMessageQueue<UIMessage*, 100> messages;               // 8
		std::uint64_t                                unknown348;             // 348
		std::uint64_t                                unknown350;             // 350
		std::uint64_t                                unknown358;             // 358
		std::uint64_t                                unknown360;             // 360
		std::uint64_t                                unknown368;             // 368
		std::uint64_t                                unknown370;             // 370
		std::uint32_t                                poolUsed;               // 378
		std::uint32_t                                padding37C;             // 37C
		UIMessage                                    messagePool[kPoolSize]; // 380
	};
	static_assert(offsetof(UIMessageQueue, messages) == 0x8);
	static_assert(offsetof(UIMessageQueue, poolUsed) == 0x378);
	static_assert(offsetof(UIMessageQueue, messagePool) == 0x380);
	static_assert(sizeof(UIMessageQueue) == 0xB80);
}
