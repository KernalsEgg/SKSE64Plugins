#include "PCH.h"

#include "Events.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
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

	std::uint32_t Events::DropItem(Skyrim::PlayerCharacter* player, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject* item, Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation)
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

				auto count = extraDataList->GetCount();

				if (count < 1)
				{
					continue;
				}

				Skyrim::InventoryEntryData temporary{};

				temporary.item           = inventoryEntryData->item;
				temporary.extraDataLists = new Skyrim::BSSimpleList<Skyrim::ExtraDataList*>();
				temporary.extraDataLists->push_front(extraDataList);

				if (temporary.IsOwnedBy(player, true))
				{
					continue;
				}

				result = player->DropItem(item, extraDataList, static_cast<std::int64_t>(itemCount) > static_cast<std::int64_t>(count) ? count : itemCount, position, rotation);

				itemCount = static_cast<std::int64_t>(itemCount) > static_cast<std::int64_t>(count) ? itemCount - count : 0;

				if (itemCount < 1)
				{
					return result.native_handle();
				}
			}
		}

		result = player->DropItem(item, nullptr, itemCount, position, rotation);

		return result.native_handle();
	}

	Skyrim::ExtraDataList* Events::GetExtraDataList(Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, bool remainEquipped)
	{
		return static_cast<Skyrim::ExtraDataList*>(static_cast<void*>(inventoryEntryData));
	}

	bool Events::IsOwnedBy(Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::Actor* actor, bool defaultOwnership)
	{
		auto* extraDataLists = inventoryEntryData->extraDataLists;

		if (extraDataLists)
		{
			for (auto* extraDataList : *extraDataLists)
			{
				Skyrim::InventoryEntryData temporary{};

				temporary.item           = inventoryEntryData->item;
				temporary.extraDataLists = new Skyrim::BSSimpleList<Skyrim::ExtraDataList*>();
				temporary.extraDataLists->push_front(extraDataList);

				if (!Events::isOwnedBy_(std::addressof(temporary), actor, defaultOwnership))
				{
					return false;
				}
			}
		}

		return defaultOwnership;
	}

	std::uint32_t Events::RemoveItem(Skyrim::PlayerCharacter* player, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject* item, std::uint32_t itemCount, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation)
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

				auto count = extraDataList->GetCount();

				if (count < 1)
				{
					continue;
				}

				Skyrim::InventoryEntryData temporary{};

				temporary.item           = inventoryEntryData->item;
				temporary.extraDataLists = new Skyrim::BSSimpleList<Skyrim::ExtraDataList*>();
				temporary.extraDataLists->push_front(extraDataList);

				if (temporary.IsOwnedBy(player, true))
				{
					continue;
				}

				result = player->RemoveItem(item, static_cast<std::int64_t>(itemCount) > static_cast<std::int64_t>(count) ? count : itemCount, reason, extraDataList, moveToReference, position, rotation);

				itemCount = static_cast<std::int64_t>(itemCount) > static_cast<std::int64_t>(count) ? itemCount - count : 0;

				if (itemCount < 1)
				{
					return result.native_handle();
				}
			}
		}

		result = player->RemoveItem(item, itemCount, reason, nullptr, moveToReference, position, rotation);

		return result.native_handle();
	}

	decltype(&Events::IsOwnedBy) Events::isOwnedBy_{ nullptr };
}
