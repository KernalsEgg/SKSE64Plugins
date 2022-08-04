#include "PCH.h"

#include "Events.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/A/ActorEquipManager.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Enumeration.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace StolenItems
{
	bool Events::Register()
	{
		if (!Patterns::Events::RequestItemCardInformation::IsOwnedBy() ||
			!Patterns::Events::Add::GetExtraDataList() ||
			!Patterns::Events::Add::RemoveItem() ||
			!Patterns::Events::Drop::DropItem() ||
			!Patterns::Events::Drop::GetExtraDataList() ||
			!Patterns::Events::Remove::GetExtraDataList() ||
			!Patterns::Events::Remove::RemoveItem() ||
			!Patterns::Events::Sell::GetExtraDataList() ||
			!Patterns::Events::Sell::RemoveItem())
		{
			return false;
		}

		Events::isOwnedBy_ = reinterpret_cast<decltype(Events::isOwnedBy_)>(Utility::Memory::ReadRelativeCall(Addresses::Events::RequestItemCardInformation::IsOwnedBy));

		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::RequestItemCardInformation::IsOwnedBy, reinterpret_cast<std::uintptr_t>(std::addressof(Events::IsOwnedBy)));

		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::Add::GetExtraDataList, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::Drop::GetExtraDataList, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::Remove::GetExtraDataList, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::Sell::GetExtraDataList, reinterpret_cast<std::uintptr_t>(std::addressof(Events::GetExtraDataList)));

		static auto* removeItem{ std::addressof(Events::RemoveItem) };

		Utility::Memory::SafeWrite(Addresses::Events::Remove::RemoveItem, 0x48ui8, 0xBEui8, reinterpret_cast<std::uint64_t>(std::addressof(removeItem))); // mov rsi, std::addressof(removeItem)

		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::Add::RemoveItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveItem)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::Drop::DropItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::DropItem)));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Events::Sell::RemoveItem, reinterpret_cast<std::uintptr_t>(std::addressof(Events::RemoveItem)));

		Utility::Memory::SafeWrite(Addresses::Events::Add::RemoveItem + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation1);
		Utility::Memory::SafeWrite(Addresses::Events::Drop::DropItem + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation1);
		Utility::Memory::SafeWrite(Addresses::Events::Sell::RemoveItem + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation1);

		return true;
	}

	std::uint32_t& Events::DropItem(Skyrim::Actor* actor, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject*, Events::Arguments* arguments, std::uint32_t, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation)
	{
		result = Events::HandleItem(arguments->inventoryEntryData, arguments->itemCount, arguments->remainEquipped,
			[actor, position, rotation](Skyrim::TESBoundObject* item, std::uint32_t itemCount, Skyrim::ExtraDataList* extraDataList) -> Skyrim::ObjectReferenceHandle
			{
				return actor->DropItem(item, extraDataList, itemCount, position, rotation);
			});

		delete arguments;

		return reinterpret_cast<std::uint32_t&>(result);
	}

	Skyrim::ObjectReferenceHandle Events::HandleItem(Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, bool remainEquipped, std::function<Skyrim::ObjectReferenceHandle(Skyrim::TESBoundObject*, std::uint32_t, Skyrim::ExtraDataList*)> handleItem)
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
					Prioritise dropping or removing stolen items over owned items
					Preemptively unequip the item so that the correct stack of items is dropped or removed
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

	Events::Arguments* Events::GetExtraDataList(Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, bool remainEquipped)
	{
		return new Events::Arguments{
			.inventoryEntryData = inventoryEntryData,
			.itemCount          = itemCount,
			.remainEquipped     = remainEquipped
		};
	}

	bool Events::IsOwnedBy(Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::Actor* actor, bool defaultOwnership)
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

				if (!Events::isOwnedBy_(std::addressof(temporary), actor, defaultOwnership))
				{
					return false;
				}
			}
		}

		return defaultOwnership;
	}

	std::uint32_t& Events::RemoveItem(Skyrim::TESObjectREFR* reference, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject*, std::uint32_t, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Events::Arguments* arguments, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation)
	{
		result = Events::HandleItem(arguments->inventoryEntryData, arguments->itemCount, arguments->remainEquipped,
			[reference, reason, moveToReference, position, rotation](Skyrim::TESBoundObject* item, std::uint32_t itemCount, Skyrim::ExtraDataList* extraDataList) -> Skyrim::ObjectReferenceHandle
			{
				return reference->RemoveItem(item, itemCount, reason, extraDataList, moveToReference, position, rotation);
			});

		delete arguments;

		return reinterpret_cast<std::uint32_t&>(result);
	}

	decltype(&Events::IsOwnedBy) Events::isOwnedBy_{ nullptr };
}
