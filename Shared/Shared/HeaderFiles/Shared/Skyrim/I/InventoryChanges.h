#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSSimpleList.h"



namespace Skyrim
{
	class Actor;
	class ExtraDataList;
	class InventoryEntryData;
	class TESBoundObject;
	class TESObjectREFR;
	class TESSoulGem;

	class InventoryChanges
	{
	public:
		class IItemChangeVisitor
		{
		public:
			enum class ReturnType : std::uint32_t
			{
				kStop     = 0,
				kContinue = 1
			};
			static_assert(sizeof(ReturnType) == 0x4);

			// Add
			virtual ~IItemChangeVisitor();                                        // 0
			virtual ReturnType Visit(InventoryEntryData* inventoryEntryData) = 0; // 1
			virtual void       Unknown2(IItemChangeVisitor*);                     // 2
			virtual void       Unknown3(IItemChangeVisitor*);                     // 3
		};
		static_assert(sizeof(IItemChangeVisitor) == 0x8);

		class FindBestSoulGemVisitor :
			public IItemChangeVisitor // 0
		{
		public:
			// Override
			virtual ~FindBestSoulGemVisitor() override; // 0

			// Override (IItemChangeVisitor)
			virtual IItemChangeVisitor::ReturnType Visit(InventoryEntryData* inventoryEntryData) override; // 1

			// Member variables
			Actor*      target;      // 8
			TESSoulGem* bestSoulGem; // 10
		};
		static_assert(offsetof(FindBestSoulGemVisitor, target) == 0x8);
		static_assert(offsetof(FindBestSoulGemVisitor, bestSoulGem) == 0x10);
		static_assert(sizeof(FindBestSoulGemVisitor) == 0x18);

		// Member functions
		InventoryEntryData* GetInventoryEntryData(TESBoundObject* item) const;
		void                ResetWeight();

		// Member variables
		BSSimpleList<InventoryEntryData*>* inventoryEntryDataList;  // 0
		TESObjectREFR*                     owner;                   // 8
		float                              currentInventoryWeight;  // 10
		float                              previousInventoryWeight; // 14
		bool                               changed;                 // 18
		std::uint8_t                       padding19;               // 19
		std::uint16_t                      padding1A;               // 1A
		std::uint32_t                      padding1C;               // 1C
	};
	static_assert(offsetof(InventoryChanges, inventoryEntryDataList) == 0x0);
	static_assert(offsetof(InventoryChanges, owner) == 0x8);
	static_assert(offsetof(InventoryChanges, currentInventoryWeight) == 0x10);
	static_assert(offsetof(InventoryChanges, previousInventoryWeight) == 0x14);
	static_assert(offsetof(InventoryChanges, changed) == 0x18);
	static_assert(sizeof(InventoryChanges) == 0x20);
}
