#include "PrecompiledHeader.h"

#include "Events.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Relocation/Module.h"
#include "Shared/Skyrim/A/ActorEquipManager.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/I/InventoryChanges.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace PrioritizeStolenItems
{
	bool Events::Register()
	{
		if (!Patterns::Events::AddItem() ||
			!Patterns::Events::DropItem() ||
			!Patterns::Events::GetExtraDataListToAddItem() ||
			!Patterns::Events::GetExtraDataListToDropItem() ||
			!Patterns::Events::GetExtraDataListToRemoveItem() ||
			!Patterns::Events::GetExtraDataListToSellItem() ||
			!Patterns::Events::GetIngredient() ||
			!Patterns::Events::RemoveIngredient() ||
			!Patterns::Events::RemoveItem() ||
			!Patterns::Events::SellItem())
		{
			return false;
		}

		// IsOwnedBy
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Events::IsOwnedBy, reinterpret_cast<std::uintptr_t>(std::addressof(Events::IsOwnedBy)));

		// RemoveComponent
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Events::RemoveComponent, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveComponent)));

		// AddItem
		Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Events::GetExtraDataListToAddItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));
		Utility::Trampoline::GetSingleton().RelativeCall6(Addresses::Events::AddItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::AddItem)));

		// DropItem
		Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Events::GetExtraDataListToDropItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));
		Utility::Trampoline::GetSingleton().RelativeCall6(Addresses::Events::DropItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::DropItem)));

		// RemoveItem
		Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Events::GetExtraDataListToRemoveItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));

#ifdef SKYRIM_ANNIVERSARY_EDITION
		Utility::Trampoline::GetSingleton().RelativeCall6(Addresses::Events::RemoveItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveItem)));
#else
		// Mimic a virtual function table
		static auto* removeItem{ std::addressof(Events::RemoveItem) };

		Utility::Memory::SafeWrite(Addresses::Events::RemoveItem, 0x48ui8, 0xBEui8, reinterpret_cast<std::uint64_t>(std::addressof(removeItem))); // mov rsi, std::addressof(removeItem)
#endif

		// SellItem
		Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Events::GetExtraDataListToSellItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));
		Utility::Trampoline::GetSingleton().RelativeCall6(Addresses::Events::SellItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveItem)));

		// RemoveIngredient
		Utility::Memory::SafeWrite(Addresses::Events::GetIngredient, 0x4Cui8, 0x8Bui8, 0xC7ui8); // mov r8, rdi

		Utility::Trampoline::GetSingleton().RelativeCall6(Addresses::Events::RemoveIngredient, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveIngredient)));

		return true;
	}

	std::uint32_t& Events::AddItem(Skyrim::TESObjectREFR* reference, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject*, std::uint32_t itemCount, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation)
	{
		result = Events::HandleItem(inventoryEntryData, itemCount, true,
			[reference, reason, moveToReference, position, rotation](Skyrim::TESBoundObject* item, std::uint32_t itemCount, Skyrim::ExtraDataList* extraDataList) -> Skyrim::ObjectReferenceHandle
			{
				return reference->RemoveItem(item, itemCount, reason, extraDataList, moveToReference, position, rotation);
			});

		return reinterpret_cast<std::uint32_t&>(result);
	}

	std::uint32_t& Events::DropItem(Skyrim::Actor* actor, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject*, Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation)
	{
		result = Events::HandleItem(inventoryEntryData, itemCount, false,
			[actor, position, rotation](Skyrim::TESBoundObject* item, std::uint32_t itemCount, Skyrim::ExtraDataList* extraDataList) -> Skyrim::ObjectReferenceHandle
			{
				return actor->DropItem(item, extraDataList, itemCount, position, rotation);
			});

		return reinterpret_cast<std::uint32_t&>(result);
	}

	Skyrim::ObjectReferenceHandle Events::HandleItem(Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, bool remainEquipped, std::function<Skyrim::ObjectReferenceHandle(Skyrim::TESBoundObject* item, std::uint32_t itemCount, Skyrim::ExtraDataList* extraDataList)> handleItem)
	{
		auto* extraDataLists = inventoryEntryData->extraDataLists;

		if (extraDataLists)
		{
			std::priority_queue<std::pair<Events::Priority, Skyrim::ExtraDataList*>> priorityQueue{};

			for (auto* extraDataList : *extraDataLists)
			{
				if (!extraDataList)
				{
					break;
				}

				Utility::Enumeration<Events::Priority> priority(Events::Priority::kNone);

				if (!extraDataList->IsWorn(true, false))
				{
					priority.set(Events::Priority::kUnequipped);
				}

				auto* owner = extraDataList->GetOwner();

				if (!inventoryEntryData->IsOwnedBy(Skyrim::PlayerCharacter::GetSingleton(), owner, true))
				{
					priority.set(Events::Priority::kStolen);
				}

				priorityQueue.emplace(priority.get(), extraDataList);
			}

			auto handleAllItems = itemCount == inventoryEntryData->itemCountDelta;

			while (!priorityQueue.empty())
			{
				const auto& top           = priorityQueue.top();
				auto*       extraDataList = top.second;

				auto count = extraDataList->GetCount();

				if (count > 0)
				{
					Utility::Enumeration<Events::Priority> priority(top.first);
					/*
						Prioritize stolen items over owned items
						Preemptively unequip the item so that the intended stack of items is dropped or removed
						When unequipped the ExtraDataList will be destroyed if it contains no other BSExtraData
					*/
					if (remainEquipped || priority.all(Events::Priority::kUnequipped) || ((handleAllItems || priority.all(Events::Priority::kStolen)) && !Skyrim::ActorEquipManager::GetSingleton()->UnequipItem(Skyrim::PlayerCharacter::GetSingleton(), inventoryEntryData->item, extraDataList, 1, nullptr, false, false, false, false, nullptr)))
					{
						auto result = handleItem(inventoryEntryData->item, std::min(itemCount, static_cast<std::uint32_t>(count)), extraDataList);

						itemCount -= std::min(itemCount, static_cast<std::uint32_t>(count));

						if (itemCount == 0)
						{
							return result;
						}
					}
				}

				priorityQueue.pop();
			}
		}

		return handleItem(inventoryEntryData->item, itemCount, nullptr);
	}

	Skyrim::InventoryEntryData* Events::GetExtraDataList(Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, bool remainEquipped)
	{
		return inventoryEntryData;
	}

	bool Events::IsOwnedBy(Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::Actor* actor, bool defaultOwnership)
	{
		auto result{ defaultOwnership };

		auto* extraDataLists = inventoryEntryData->extraDataLists;

		if (extraDataLists)
		{
			for (auto* extraDataList : *extraDataLists)
			{
				if (!extraDataList)
				{
					break;
				}

				auto* owner = extraDataList->GetOwner();

				result = inventoryEntryData->IsOwnedBy(actor, owner, defaultOwnership);

				if (!result)
				{
					break;
				}
			}
		}

		return result;
	}

	std::uint32_t Events::RemoveComponent(Skyrim::TESBoundObject* item, std::int32_t itemCount)
	{
		auto* player           = Skyrim::PlayerCharacter::GetSingleton();
		auto* inventoryChanges = player->GetInventoryChanges();

		if (inventoryChanges)
		{
			auto* inventoryEntryData = inventoryChanges->GetInventoryEntryData(item);

			if (inventoryEntryData)
			{
				Events::HandleItem(inventoryEntryData, std::abs(itemCount), false,
					[player](Skyrim::TESBoundObject* item, std::uint32_t itemCount, Skyrim::ExtraDataList* extraDataList) -> Skyrim::ObjectReferenceHandle
					{
						return player->RemoveItem(item, itemCount, Skyrim::TESObjectREFR::RemoveItemReason::kRemove, extraDataList, nullptr, nullptr, nullptr);
					});

				return 1;
			}
		}

		player->RemoveItem(item, std::abs(itemCount), Skyrim::TESObjectREFR::RemoveItemReason::kRemove, nullptr, nullptr, nullptr, nullptr);

		return 1;
	}

	std::uint32_t& Events::RemoveIngredient(Skyrim::TESObjectREFR* reference, Skyrim::ObjectReferenceHandle& result, Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Skyrim::ExtraDataList*, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation)
	{
		result = Events::HandleItem(inventoryEntryData, itemCount, false,
			[reference, reason, moveToReference, position, rotation](Skyrim::TESBoundObject* item, std::uint32_t itemCount, Skyrim::ExtraDataList* extraDataList) -> Skyrim::ObjectReferenceHandle
			{
				return reference->RemoveItem(item, itemCount, reason, extraDataList, moveToReference, position, rotation);
			});

		return reinterpret_cast<std::uint32_t&>(result);
	}

	/*
		RemoveItem
		SellItem
	*/
	std::uint32_t& Events::RemoveItem(Skyrim::TESObjectREFR* reference, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject*, std::uint32_t itemCount, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation)
	{
		result = Events::HandleItem(inventoryEntryData, itemCount, false,
			[reference, reason, moveToReference, position, rotation](Skyrim::TESBoundObject* item, std::uint32_t itemCount, Skyrim::ExtraDataList* extraDataList) -> Skyrim::ObjectReferenceHandle
			{
				return reference->RemoveItem(item, itemCount, reason, extraDataList, moveToReference, position, rotation);
			});

		return reinterpret_cast<std::uint32_t&>(result);
	}
}
