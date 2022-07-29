#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace StolenItems
{
	class Events
	{
	public:
		static bool Register();

	private:
		static std::uint32_t          DropItem(Skyrim::PlayerCharacter* player, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject* item, Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation);
		static Skyrim::ExtraDataList* GetExtraDataList(Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, bool remainEquipped);
		static bool                   IsOwnedBy(Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::Actor* actor, bool defaultOwnership);
		static std::uint32_t          RemoveItem(Skyrim::PlayerCharacter* player, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject* item, std::uint32_t itemCount, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation);

		static decltype(&Events::IsOwnedBy) isOwnedBy_;
	};
}
