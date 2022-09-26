#include "PrecompiledHeader.h"

#include "Patches/SoulGems.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Skyrim/T/TESSoulGem.h"
#include "Shared/Utility/Enumeration.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void SoulGems::Patch(bool& blackSoulGems, bool& underfilledSoulGems)
	{
		SoulGems::blackSoulGems_       = blackSoulGems;
		SoulGems::underfilledSoulGems_ = underfilledSoulGems;

		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::InventoryChanges::FindBestSoulGemVisitor::VirtualFunctionTable, 0x1, reinterpret_cast<std::uintptr_t>(std::addressof(SoulGems::Visit)));
	}

	Skyrim::InventoryChanges::IItemChangeVisitor::ReturnType SoulGems::Visit(Skyrim::InventoryChanges::FindBestSoulGemVisitor* findBestSoulGemVisitor, Skyrim::InventoryEntryData* inventoryEntryData)
	{
		// findBestSoulGemVisitor != nullptr
		// inventoryEntryData != nullptr

		auto* item = inventoryEntryData->item;

		if (item && item->formType == Skyrim::FormType::kSoulGem)
		{
			auto* soulGem = static_cast<Skyrim::TESSoulGem*>(item);

			if (soulGem->soul == Skyrim::SoulLevel::kNone)
			{
				auto soulGemCountDelta = inventoryEntryData->itemCountDelta;

				if (soulGemCountDelta)
				{
					auto* extraDataLists = inventoryEntryData->extraDataLists;

					// Check if there are any empty soul gems
					if (extraDataLists)
					{
						for (auto* extraDataList : *extraDataLists)
						{
							if (!extraDataList)
							{
								break;
							}

							if (extraDataList->GetSoulLevel() == Skyrim::SoulLevel::kNone)
							{
								break;
							}

							soulGemCountDelta -= extraDataList->GetCount();
						}
					}

					if (soulGemCountDelta > 0)
					{
						auto* target      = findBestSoulGemVisitor->target;
						auto  targetIsNPC = target->IsNPC();

						auto soulGemCanHoldNPCSoul = Utility::Enumeration<Skyrim::TESSoulGem::RecordFlags, std::uint32_t>(soulGem->recordFlags).all(Skyrim::TESSoulGem::RecordFlags::kCanHoldNPCSoul);

						if (SoulGems::blackSoulGems_ ? (targetIsNPC && soulGemCanHoldNPCSoul) || (!targetIsNPC && !soulGemCanHoldNPCSoul) : !targetIsNPC || soulGemCanHoldNPCSoul)
						{
							auto targetSoulLevelValue  = Skyrim::TESSoulGem::GetSoulLevelValue(target->GetSoulLevel());
							auto soulGemSoulLevelValue = Skyrim::TESSoulGem::GetSoulLevelValue(soulGem->capacity.get());

							if (SoulGems::underfilledSoulGems_ ? soulGemSoulLevelValue == targetSoulLevelValue : soulGemSoulLevelValue >= targetSoulLevelValue)
							{
								auto* bestSoulGem               = findBestSoulGemVisitor->bestSoulGem;
								auto  bestSoulGemSoulLevelValue = bestSoulGem ?
                                                                      std::make_optional(Skyrim::TESSoulGem::GetSoulLevelValue(bestSoulGem->capacity.get())) :
                                                                      std::nullopt;
								auto  bestSoulGemCanHoldNPCSoul = bestSoulGem ?
                                                                      std::make_optional(Utility::Enumeration<Skyrim::TESSoulGem::RecordFlags, std::uint32_t>(bestSoulGem->recordFlags).all(Skyrim::TESSoulGem::RecordFlags::kCanHoldNPCSoul)) :
                                                                      std::nullopt;

								if (!bestSoulGem || bestSoulGemSoulLevelValue.value() > soulGemSoulLevelValue ||
									(!targetIsNPC && bestSoulGemSoulLevelValue.value() == soulGemSoulLevelValue && bestSoulGemCanHoldNPCSoul.value() && !soulGemCanHoldNPCSoul))
								{
									findBestSoulGemVisitor->bestSoulGem = soulGem;

									return soulGemSoulLevelValue == targetSoulLevelValue && (targetIsNPC || !soulGemCanHoldNPCSoul) ?
                                               Skyrim::InventoryChanges::IItemChangeVisitor::ReturnType::kStop :
                                               Skyrim::InventoryChanges::IItemChangeVisitor::ReturnType::kContinue;
								}
							}
						}
					}
				}
			}
		}

		return Skyrim::InventoryChanges::IItemChangeVisitor::ReturnType::kContinue;
	}

	bool SoulGems::blackSoulGems_;
	bool SoulGems::underfilledSoulGems_;
}
