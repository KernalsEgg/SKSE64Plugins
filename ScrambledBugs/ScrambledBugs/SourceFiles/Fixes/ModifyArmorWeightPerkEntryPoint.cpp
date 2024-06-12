#include "PrecompiledHeader.h"

#include "Fixes/ModifyArmorWeightPerkEntryPoint.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void ModifyArmorWeightPerkEntryPoint::Fix(bool& modifyArmorWeightPerkEntryPoint)
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Addresses::Fixes::ModifyArmorWeightPerkEntryPoint::GetInventoryWeight,
			reinterpret_cast<std::uintptr_t>(std::addressof(ModifyArmorWeightPerkEntryPoint::GetInventoryWeight)));

		ModifyArmorWeightPerkEntryPoint::applyPerkEntry_  = reinterpret_cast<decltype(ModifyArmorWeightPerkEntryPoint::applyPerkEntry_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::BGSEntryPointPerkEntry::VirtualFunctionTable(), 0xA));
		ModifyArmorWeightPerkEntryPoint::removePerkEntry_ = reinterpret_cast<decltype(ModifyArmorWeightPerkEntryPoint::removePerkEntry_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::BGSEntryPointPerkEntry::VirtualFunctionTable(), 0xB));

		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::BGSEntryPointPerkEntry::VirtualFunctionTable(), 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(ModifyArmorWeightPerkEntryPoint::ApplyPerkEntry)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::BGSEntryPointPerkEntry::VirtualFunctionTable(), 0xB, reinterpret_cast<std::uintptr_t>(std::addressof(ModifyArmorWeightPerkEntryPoint::RemovePerkEntry)));
	}

	void ModifyArmorWeightPerkEntryPoint::ApplyPerkEntry(Skyrim::BGSEntryPointPerkEntry* entryPointPerkEntry, Skyrim::Actor* perkOwner)
	{
		ModifyArmorWeightPerkEntryPoint::applyPerkEntry_(entryPointPerkEntry, perkOwner);

		if (entryPointPerkEntry->entryPoint == Skyrim::BGSEntryPoint::EntryPoint::kModifyArmorWeight)
		{
			auto* inventoryChanges = perkOwner->GetInventoryChanges();

			if (inventoryChanges)
			{
				inventoryChanges->ResetWeight();
			}
		}
	}

	float ModifyArmorWeightPerkEntryPoint::GetInventoryWeight(Skyrim::InventoryChanges* inventoryChanges)
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

		/* TESContainer */
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

											Skyrim::BGSEntryPoint::HandleEntryPoint(
												Skyrim::BGSEntryPoint::EntryPoint::kModifyArmorWeight,
												ownerActor,
												item,
												std::addressof(armorWeight));

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

		/* InventoryChanges */
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

										Skyrim::BGSEntryPoint::HandleEntryPoint(
											Skyrim::BGSEntryPoint::EntryPoint::kModifyArmorWeight,
											ownerActor,
											item,
											std::addressof(armorWeight));

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
			ownerActor->HandleActorValueModified(
				Skyrim::ActorValue::kInventoryWeight,
				inventoryChanges->previousInventoryWeight,
				inventoryWeight - inventoryChanges->previousInventoryWeight,
				nullptr);
		}

		return inventoryChanges->currentInventoryWeight;
	}

	void ModifyArmorWeightPerkEntryPoint::RemovePerkEntry(Skyrim::BGSEntryPointPerkEntry* entryPointPerkEntry, Skyrim::Actor* perkOwner)
	{
		ModifyArmorWeightPerkEntryPoint::removePerkEntry_(entryPointPerkEntry, perkOwner);

		if (entryPointPerkEntry->entryPoint == Skyrim::BGSEntryPoint::EntryPoint::kModifyArmorWeight)
		{
			auto* inventoryChanges = perkOwner->GetInventoryChanges();

			if (inventoryChanges)
			{
				inventoryChanges->ResetWeight();
			}
		}
	}

	decltype(ModifyArmorWeightPerkEntryPoint::ApplyPerkEntry)*  ModifyArmorWeightPerkEntryPoint::applyPerkEntry_{ nullptr };
	decltype(ModifyArmorWeightPerkEntryPoint::RemovePerkEntry)* ModifyArmorWeightPerkEntryPoint::removePerkEntry_{ nullptr };
}
