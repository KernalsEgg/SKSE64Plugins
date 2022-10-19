#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	struct MenuModeChangeEvent;
	struct MenuOpenCloseEvent;

	class UI :
		public BSTSingletonSDM<UI>,                 // 0
		public BSTEventSource<MenuOpenCloseEvent>,  // 8
		public BSTEventSource<MenuModeChangeEvent>, // 60
		public BSTEventSource<void*>                // B8 (MenuModeCounterChangedEvent/TutorialEvent)
	{
	public:
		// Non-member functions
		static UI*  GetSingleton();
		static void Notification(const char* notification, const char* sound, bool queueOnce);
		static void PlaySound(const char* editorID);

		template <class... Arguments>
		static void MessageBox(const char* message, void (*messageBoxCallback)(std::int8_t buttonIndex), std::int32_t baseButtonIndex, std::uint32_t warningType, std::int32_t depthPriority, Arguments... buttons)
		{
			auto* function{ reinterpret_cast<decltype(&UI::MessageBox<Arguments...>)>(Addresses::UI::MessageBox) };

			function(message, messageBoxCallback, baseButtonIndex, warningType, depthPriority, buttons...);
		}

		// Member functions
		bool IsMenuOpen(const BSFixedString& menuName) const;

		template <class T>
		BSTEventSource<T>* GetEventSource()
		{
			return static_cast<BSTEventSource<T>*>(this);
		}

		template <class T>
		void AddEventSink(BSTEventSink<T>* eventSink)
		{
			this->GetEventSource<T>()->AddEventSink(eventSink);
		}

		template <class T>
		void RemoveEventSink(BSTEventSink<T>* eventSink)
		{
			this->GetEventSource<T>()->RemoveEventSink(eventSink);
		}

		// Member variables
		std::uint64_t      unknown110;                 // 110
		std::uint64_t      unknown118;                 // 118
		std::uint64_t      unknown120;                 // 120
		std::uint64_t      unknown128;                 // 128
		std::uint64_t      unknown130;                 // 130
		std::uint64_t      unknown138;                 // 138
		std::uint64_t      unknown140;                 // 140
		std::uint64_t      unknown148;                 // 148
		std::uint64_t      unknown150;                 // 150
		mutable BSSpinLock messageProcessingLock;      // 158
		std::uint32_t      pauseGameCount;             // 160 (IMenu::Flags::kPauseGame)
		std::uint32_t      inventoryItemMenuCount;     // 164 (IMenu::Flags::kInventoryItemMenu)
		std::uint32_t      disablePauseMenuCount;      // 168 (IMenu::Flags::kDisablePauseMenu)
		std::uint32_t      allowSavingCount;           // 16C (IMenu::Flags::kAllowSaving)
		std::uint32_t      showCursorWhenTopmostCount; // 170 (IMenu::Flags::kShowCursorWhenTopmost)
		std::uint32_t      customRenderingCount;       // 174 (IMenu::Flags::kCustomRendering)
		std::uint32_t      applicationMenuCount;       // 178 (IMenu::Flags::kApplicationMenu)
		bool               modal;                      // 17C (IMenu::Flags::kModal)
		std::uint8_t       padding17D;                 // 17D
		std::uint16_t      padding17E;                 // 17E
		std::uint64_t      unknown180;                 // 180
		std::uint64_t      unknown188;                 // 188
		std::uint64_t      unknown190;                 // 190
		std::uint64_t      unknown198;                 // 198
		std::uint64_t      unknown1A0;                 // 1A0
		std::uint64_t      unknown1A8;                 // 1A8
		std::uint64_t      unknown1B0;                 // 1B0
		std::uint64_t      unknown1B8;                 // 1B8
		std::uint64_t      unknown1C0;                 // 1C0
	};
	static_assert(offsetof(UI, messageProcessingLock) == 0x158);
	static_assert(offsetof(UI, pauseGameCount) == 0x160);
	static_assert(offsetof(UI, inventoryItemMenuCount) == 0x164);
	static_assert(offsetof(UI, disablePauseMenuCount) == 0x168);
	static_assert(offsetof(UI, allowSavingCount) == 0x16C);
	static_assert(offsetof(UI, showCursorWhenTopmostCount) == 0x170);
	static_assert(offsetof(UI, customRenderingCount) == 0x174);
	static_assert(offsetof(UI, applicationMenuCount) == 0x178);
	static_assert(offsetof(UI, modal) == 0x17C);
	static_assert(sizeof(UI) == 0x1C8);
}
