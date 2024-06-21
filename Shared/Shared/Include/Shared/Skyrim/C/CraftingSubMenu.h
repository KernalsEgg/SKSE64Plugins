#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/F/FxDelegateHandler.h"



namespace Skyrim
{
	struct TESFurnitureEvent;

	namespace CraftingSubMenus
	{
		class CraftingSubMenu :
			public FxDelegateHandler,              // 0
			public BSTEventSink<TESFurnitureEvent> // 10
		{
		public:
			// Override
			virtual ~CraftingSubMenu() override; // 0

			// Add
			virtual void Unknown2(CraftingSubMenu*); // 2
			virtual void Unknown3(CraftingSubMenu*); // 3
			virtual void Unknown4(CraftingSubMenu*); // 4
			virtual void Unknown5(CraftingSubMenu*); // 5
			virtual void Unknown6(CraftingSubMenu*); // 6
			virtual void Unknown7(CraftingSubMenu*); // 7

			// Override (BSTEventSink<TESFurnitureEvent>)
			virtual EventNotifyControl ProcessEvent(const TESFurnitureEvent* eventArguments, BSTEventSource<TESFurnitureEvent>* eventSource) override; // 1

			// Member variables
			std::uint64_t unknown18; // 18
			std::uint64_t unknown20; // 20
			std::uint64_t unknown28; // 28
			std::uint64_t unknown30; // 30
			std::uint64_t unknown38; // 38
			std::uint64_t unknown40; // 40
			std::uint64_t unknown48; // 48
			std::uint64_t unknown50; // 50
			std::uint64_t unknown58; // 58
			std::uint64_t unknown60; // 60
			std::uint64_t unknown68; // 68
			std::uint64_t unknown70; // 70
			std::uint64_t unknown78; // 78
			std::uint64_t unknown80; // 80
			std::uint64_t unknown88; // 88
			std::uint64_t unknown90; // 90
			std::uint64_t unknown98; // 98
			std::uint64_t unknownA0; // A0
			std::uint64_t unknownA8; // A8
			std::uint64_t unknownB0; // B0
			std::uint64_t unknownB8; // B8
			std::uint64_t unknownC0; // C0
			std::uint64_t unknownC8; // C8
			std::uint64_t unknownD0; // D0
			std::uint64_t unknownD8; // D8
			std::uint64_t unknownE0; // E0
			std::uint64_t unknownE8; // E8
			std::uint64_t unknownF0; // F0
			std::uint64_t unknownF8; // F8
		};
		static_assert(sizeof(CraftingSubMenu) == 0x100);
	}
}
