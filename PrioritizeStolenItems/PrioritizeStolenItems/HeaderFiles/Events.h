#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"
#include "Shared/Utility/Enumeration.h"



namespace PrioritizeStolenItems
{
	class Events
	{
	public:
		static bool Register();

	private:
		enum class Priority
		{
			kNone       = 0,
			kUnequipped = 1U << 0,
			kStolen     = 1U << 1
		};

		static std::uint32_t&                AddItem(Skyrim::TESObjectREFR* reference, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject* item, std::uint32_t itemCount, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation);
		static std::uint32_t&                DropItem(Skyrim::Actor* actor, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject* item, Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation);
		static Skyrim::InventoryEntryData*   GetExtraDataList(Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, bool remainEquipped);
		static Skyrim::ObjectReferenceHandle HandleItem(Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, bool remainEquipped, std::function<Skyrim::ObjectReferenceHandle(Skyrim::TESBoundObject* item, std::uint32_t itemCount, Skyrim::ExtraDataList* extraDataList)> handleItem);
		static bool                          IsOwnedBy(Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::Actor* actor, bool defaultOwnership);
		static std::uint32_t                 RemoveComponent(Skyrim::TESBoundObject* item, std::int32_t itemCount);
		static std::uint32_t&                RemoveIngredient(Skyrim::TESObjectREFR* reference, Skyrim::ObjectReferenceHandle& result, Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Skyrim::ExtraDataList* extraDataList, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation);
		static std::uint32_t&                RemoveItem(Skyrim::TESObjectREFR* reference, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject* item, std::uint32_t itemCount, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation);

		static decltype(&Events::IsOwnedBy) isOwnedBy_;
	};
}
