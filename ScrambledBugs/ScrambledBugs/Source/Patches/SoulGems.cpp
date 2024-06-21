#include "PrecompiledHeader.h"

#include "Patches/SoulGems.h"

#include "Shared/Utility/Enumeration.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void SoulGems::Patch(bool& black, bool& underfilled)
	{
		SoulGems::black_       = black;
		SoulGems::underfilled_ = underfilled;

		Utility::Memory::SafeWriteVirtualFunction(
			Skyrim::Addresses::InventoryChanges::FindBestSoulGemVisitor::VirtualFunctionTable(),
			0x1,
			reinterpret_cast<std::uintptr_t>(std::addressof(SoulGems::FunctionCallOperator)));
	}

	Skyrim::ForEachResult SoulGems::FunctionCallOperator(Skyrim::InventoryChanges::FindBestSoulGemVisitor* findBestSoulGemVisitor, Skyrim::InventoryEntryData* inventoryEntryData)
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

					/* Check if there are any empty soul gems */
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

						if (SoulGems::black_ ? (targetIsNPC && soulGemCanHoldNPCSoul) || (!targetIsNPC && !soulGemCanHoldNPCSoul) : !targetIsNPC || soulGemCanHoldNPCSoul)
						{
							auto targetSoulLevelValue  = Skyrim::TESSoulGem::GetSoulLevelValue(target->GetSoulLevel());
							auto soulGemSoulLevelValue = Skyrim::TESSoulGem::GetSoulLevelValue(soulGem->capacity.get());

							if (SoulGems::underfilled_ ? soulGemSoulLevelValue == targetSoulLevelValue : soulGemSoulLevelValue >= targetSoulLevelValue)
							{
								auto* bestSoulGem               = findBestSoulGemVisitor->bestSoulGem;
								auto  bestSoulGemSoulLevelValue = bestSoulGem ?
								                                      std::make_optional(Skyrim::TESSoulGem::GetSoulLevelValue(bestSoulGem->capacity.get())) :
								                                      std::nullopt;
								auto  bestSoulGemCanHoldNPCSoul = bestSoulGem ?
								                                      std::make_optional(Utility::Enumeration<Skyrim::TESSoulGem::RecordFlags, std::uint32_t>(bestSoulGem->recordFlags).all(Skyrim::TESSoulGem::RecordFlags::kCanHoldNPCSoul)) :
								                                      std::nullopt;

								if (!bestSoulGem ||
									bestSoulGemSoulLevelValue.value() > soulGemSoulLevelValue ||
									(!targetIsNPC && bestSoulGemSoulLevelValue.value() == soulGemSoulLevelValue && bestSoulGemCanHoldNPCSoul.value() && !soulGemCanHoldNPCSoul))
								{
									findBestSoulGemVisitor->bestSoulGem = soulGem;

									return soulGemSoulLevelValue == targetSoulLevelValue && (targetIsNPC || !soulGemCanHoldNPCSoul) ?
									           Skyrim::ForEachResult::kStop :
									           Skyrim::ForEachResult::kContinue;
								}
							}
						}
					}
				}
			}
		}

		return Skyrim::ForEachResult::kContinue;
	}

	bool SoulGems::black_{ false };
	bool SoulGems::underfilled_{ false };
}
