#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSTSingleton.h"



namespace Skyrim
{
	class UserEvents :
		public BSTSingletonSDM<UserEvents> // 0
	{
	public:
		// Non-member functions
		static UserEvents* GetSingleton();

		// Member variables
		std::uint8_t  padding1;           // 1
		std::uint16_t padding2;           // 2
		std::uint32_t padding4;           // 4
		BSFixedString forward;            // 8, "Forward"
		BSFixedString back;               // 10, "Back"
		BSFixedString strafeLeft;         // 18, "Strafe Left"
		BSFixedString strafeRight;        // 20, "Strafe Right"
		BSFixedString move;               // 28, "Move"
		BSFixedString look;               // 30, "Look"
		BSFixedString activate;           // 38, "Activate"
		BSFixedString leftAttackBlock;    // 40, "Left Attack/Block"
		BSFixedString rightAttackBlock;   // 48, "Right Attack/Block"
		BSFixedString dualAttack;         // 50, "Dual Attack"
		BSFixedString forceRelease;       // 58, "ForceRelease"
		BSFixedString pause;              // 60, "Pause"
		BSFixedString readyWeapon;        // 68, "Ready Weapon"
		BSFixedString togglePOV;          // 70, "Toggle POV"
		BSFixedString jump;               // 78, "Jump"
		BSFixedString journal;            // 80, "Journal"
		BSFixedString sprint;             // 88, "Sprint"
		BSFixedString sneak;              // 90, "Sneak"
		BSFixedString shout;              // 98, "Shout"
		BSFixedString kinectShout;        // A0, "KinectShout"
		BSFixedString grab;               // A8, "Grab"
		BSFixedString run;                // B0, "Run"
		BSFixedString toggleAlwaysRun;    // B8, "Toggle Always Run"
		BSFixedString autoMove;           // C0, "Auto-Move"
		BSFixedString quickSave;          // C8, "Quicksave"
		BSFixedString quickLoad;          // D0, "Quickload"
		BSFixedString newSave;            // D8, "NewSave"
		BSFixedString inventory;          // E0, "Inventory"
		BSFixedString statistics;         // E8, "Stats"
		BSFixedString map;                // F0, "Map"
		BSFixedString screenshot;         // F8, "Screenshot"
		BSFixedString multipleScreenshot; // 100, "Multi-Screenshot"
		BSFixedString console;            // 108, "Console"
		BSFixedString cameraPath;         // 110, "CameraPath"
		BSFixedString tweenMenu;          // 118, "Tween Menu"
		BSFixedString takeAll;            // 120, "Take All"
		BSFixedString accept;             // 128, "Accept"
		BSFixedString cancel;             // 130, "Cancel"
		BSFixedString up;                 // 138, "Up"
		BSFixedString down;               // 140, "Down"
		BSFixedString left;               // 148, "Left"
		BSFixedString right;              // 150, "Right"
		BSFixedString pageUp;             // 158, "PageUp"
		BSFixedString pageDown;           // 160, "PageDown"
		BSFixedString pick;               // 168, "Pick"
		BSFixedString pickNext;           // 170, "PickNext"
		BSFixedString pickPrevious;       // 178, "PickPrevious"
		BSFixedString cursor;             // 180, "Cursor"
		BSFixedString kinect;             // 188, "Kinect"
		BSFixedString sprintStart;        // 190, "SprintStart"
		BSFixedString sprintStop;         // 198, "SprintStop"
		BSFixedString sneakStart;         // 1A0, "sneakStart"
		BSFixedString sneakStop;          // 1A8, "sneakStop"
		BSFixedString blockStart;         // 1B0, "blockStart"
		BSFixedString blockStop;          // 1B8, "blockStop"
		BSFixedString blockBash;          // 1C0, "blockBash"
		BSFixedString attackStart;        // 1C8, "attackStart"
		BSFixedString attackPowerStart;   // 1D0, "attackPowerStart"
		BSFixedString reverseDirection;   // 1D8, "reverseDirection"
		BSFixedString unequip;            // 1E0, "Unequip"
		BSFixedString zoomIn;             // 1E8, "Zoom In"
		BSFixedString zoomOut;            // 1F0, "Zoom Out"
		BSFixedString rotateItem;         // 1F8, "RotateItem"
		BSFixedString leftStick;          // 200, "Left Stick"
		BSFixedString previousPage;       // 208, "PrevPage"
		BSFixedString nextPage;           // 210, "NextPage"
		BSFixedString previousSubPage;    // 218, "PrevSubPage"
		BSFixedString nextSubPage;        // 220, "NextSubPage"
		BSFixedString leftEquip;          // 228, "LeftEquip"
		BSFixedString rightEquip;         // 230, "RightEquip"
		BSFixedString toggleFavorite;     // 238, "ToggleFavorite"
		BSFixedString favorites;          // 240, "Favorites"
		BSFixedString hotkey1;            // 248, "Hotkey1"
		BSFixedString hotkey2;            // 250, "Hotkey2"
		BSFixedString hotkey3;            // 258, "Hotkey3"
		BSFixedString hotkey4;            // 260, "Hotkey4"
		BSFixedString hotkey5;            // 268, "Hotkey5"
		BSFixedString hotkey6;            // 270, "Hotkey6"
		BSFixedString hotkey7;            // 278, "Hotkey7"
		BSFixedString hotkey8;            // 280, "Hotkey8"
		BSFixedString quickInventory;     // 288, "Quick Inventory"
		BSFixedString quickMagic;         // 290, "Quick Magic"
		BSFixedString quickStatistics;    // 298, "Quick Stats"
		BSFixedString quickMap;           // 2A0, "Quick Map"
		BSFixedString toggleCursor;       // 2A8, "ToggleCursor"
		BSFixedString wait;               // 2B0, "Wait"
		BSFixedString click;              // 2B8, "Click"
		BSFixedString mapLookMode;        // 2C0, "MapLookMode"
		BSFixedString equip;              // 2C8, "Equip"
		BSFixedString dropItem;           // 2D0, "DropItem"
		BSFixedString rotate;             // 2D8, "Rotate"
		BSFixedString nextFocus;          // 2E0, "NextFocus"
		BSFixedString previousFocus;      // 2E8, "PreviousFocus"
		BSFixedString setActiveQuest;     // 2F0, "SetActiveQuest"
		BSFixedString placePlayerMarker;  // 2F8, "PlacePlayerMarker"
		BSFixedString xButton;            // 300, "XButton"
		BSFixedString yButton;            // 308, "YButton"
		BSFixedString chargeItem;         // 310, "ChargeItem"
		BSFixedString empty;              // 318, ""
		BSFixedString playerPosition;     // 320, "PlayerPosition"
		BSFixedString localMap;           // 328, "LocalMap"
		BSFixedString localMapMoveMode;   // 330, "LocalMapMoveMode"
		BSFixedString itemZoom;           // 338, "Item Zoom"
	};
	static_assert(offsetof(UserEvents, forward) == 0x8);
	static_assert(offsetof(UserEvents, back) == 0x10);
	static_assert(offsetof(UserEvents, strafeLeft) == 0x18);
	static_assert(offsetof(UserEvents, strafeRight) == 0x20);
	static_assert(offsetof(UserEvents, move) == 0x28);
	static_assert(offsetof(UserEvents, look) == 0x30);
	static_assert(offsetof(UserEvents, activate) == 0x38);
	static_assert(offsetof(UserEvents, leftAttackBlock) == 0x40);
	static_assert(offsetof(UserEvents, rightAttackBlock) == 0x48);
	static_assert(offsetof(UserEvents, dualAttack) == 0x50);
	static_assert(offsetof(UserEvents, forceRelease) == 0x58);
	static_assert(offsetof(UserEvents, pause) == 0x60);
	static_assert(offsetof(UserEvents, readyWeapon) == 0x68);
	static_assert(offsetof(UserEvents, togglePOV) == 0x70);
	static_assert(offsetof(UserEvents, jump) == 0x78);
	static_assert(offsetof(UserEvents, journal) == 0x80);
	static_assert(offsetof(UserEvents, sprint) == 0x88);
	static_assert(offsetof(UserEvents, sneak) == 0x90);
	static_assert(offsetof(UserEvents, shout) == 0x98);
	static_assert(offsetof(UserEvents, kinectShout) == 0xA0);
	static_assert(offsetof(UserEvents, grab) == 0xA8);
	static_assert(offsetof(UserEvents, run) == 0xB0);
	static_assert(offsetof(UserEvents, toggleAlwaysRun) == 0xB8);
	static_assert(offsetof(UserEvents, autoMove) == 0xC0);
	static_assert(offsetof(UserEvents, quickSave) == 0xC8);
	static_assert(offsetof(UserEvents, quickLoad) == 0xD0);
	static_assert(offsetof(UserEvents, newSave) == 0xD8);
	static_assert(offsetof(UserEvents, inventory) == 0xE0);
	static_assert(offsetof(UserEvents, statistics) == 0xE8);
	static_assert(offsetof(UserEvents, map) == 0xF0);
	static_assert(offsetof(UserEvents, screenshot) == 0xF8);
	static_assert(offsetof(UserEvents, multipleScreenshot) == 0x100);
	static_assert(offsetof(UserEvents, console) == 0x108);
	static_assert(offsetof(UserEvents, cameraPath) == 0x110);
	static_assert(offsetof(UserEvents, tweenMenu) == 0x118);
	static_assert(offsetof(UserEvents, takeAll) == 0x120);
	static_assert(offsetof(UserEvents, accept) == 0x128);
	static_assert(offsetof(UserEvents, cancel) == 0x130);
	static_assert(offsetof(UserEvents, up) == 0x138);
	static_assert(offsetof(UserEvents, down) == 0x140);
	static_assert(offsetof(UserEvents, left) == 0x148);
	static_assert(offsetof(UserEvents, right) == 0x150);
	static_assert(offsetof(UserEvents, pageUp) == 0x158);
	static_assert(offsetof(UserEvents, pageDown) == 0x160);
	static_assert(offsetof(UserEvents, pick) == 0x168);
	static_assert(offsetof(UserEvents, pickNext) == 0x170);
	static_assert(offsetof(UserEvents, pickPrevious) == 0x178);
	static_assert(offsetof(UserEvents, cursor) == 0x180);
	static_assert(offsetof(UserEvents, kinect) == 0x188);
	static_assert(offsetof(UserEvents, sprintStart) == 0x190);
	static_assert(offsetof(UserEvents, sprintStop) == 0x198);
	static_assert(offsetof(UserEvents, sneakStart) == 0x1A0);
	static_assert(offsetof(UserEvents, sneakStop) == 0x1A8);
	static_assert(offsetof(UserEvents, blockStart) == 0x1B0);
	static_assert(offsetof(UserEvents, blockStop) == 0x1B8);
	static_assert(offsetof(UserEvents, blockBash) == 0x1C0);
	static_assert(offsetof(UserEvents, attackStart) == 0x1C8);
	static_assert(offsetof(UserEvents, attackPowerStart) == 0x1D0);
	static_assert(offsetof(UserEvents, reverseDirection) == 0x1D8);
	static_assert(offsetof(UserEvents, unequip) == 0x1E0);
	static_assert(offsetof(UserEvents, zoomIn) == 0x1E8);
	static_assert(offsetof(UserEvents, zoomOut) == 0x1F0);
	static_assert(offsetof(UserEvents, rotateItem) == 0x1F8);
	static_assert(offsetof(UserEvents, leftStick) == 0x200);
	static_assert(offsetof(UserEvents, previousPage) == 0x208);
	static_assert(offsetof(UserEvents, nextPage) == 0x210);
	static_assert(offsetof(UserEvents, previousSubPage) == 0x218);
	static_assert(offsetof(UserEvents, nextSubPage) == 0x220);
	static_assert(offsetof(UserEvents, leftEquip) == 0x228);
	static_assert(offsetof(UserEvents, rightEquip) == 0x230);
	static_assert(offsetof(UserEvents, toggleFavorite) == 0x238);
	static_assert(offsetof(UserEvents, favorites) == 0x240);
	static_assert(offsetof(UserEvents, hotkey1) == 0x248);
	static_assert(offsetof(UserEvents, hotkey2) == 0x250);
	static_assert(offsetof(UserEvents, hotkey3) == 0x258);
	static_assert(offsetof(UserEvents, hotkey4) == 0x260);
	static_assert(offsetof(UserEvents, hotkey5) == 0x268);
	static_assert(offsetof(UserEvents, hotkey6) == 0x270);
	static_assert(offsetof(UserEvents, hotkey7) == 0x278);
	static_assert(offsetof(UserEvents, hotkey8) == 0x280);
	static_assert(offsetof(UserEvents, quickInventory) == 0x288);
	static_assert(offsetof(UserEvents, quickMagic) == 0x290);
	static_assert(offsetof(UserEvents, quickStatistics) == 0x298);
	static_assert(offsetof(UserEvents, quickMap) == 0x2A0);
	static_assert(offsetof(UserEvents, toggleCursor) == 0x2A8);
	static_assert(offsetof(UserEvents, wait) == 0x2B0);
	static_assert(offsetof(UserEvents, click) == 0x2B8);
	static_assert(offsetof(UserEvents, mapLookMode) == 0x2C0);
	static_assert(offsetof(UserEvents, equip) == 0x2C8);
	static_assert(offsetof(UserEvents, dropItem) == 0x2D0);
	static_assert(offsetof(UserEvents, rotate) == 0x2D8);
	static_assert(offsetof(UserEvents, nextFocus) == 0x2E0);
	static_assert(offsetof(UserEvents, previousFocus) == 0x2E8);
	static_assert(offsetof(UserEvents, setActiveQuest) == 0x2F0);
	static_assert(offsetof(UserEvents, placePlayerMarker) == 0x2F8);
	static_assert(offsetof(UserEvents, xButton) == 0x300);
	static_assert(offsetof(UserEvents, yButton) == 0x308);
	static_assert(offsetof(UserEvents, chargeItem) == 0x310);
	static_assert(offsetof(UserEvents, empty) == 0x318);
	static_assert(offsetof(UserEvents, playerPosition) == 0x320);
	static_assert(offsetof(UserEvents, localMap) == 0x328);
	static_assert(offsetof(UserEvents, localMapMoveMode) == 0x330);
	static_assert(offsetof(UserEvents, itemZoom) == 0x338);
	static_assert(sizeof(UserEvents) == 0x340);
}
