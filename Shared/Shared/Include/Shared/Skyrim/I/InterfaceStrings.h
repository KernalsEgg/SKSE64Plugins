#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSTSingleton.h"



namespace Skyrim
{
	class InterfaceStrings :
		public BSTSingletonSDM<InterfaceStrings> // 0
	{
	public:
		// Non-member functions
		static InterfaceStrings* GetSingleton();

		// Member variables
		std::uint8_t  padding1;               // 1
		std::uint16_t padding2;               // 2
		std::uint32_t padding4;               // 4
		BSFixedString faderData;              // 8, "FaderData"
		BSFixedString hudData;                // 10, "HUDData"
		BSFixedString hudCameraData;          // 18, "HUDCamData"
		BSFixedString floatingQuestMarkers;   // 20, "FloatingQuestMarkers"
		BSFixedString consoleData;            // 28, "ConsoleData"
		BSFixedString quantityData;           // 30, "QuantityData"
		BSFixedString messageBoxData;         // 38, "MessageBoxData"
		BSFixedString uiScaleformData;        // 40, "BSUIScaleformData"
		BSFixedString uiMessageData;          // 48, "BSUIMessageData"
		BSFixedString uiAnalogData;           // 50, "BSUIAnalogData"
		BSFixedString inventoryUpdateData;    // 58, "InventoryUpdateData"
		BSFixedString referenceHandleUIData;  // 60, "RefHandleUIData"
		BSFixedString formUIData;             // 68, "TESFormUIData"
		BSFixedString loadingMenuData;        // 70, "LoadingMenuData"
		BSFixedString kinectStateChangeData;  // 78, "KinectStateChangeData"
		BSFixedString kinectUserEventData;    // 80, "KinectUserEventData"
		BSFixedString inventoryMenu;          // 88, "InventoryMenu"
		BSFixedString console;                // 90, "Console"
		BSFixedString dialogueMenu;           // 98, "Dialogue Menu"
		BSFixedString hudMenu;                // A0, "HUD Menu"
		BSFixedString mainMenu;               // A8, "Main Menu"
		BSFixedString messageBoxMenu;         // B0, "MessageBoxMenu"
		BSFixedString cursorMenu;             // B8, "Cursor Menu"
		BSFixedString faderMenu;              // C0, "Fader Menu"
		BSFixedString magicMenu;              // C8, "MagicMenu"
		BSFixedString topMenu;                // D0, "Top Menu"
		BSFixedString overlayMenu;            // D8, "Overlay Menu"
		BSFixedString overlayInteractionMenu; // E0, "Overlay Interaction Menu"
		BSFixedString loadingMenu;            // E8, "Loading Menu"
		BSFixedString tweenMenu;              // F0, "TweenMenu"
		BSFixedString barterMenu;             // F8, "BarterMenu"
		BSFixedString giftMenu;               // 100, "GiftMenu"
		BSFixedString debugTextMenu;          // 108, "Debug Text Menu"
		BSFixedString mapMenu;                // 110, "MapMenu"
		BSFixedString lockpickingMenu;        // 118, "Lockpicking Menu"
		BSFixedString quantityMenu;           // 120, "Quantity Menu"
		BSFixedString statisticsMenu;         // 128, "StatsMenu"
		BSFixedString containerMenu;          // 130, "ContainerMenu"
		BSFixedString sleepWaitMenu;          // 138, "Sleep/Wait Menu"
		BSFixedString levelUpMenu;            // 140, "LevelUp Menu"
		BSFixedString journalMenu;            // 148, "Journal Menu"
		BSFixedString bookMenu;               // 150, "Book Menu"
		BSFixedString favoritesMenu;          // 158, "FavoritesMenu"
		BSFixedString raceSexMenu;            // 160, "RaceSex Menu"
		BSFixedString craftingMenu;           // 168, "Crafting Menu"
		BSFixedString trainingMenu;           // 170, "Training Menu"
		BSFixedString mistMenu;               // 178, "Mist Menu"
		BSFixedString tutorialMenu;           // 180, "Tutorial Menu"
		BSFixedString creditsMenu;            // 188, "Credits Menu"
		BSFixedString modManagerMenu;         // 190, "Mod Manager Menu"
		BSFixedString creationClubMenu;       // 198, "Creation Club Menu"
#ifdef SKYRIM_ANNIVERSARY_EDITION
		BSFixedString marketplaceMenu; // 1A0, "Marketplace Menu"
#endif
		BSFixedString titleSequenceMenu;       // 1A0, 1A8, "TitleSequence Menu"
		BSFixedString consoleNativeUIMenu;     // 1A8, 1B0, "Console Native UI Menu"
		BSFixedString kinectMenu;              // 1B0, 1B8, "Kinect Menu"
		BSFixedString loadWaitSpinner;         // 1B8, 1C0, "LoadWaitSpinner"
		BSFixedString streamingInstallMenu;    // 1C0, 1C8, "StreamingInstallMenu"
		BSFixedString textWidget;              // 1C8, 1D0, "TextWidget"
		BSFixedString buttonBarWidget;         // 1D0, 1D8, "ButtonBarWidget"
		BSFixedString graphWidget;             // 1D8, 1E0, "GraphWidget"
		BSFixedString textureWidget;           // 1E0, 1E8, "TextureWidget"
		BSFixedString uiMenuOK;                // 1E8, 1F0, "UIMenuOK"
		BSFixedString uiMenuCancel;            // 1F0, 1F8, "UIMenuCancel"
		BSFixedString showText;                // 1F8, 200, "Show Text"
		BSFixedString hideText;                // 200, 208, "Hide Text"
		BSFixedString showList;                // 208, 210, "Show List"
		BSFixedString voiceReady;              // 210, 218, "Voice Ready"
		BSFixedString dmfoString;              // 218, 220, "DMFOStr"
		BSFixedString showJournal;             // 220, 228, "Show Journal"
		BSFixedString journalSettingsSaved;    // 228, 230, "Journal Settings Saved"
		BSFixedString closeMenu;               // 230, 238, "CloseMenu"
		BSFixedString closingAllMenus;         // 238, 240, "Closing All Menus"
		BSFixedString refreshMenu;             // 240, 248, "RefreshMenu"
		BSFixedString cancelLoading;           // 248, 250, "CancelLoading"
		BSFixedString menuTextureDegradeEvent; // 250, 258, "Menu Texture Degrade Event"
#ifdef SKYRIM_ANNIVERSARY_EDITION
		BSFixedString userSettingsLoaded; // 260, "UserSettingsLoaded"
		BSFixedString activityStarted;    // 268, "ActivityStarted"
#endif
		BSFixedString diamondMarker; // 258, 270, "<img src='DiamondMarker' width='10' height='15' align='baseline' vspace='5'>"
	};
	static_assert(offsetof(InterfaceStrings, faderData) == 0x8);
	static_assert(offsetof(InterfaceStrings, hudData) == 0x10);
	static_assert(offsetof(InterfaceStrings, hudCameraData) == 0x18);
	static_assert(offsetof(InterfaceStrings, floatingQuestMarkers) == 0x20);
	static_assert(offsetof(InterfaceStrings, consoleData) == 0x28);
	static_assert(offsetof(InterfaceStrings, quantityData) == 0x30);
	static_assert(offsetof(InterfaceStrings, messageBoxData) == 0x38);
	static_assert(offsetof(InterfaceStrings, uiScaleformData) == 0x40);
	static_assert(offsetof(InterfaceStrings, uiMessageData) == 0x48);
	static_assert(offsetof(InterfaceStrings, uiAnalogData) == 0x50);
	static_assert(offsetof(InterfaceStrings, inventoryUpdateData) == 0x58);
	static_assert(offsetof(InterfaceStrings, referenceHandleUIData) == 0x60);
	static_assert(offsetof(InterfaceStrings, formUIData) == 0x68);
	static_assert(offsetof(InterfaceStrings, loadingMenuData) == 0x70);
	static_assert(offsetof(InterfaceStrings, kinectStateChangeData) == 0x78);
	static_assert(offsetof(InterfaceStrings, kinectUserEventData) == 0x80);
	static_assert(offsetof(InterfaceStrings, inventoryMenu) == 0x88);
	static_assert(offsetof(InterfaceStrings, console) == 0x90);
	static_assert(offsetof(InterfaceStrings, dialogueMenu) == 0x98);
	static_assert(offsetof(InterfaceStrings, hudMenu) == 0xA0);
	static_assert(offsetof(InterfaceStrings, mainMenu) == 0xA8);
	static_assert(offsetof(InterfaceStrings, messageBoxMenu) == 0xB0);
	static_assert(offsetof(InterfaceStrings, cursorMenu) == 0xB8);
	static_assert(offsetof(InterfaceStrings, faderMenu) == 0xC0);
	static_assert(offsetof(InterfaceStrings, magicMenu) == 0xC8);
	static_assert(offsetof(InterfaceStrings, topMenu) == 0xD0);
	static_assert(offsetof(InterfaceStrings, overlayMenu) == 0xD8);
	static_assert(offsetof(InterfaceStrings, overlayInteractionMenu) == 0xE0);
	static_assert(offsetof(InterfaceStrings, loadingMenu) == 0xE8);
	static_assert(offsetof(InterfaceStrings, tweenMenu) == 0xF0);
	static_assert(offsetof(InterfaceStrings, barterMenu) == 0xF8);
	static_assert(offsetof(InterfaceStrings, giftMenu) == 0x100);
	static_assert(offsetof(InterfaceStrings, debugTextMenu) == 0x108);
	static_assert(offsetof(InterfaceStrings, mapMenu) == 0x110);
	static_assert(offsetof(InterfaceStrings, lockpickingMenu) == 0x118);
	static_assert(offsetof(InterfaceStrings, quantityMenu) == 0x120);
	static_assert(offsetof(InterfaceStrings, statisticsMenu) == 0x128);
	static_assert(offsetof(InterfaceStrings, containerMenu) == 0x130);
	static_assert(offsetof(InterfaceStrings, sleepWaitMenu) == 0x138);
	static_assert(offsetof(InterfaceStrings, levelUpMenu) == 0x140);
	static_assert(offsetof(InterfaceStrings, journalMenu) == 0x148);
	static_assert(offsetof(InterfaceStrings, bookMenu) == 0x150);
	static_assert(offsetof(InterfaceStrings, favoritesMenu) == 0x158);
	static_assert(offsetof(InterfaceStrings, raceSexMenu) == 0x160);
	static_assert(offsetof(InterfaceStrings, craftingMenu) == 0x168);
	static_assert(offsetof(InterfaceStrings, trainingMenu) == 0x170);
	static_assert(offsetof(InterfaceStrings, mistMenu) == 0x178);
	static_assert(offsetof(InterfaceStrings, tutorialMenu) == 0x180);
	static_assert(offsetof(InterfaceStrings, creditsMenu) == 0x188);
	static_assert(offsetof(InterfaceStrings, modManagerMenu) == 0x190);
	static_assert(offsetof(InterfaceStrings, creationClubMenu) == 0x198);
#ifdef SKYRIM_ANNIVERSARY_EDITION
	static_assert(offsetof(InterfaceStrings, marketplaceMenu) == 0x1A0);
#endif
	static_assert(offsetof(InterfaceStrings, titleSequenceMenu) == SKYRIM_RELOCATE(0x1A0, 0x1A8));
	static_assert(offsetof(InterfaceStrings, consoleNativeUIMenu) == SKYRIM_RELOCATE(0x1A8, 0x1B0));
	static_assert(offsetof(InterfaceStrings, kinectMenu) == SKYRIM_RELOCATE(0x1B0, 0x1B8));
	static_assert(offsetof(InterfaceStrings, loadWaitSpinner) == SKYRIM_RELOCATE(0x1B8, 0x1C0));
	static_assert(offsetof(InterfaceStrings, streamingInstallMenu) == SKYRIM_RELOCATE(0x1C0, 0x1C8));
	static_assert(offsetof(InterfaceStrings, textWidget) == SKYRIM_RELOCATE(0x1C8, 0x1D0));
	static_assert(offsetof(InterfaceStrings, buttonBarWidget) == SKYRIM_RELOCATE(0x1D0, 0x1D8));
	static_assert(offsetof(InterfaceStrings, graphWidget) == SKYRIM_RELOCATE(0x1D8, 0x1E0));
	static_assert(offsetof(InterfaceStrings, textureWidget) == SKYRIM_RELOCATE(0x1E0, 0x1E8));
	static_assert(offsetof(InterfaceStrings, uiMenuOK) == SKYRIM_RELOCATE(0x1E8, 0x1F0));
	static_assert(offsetof(InterfaceStrings, uiMenuCancel) == SKYRIM_RELOCATE(0x1F0, 0x1F8));
	static_assert(offsetof(InterfaceStrings, showText) == SKYRIM_RELOCATE(0x1F8, 0x200));
	static_assert(offsetof(InterfaceStrings, hideText) == SKYRIM_RELOCATE(0x200, 0x208));
	static_assert(offsetof(InterfaceStrings, showList) == SKYRIM_RELOCATE(0x208, 0x210));
	static_assert(offsetof(InterfaceStrings, voiceReady) == SKYRIM_RELOCATE(0x210, 0x218));
	static_assert(offsetof(InterfaceStrings, dmfoString) == SKYRIM_RELOCATE(0x218, 0x220));
	static_assert(offsetof(InterfaceStrings, showJournal) == SKYRIM_RELOCATE(0x220, 0x228));
	static_assert(offsetof(InterfaceStrings, journalSettingsSaved) == SKYRIM_RELOCATE(0x228, 0x230));
	static_assert(offsetof(InterfaceStrings, closeMenu) == SKYRIM_RELOCATE(0x230, 0x238));
	static_assert(offsetof(InterfaceStrings, closingAllMenus) == SKYRIM_RELOCATE(0x238, 0x240));
	static_assert(offsetof(InterfaceStrings, refreshMenu) == SKYRIM_RELOCATE(0x240, 0x248));
	static_assert(offsetof(InterfaceStrings, cancelLoading) == SKYRIM_RELOCATE(0x248, 0x250));
	static_assert(offsetof(InterfaceStrings, menuTextureDegradeEvent) == SKYRIM_RELOCATE(0x250, 0x258));
#ifdef SKYRIM_ANNIVERSARY_EDITION
	static_assert(offsetof(InterfaceStrings, userSettingsLoaded) == 0x260);
	static_assert(offsetof(InterfaceStrings, activityStarted) == 0x268);
#endif
	static_assert(offsetof(InterfaceStrings, diamondMarker) == SKYRIM_RELOCATE(0x258, 0x270));
	static_assert(sizeof(InterfaceStrings) == SKYRIM_RELOCATE(0x260, 0x278));
}
