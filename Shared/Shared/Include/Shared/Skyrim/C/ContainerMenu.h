#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/G/GFxValue.h"
#include "Shared/Skyrim/I/IMenu.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	struct ItemCard;
	struct ItemList;

	class BottomBar;
	class ExtraDataList;
	class TESBoundObject;

	class ContainerMenu :
		public IMenu // 0
	{
	public:
		// Override
		virtual ~ContainerMenu() override; // 0

		// Override (IMenu)
		virtual void            Accept(CallbackProcessor* processor) override; // 1
		virtual UIMessageResult ProcessMessage(UIMessage& message) override;   // 4
		virtual void            Unknown6(IMenu*) override;                     // 6

		// Non-member functions
		static NiPointer<TESObjectREFR> GetTargetReference();
		static ObjectReferenceHandle    GetTargetReferenceHandle();

		// Member variables
		GFxValue        root;                  // 30
		ItemList*       itemList;              // 48
		ItemCard*       itemCard;              // 50
		BottomBar*      bottomBar;             // 58
		std::uint64_t   unknown60;             // 60
		std::uint64_t   unknown68;             // 68
		std::uint64_t   unknown70;             // 70
		std::uint64_t   unknown78;             // 78
		std::uint64_t   unknown80;             // 80
		std::uint64_t   unknown88;             // 88
		TESBoundObject* selectedBoundObject;   // 90
		ExtraDataList*  selectedExtraDataList; // 98
		std::uint32_t   selectedFilterFlag;    // A0
		std::uint32_t   paddingA4;             // A4
		std::uint64_t   unknownA8;             // A8
		std::uint64_t   unknownB0;             // B0
		std::uint8_t    unknownB8;             // B8
		bool            pcControlsReady;       // B9
		std::uint16_t   unknownBA;             // BA
		std::uint32_t   unknownBC;             // BC
	};
	static_assert(offsetof(ContainerMenu, root) == 0x30);
	static_assert(offsetof(ContainerMenu, itemList) == 0x48);
	static_assert(offsetof(ContainerMenu, itemCard) == 0x50);
	static_assert(offsetof(ContainerMenu, bottomBar) == 0x58);
	static_assert(offsetof(ContainerMenu, selectedBoundObject) == 0x90);
	static_assert(offsetof(ContainerMenu, selectedExtraDataList) == 0x98);
	static_assert(offsetof(ContainerMenu, selectedFilterFlag) == 0xA0);
	static_assert(offsetof(ContainerMenu, pcControlsReady) == 0xB9);
	static_assert(sizeof(ContainerMenu) == 0xC0);
}
