#include "PCH.h"

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



namespace StolenItems
{
	bool Events::Register()
	{
		if (!Patterns::Events::AddItem() ||
			!Patterns::Events::DisenchantItem() ||
			!Patterns::Events::DropItem() ||
			!Patterns::Events::GetExtraDataLists() ||
			!Patterns::Events::GetExtraDataListToAddItem() ||
			!Patterns::Events::GetExtraDataListToDropItem() ||
			!Patterns::Events::GetExtraDataListToRemoveItem() ||
			!Patterns::Events::GetExtraDataListToRemoveSoul() ||
			!Patterns::Events::GetExtraDataListToRemoveSoulGem() ||
			!Patterns::Events::GetExtraDataListToSellItem() ||
			!Patterns::Events::GetIngredientToRemove() ||
			!Patterns::Events::GetItemToDisenchant() ||
			!Patterns::Events::IsOwnedBy() ||
			!Patterns::Events::RemoveIngredient() ||
			!Patterns::Events::RemoveItem() ||
			!Patterns::Events::RemoveSoul() ||
			!Patterns::Events::RemoveSoulGem() ||
			!Patterns::Events::SellItem())
		{
			return false;
		}

		// IsOwnedBy
		Events::isOwnedBy_ = reinterpret_cast<decltype(Events::isOwnedBy_)>(Utility::Memory::ReadRelativeCall(Addresses::Events::IsOwnedBy));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::IsOwnedBy, reinterpret_cast<std::uintptr_t>(std::addressof(Events::IsOwnedBy)));

		// RemoveComponent
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Events::RemoveComponent, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveComponent)));

		// GetExtraDataList
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::GetExtraDataListToAddItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::GetExtraDataListToDropItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::GetExtraDataListToRemoveItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::GetExtraDataListToSellItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));

		// AddItem
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::AddItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::AddItem)));
		Utility::Memory::SafeWrite(Addresses::Events::AddItem + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation1);

		// DropItem
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::DropItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::DropItem)));
		Utility::Memory::SafeWrite(Addresses::Events::DropItem + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation1);

		// RemoveItem
		if (Relocation::Executable::GetSingleton().IsSpecialEdition())
		{
			static auto* removeItem{ std::addressof(Events::RemoveItem) };

			Utility::Memory::SafeWrite(Addresses::Events::RemoveItem, 0x48ui8, 0xBEui8, reinterpret_cast<std::uint64_t>(std::addressof(removeItem))); // mov rsi, std::addressof(removeItem)
		}
		else
		{
			Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::RemoveItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveItem)));
			Utility::Memory::SafeWrite(Addresses::Events::RemoveItem + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation1);
		}

		// SellItem
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::SellItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveItem)));
		Utility::Memory::SafeWrite(Addresses::Events::SellItem + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation1);

		// DisenchantItem
		Utility::Memory::SafeWrite(Addresses::Events::GetItemToDisenchant, 0x4Dui8, 0x8Bui8, 0xC6ui8); // mov r8, r14

		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::DisenchantItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::DisenchantItem)));
		Utility::Memory::SafeWrite(Addresses::Events::DisenchantItem + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation1);

		// RemoveIngredient
		Utility::Memory::SafeWrite(Addresses::Events::GetIngredientToRemove, 0x4Cui8, 0x8Bui8, 0xC7ui8); // mov r8, rdi

		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::RemoveIngredient, reinterpret_cast<std::uintptr_t>(std::addressof(Events::DisenchantItem)));
		Utility::Memory::SafeWrite(Addresses::Events::RemoveIngredient + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation1);

		// RemoveSoulGem
		Utility::Memory::SafeWrite(Addresses::Events::GetExtraDataLists, 0x48ui8, 0x8Bui8, 0xC8ui8, Utility::Assembly::NoOperation1); // mov rcx, rax
		Utility::Memory::SafeWrite(Addresses::Events::GetExtraDataListToRemoveSoul, Utility::Assembly::NoOperation3);                 // nop
		Utility::Memory::SafeWrite(Addresses::Events::GetExtraDataListToRemoveSoulGem, 0x48ui8, 0x8Bui8, 0xD1ui8);                    // mov rdx, rcx

		Events::removeSoul_ = reinterpret_cast<decltype(Events::removeSoul_)>(Utility::Memory::ReadRelativeCall(Addresses::Events::RemoveSoul));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::RemoveSoul, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveSoul)));

		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::RemoveSoulGem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveItem)));
		Utility::Memory::SafeWrite(Addresses::Events::RemoveSoulGem + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation1);

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

	/*
	DisenchantItem
	RemoveIngredient
	*/
	std::uint32_t& Events::DisenchantItem(Skyrim::TESObjectREFR* reference, Skyrim::ObjectReferenceHandle& result, Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Skyrim::ExtraDataList*, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation)
	{
		result = Events::HandleItem(inventoryEntryData, itemCount, false,
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

				Skyrim::InventoryEntryData temporary{};

				temporary.item           = inventoryEntryData->item;
				temporary.extraDataLists = new Skyrim::BSSimpleList<Skyrim::ExtraDataList*>();
				temporary.itemCountDelta = 1;

				temporary.extraDataLists->push_front(extraDataList);

				if (!temporary.IsOwnedBy(Skyrim::PlayerCharacter::GetSingleton(), true))
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
					Prioritise stolen items over owned items
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

				Skyrim::InventoryEntryData temporary{};

				temporary.item           = inventoryEntryData->item;
				temporary.extraDataLists = new Skyrim::BSSimpleList<Skyrim::ExtraDataList*>();
				temporary.itemCountDelta = 1;

				temporary.extraDataLists->push_front(extraDataList);

				result = Events::isOwnedBy_(std::addressof(temporary), actor, defaultOwnership);

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

	/*
	RemoveItem
	RemoveSoulGem
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

	void Events::RemoveSoul(Skyrim::InventoryEntryData* inventoryEntryData, Utility::Enumeration<Skyrim::SoulLevel, std::uint8_t> soulLevel)
	{
		auto* extraDataLists = inventoryEntryData->extraDataLists;

		if (extraDataLists)
		{
			for (auto* extraDataList : *extraDataLists)
			{
				if (!extraDataList)
				{
					break;
				}

				Skyrim::InventoryEntryData temporary{};

				temporary.item           = inventoryEntryData->item;
				temporary.extraDataLists = new Skyrim::BSSimpleList<Skyrim::ExtraDataList*>();
				temporary.itemCountDelta = 1;

				temporary.extraDataLists->push_front(extraDataList);

				if (!temporary.IsOwnedBy(Skyrim::PlayerCharacter::GetSingleton(), true))
				{
					Events::removeSoul_(extraDataList, soulLevel);

					return;
				}
			}

			Events::removeSoul_(extraDataLists->front(), soulLevel);

			return;
		}

		Events::removeSoul_(nullptr, soulLevel);
	}

	decltype(&Events::IsOwnedBy) Events::isOwnedBy_{ nullptr };
	void (*Events::removeSoul_)(Skyrim::ExtraDataList* extraDataList, Utility::Enumeration<Skyrim::SoulLevel, std::uint8_t> soulLevel){ nullptr };
}
