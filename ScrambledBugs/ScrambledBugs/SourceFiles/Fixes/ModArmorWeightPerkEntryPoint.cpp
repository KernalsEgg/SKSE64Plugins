#include "PrecompiledHeader.h"

#include "Fixes/ModArmorWeightPerkEntryPoint.h"

#include "Addresses.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESContainer.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void ModArmorWeightPerkEntryPoint::Fix(bool& modArmorWeightPerkEntryPoint)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::ModArmorWeightPerkEntryPoint::GetInventoryWeight, reinterpret_cast<std::uintptr_t>(std::addressof(ModArmorWeightPerkEntryPoint::GetInventoryWeight)));

		ModArmorWeightPerkEntryPoint::applyPerkEntry_ = reinterpret_cast<decltype(ModArmorWeightPerkEntryPoint::applyPerkEntry_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::BGSEntryPointPerkEntry::VirtualFunctionTable, 0xA));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::BGSEntryPointPerkEntry::VirtualFunctionTable, 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(ModArmorWeightPerkEntryPoint::ApplyPerkEntry)));

		ModArmorWeightPerkEntryPoint::removePerkEntry_ = reinterpret_cast<decltype(ModArmorWeightPerkEntryPoint::removePerkEntry_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::BGSEntryPointPerkEntry::VirtualFunctionTable, 0xB));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::BGSEntryPointPerkEntry::VirtualFunctionTable, 0xB, reinterpret_cast<std::uintptr_t>(std::addressof(ModArmorWeightPerkEntryPoint::RemovePerkEntry)));
	}

	void ModArmorWeightPerkEntryPoint::ApplyPerkEntry(Skyrim::BGSEntryPointPerkEntry* entryPointPerkEntry, Skyrim::Actor* perkOwner)
	{
		ModArmorWeightPerkEntryPoint::applyPerkEntry_(entryPointPerkEntry, perkOwner);

		if (entryPointPerkEntry->entryPoint == Skyrim::BGSPerkEntry::EntryPoint::kModifyArmorWeight)
		{
			auto* inventoryChanges = perkOwner->GetInventoryChanges();

			if (inventoryChanges)
			{
				inventoryChanges->ResetWeight();
			}
		}
	}

	float ModArmorWeightPerkEntryPoint::GetInventoryWeight(Skyrim::InventoryChanges* inventoryChanges)
	{
		// inventoryChanges != nullptr

		if (inventoryChanges->currentInventoryWeight != -1.0F)
		{
			return inventoryChanges->currentInventoryWeight;
		}

		float inventoryWeight{ 0.0F };

		auto* owner      = inventoryChanges->owner;
		auto* ownerActor = owner && owner->formType == Skyrim::FormType::kActor ? static_cast<Skyrim::Actor*>(owner) : nullptr;
		auto* container  = owner ? owner->GetContainer() : nullptr;

		// TESContainer
		if (container)
		{
			for (auto* containerObject : *container)
			{
				auto* item = containerObject->object;

				if (item)
				{
					auto itemWeight = item->GetWeight();

					if (itemWeight > 0.0F)
					{
						auto* inventoryEntryData = inventoryChanges->GetInventoryEntryData(item);
						auto  itemCount          = containerObject->count;

						if (inventoryEntryData)
						{
							if (inventoryEntryData->IsQuestItem())
							{
								continue;
							}

							itemCount += inventoryEntryData->itemCountDelta;

							if (itemCount > 0)
							{
								if (ownerActor)
								{
									if (item->formType == Skyrim::FormType::kArmor)
									{
										if (inventoryEntryData->IsWorn(true, false))
										{
											auto armorWeight = itemWeight;

											Skyrim::BGSEntryPointPerkEntry::HandleEntryPoint(Skyrim::BGSPerkEntry::EntryPoint::kModifyArmorWeight, ownerActor, item, std::addressof(armorWeight));

											inventoryWeight += armorWeight;
											--itemCount;
										}
									}
								}
							}
						}

						inventoryWeight += itemCount * itemWeight;
					}
				}
			}
		}

		// InventoryChanges
		auto* inventoryEntryDataList = inventoryChanges->inventoryEntryDataList;

		if (inventoryEntryDataList)
		{
			for (auto* inventoryEntryData : *inventoryEntryDataList)
			{
				if (!inventoryEntryData)
				{
					break;
				}

				auto* item = inventoryEntryData->item;

				if (item)
				{
					if (container && container->HasItem(item))
					{
						continue;
					}

					if (inventoryEntryData->IsQuestItem())
					{
						continue;
					}

					auto itemWeight = item->GetWeight();

					if (itemWeight > 0.0F)
					{
						auto itemCount = inventoryEntryData->itemCountDelta;

						if (itemCount > 0)
						{
							if (ownerActor)
							{
								if (item->formType == Skyrim::FormType::kArmor)
								{
									if (inventoryEntryData->IsWorn(true, false))
									{
										auto armorWeight = itemWeight;

										Skyrim::BGSEntryPointPerkEntry::HandleEntryPoint(Skyrim::BGSPerkEntry::EntryPoint::kModifyArmorWeight, ownerActor, item, std::addressof(armorWeight));

										inventoryWeight += armorWeight;
										--itemCount;
									}
								}
							}

							inventoryWeight += itemCount * itemWeight;
						}
					}
				}
			}
		}

		inventoryChanges->currentInventoryWeight = inventoryWeight;

		if (ownerActor)
		{
			ownerActor->ModifyActorValue(Skyrim::ActorValue::kInventoryWeight, inventoryChanges->previousInventoryWeight, inventoryWeight - inventoryChanges->previousInventoryWeight, nullptr);
		}

		return inventoryChanges->currentInventoryWeight;
	}

	void ModArmorWeightPerkEntryPoint::RemovePerkEntry(Skyrim::BGSEntryPointPerkEntry* entryPointPerkEntry, Skyrim::Actor* perkOwner)
	{
		ModArmorWeightPerkEntryPoint::removePerkEntry_(entryPointPerkEntry, perkOwner);

		if (entryPointPerkEntry->entryPoint == Skyrim::BGSPerkEntry::EntryPoint::kModifyArmorWeight)
		{
			auto* inventoryChanges = perkOwner->GetInventoryChanges();

			if (inventoryChanges)
			{
				inventoryChanges->ResetWeight();
			}
		}
	}

	decltype(&ModArmorWeightPerkEntryPoint::ApplyPerkEntry)  ModArmorWeightPerkEntryPoint::applyPerkEntry_;
	decltype(&ModArmorWeightPerkEntryPoint::RemovePerkEntry) ModArmorWeightPerkEntryPoint::removePerkEntry_;
}
