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

		if (container)
		{
			for (auto* containerObject : *container)
			{
				if (!containerObject)
				{
					break;
				}

				auto* boundObject = containerObject->boundObject;

				if (!boundObject)
				{
					continue;
				}

				auto* inventoryEntryData = inventoryChanges->GetInventoryEntryData(boundObject);

				if (inventoryEntryData && inventoryEntryData->IsQuestBoundObject())
				{
					continue;
				}

				auto boundObjectWeight = boundObject->GetWeight();

				if (boundObjectWeight <= 0.0F)
				{
					continue;
				}

				auto boundObjectCount = containerObject->count;

				if (inventoryEntryData)
				{
					boundObjectCount += inventoryEntryData->countDelta;
				}

				if (boundObjectCount <= 0)
				{
					continue;
				}

				if (ownerActor && boundObject->formType == Skyrim::FormType::kArmor && inventoryEntryData && inventoryEntryData->IsWorn(true, false))
				{
					auto* armor       = static_cast<Skyrim::TESObjectARMO*>(boundObject);
					auto  armorWeight = boundObjectWeight;

					Skyrim::BGSEntryPoint::HandleEntryPoint(Skyrim::BGSEntryPoint::EntryPoint::kModifyArmorWeight, ownerActor, armor, std::addressof(armorWeight));

					inventoryWeight += armorWeight;
					--boundObjectCount;
				}

				inventoryWeight += boundObjectWeight * boundObjectCount;
			}
		}

		auto* inventoryEntryDataList = inventoryChanges->inventoryEntryDataList;

		if (inventoryEntryDataList)
		{
			for (auto* inventoryEntryData : *inventoryEntryDataList)
			{
				if (!inventoryEntryData)
				{
					break;
				}

				auto* boundObject = inventoryEntryData->boundObject;

				if (!boundObject)
				{
					continue;
				}

				if (container && container->HasBoundObject(boundObject))
				{
					continue;
				}

				if (inventoryEntryData->IsQuestBoundObject())
				{
					continue;
				}

				auto boundObjectWeight = boundObject->GetWeight();

				if (boundObjectWeight <= 0.0F)
				{
					continue;
				}

				auto boundObjectCount = inventoryEntryData->countDelta;

				if (boundObjectCount <= 0)
				{
					continue;
				}

				if (ownerActor && boundObject->formType == Skyrim::FormType::kArmor && inventoryEntryData->IsWorn(true, false))
				{
					auto* armor       = static_cast<Skyrim::TESObjectARMO*>(boundObject);
					auto  armorWeight = boundObjectWeight;

					Skyrim::BGSEntryPoint::HandleEntryPoint(Skyrim::BGSEntryPoint::EntryPoint::kModifyArmorWeight, ownerActor, armor, std::addressof(armorWeight));

					inventoryWeight += armorWeight;
					--boundObjectCount;
				}

				inventoryWeight += boundObjectWeight * boundObjectCount;
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

	decltype(ModifyArmorWeightPerkEntryPoint::ApplyPerkEntry)*  ModifyArmorWeightPerkEntryPoint::applyPerkEntry_{ nullptr };
	decltype(ModifyArmorWeightPerkEntryPoint::RemovePerkEntry)* ModifyArmorWeightPerkEntryPoint::removePerkEntry_{ nullptr };
}
