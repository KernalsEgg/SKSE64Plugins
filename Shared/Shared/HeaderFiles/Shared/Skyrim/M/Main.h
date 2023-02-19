#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSPackedTaskQueue.h"
#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/S/ScrapHeap.h"



namespace Skyrim
{
	struct BSGamerProfileEvent;
	struct PositionPlayerEvent;

	struct BSSaveDataSystemUtilityImage
	{
	public:
		// Member variables
		std::uint32_t size;     // 0
		std::uint32_t width;    // 4
		std::uint32_t height;   // 8
		std::uint32_t paddingC; // C
		char*         buffer;   // 10
	};
	static_assert(offsetof(BSSaveDataSystemUtilityImage, size) == 0x0);
	static_assert(offsetof(BSSaveDataSystemUtilityImage, width) == 0x4);
	static_assert(offsetof(BSSaveDataSystemUtilityImage, height) == 0x8);
	static_assert(offsetof(BSSaveDataSystemUtilityImage, buffer) == 0x10);
	static_assert(sizeof(BSSaveDataSystemUtilityImage) == 0x18);

	class Main :
		public BSTEventSink<PositionPlayerEvent>, // 0
		public BSTEventSink<BSGamerProfileEvent>  // 8
	{
	public:
		// Override
		virtual ~Main() override; // 0

		// Override (BSTEventSink<PositionPlayerEvent>)
		virtual EventNotifyControl ProcessEvent(const PositionPlayerEvent* eventArguments, BSTEventSource<PositionPlayerEvent>* eventSource) override; // 1

		// Override (BSTEventSink<BSGamerProfileEvent>)
		virtual EventNotifyControl ProcessEvent(const BSGamerProfileEvent* eventArguments, BSTEventSource<BSGamerProfileEvent>* eventSource) override; // 1

		// Non-member functions
		static std::uint32_t GetFrameCount();
		static Main*         GetSingleton();

		// Member variables
		bool                         quitGame;                    // 10
		bool                         resetGame;                   // 11
		bool                         fullReset;                   // 12
		bool                         gameActive;                  // 13
		bool                         onIdle;                      // 14
		bool                         reloadContent;               // 15
		bool                         freezeTime;                  // 16
		bool                         freezeNextFrame;             // 17
		::HWND                       window;                      // 18
		::HINSTANCE                  instance;                    // 20
		std::uint32_t                threadID;                    // 28
		std::uint32_t                unknown2C;                   // 2C
		std::uint64_t                unknown30;                   // 30
		ScrapHeap                    packedTaskHeap;              // 38
		BSPackedTaskQueue            packedTaskQueue;             // C8
		ScrapHeap                    secondaryPackedTaskHeap;     // 108
		BSPackedTaskQueue            secondaryPackedTaskQueue;    // 198
		std::uint64_t                unknown1D8;                  // 1D8
		BSSaveDataSystemUtilityImage saveDataBackgroundImages[3]; // 1E0
		BSSaveDataSystemUtilityImage saveDataIconImages[3];       // 228
	};
	static_assert(offsetof(Main, quitGame) == 0x10);
	static_assert(offsetof(Main, resetGame) == 0x11);
	static_assert(offsetof(Main, fullReset) == 0x12);
	static_assert(offsetof(Main, gameActive) == 0x13);
	static_assert(offsetof(Main, onIdle) == 0x14);
	static_assert(offsetof(Main, reloadContent) == 0x15);
	static_assert(offsetof(Main, freezeTime) == 0x16);
	static_assert(offsetof(Main, freezeNextFrame) == 0x17);
	static_assert(offsetof(Main, window) == 0x18);
	static_assert(offsetof(Main, instance) == 0x20);
	static_assert(offsetof(Main, threadID) == 0x28);
	static_assert(offsetof(Main, packedTaskHeap) == 0x38);
	static_assert(offsetof(Main, packedTaskQueue) == 0xC8);
	static_assert(offsetof(Main, secondaryPackedTaskHeap) == 0x108);
	static_assert(offsetof(Main, secondaryPackedTaskQueue) == 0x198);
	static_assert(offsetof(Main, saveDataBackgroundImages) == 0x1E0);
	static_assert(offsetof(Main, saveDataIconImages) == 0x228);
	static_assert(sizeof(Main) == 0x270);
}
