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
		enum class Priority
		{
			kNone       = 0,
			kUnequipped = 1U << 0,
			kStolen     = 1U << 1
		};

		struct Arguments
		{
		public:
			Skyrim::InventoryEntryData* inventoryEntryData;
			std::uint32_t               itemCount;
			bool                        remainEquipped;
		};

		static std::uint32_t&                DropItem(Skyrim::PlayerCharacter* player, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject* item, Events::Arguments* arguments, std::uint32_t itemCount, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation);
		static Events::Arguments*            GetExtraDataList(Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, bool remainEquipped);
		static Skyrim::ObjectReferenceHandle HandleItem(Skyrim::PlayerCharacter* player, Skyrim::InventoryEntryData* inventoryEntryData, std::uint32_t itemCount, bool remainEquipped, std::function<Skyrim::ObjectReferenceHandle(Skyrim::PlayerCharacter*, Skyrim::TESBoundObject*, Skyrim::ExtraDataList*, std::uint32_t)> handleItem);
		static bool                          IsOwnedBy(Skyrim::InventoryEntryData* inventoryEntryData, Skyrim::Actor* actor, bool defaultOwnership);
		static std::uint32_t&                RemoveItem(Skyrim::PlayerCharacter* player, Skyrim::ObjectReferenceHandle& result, Skyrim::TESBoundObject* item, std::uint32_t itemCount, Utility::Enumeration<Skyrim::TESObjectREFR::RemoveItemReason, std::uint32_t> reason, Events::Arguments* arguments, Skyrim::TESObjectREFR* moveToReference, const Skyrim::NiPoint3* position, const Skyrim::NiPoint3* rotation);

		static decltype(&Events::IsOwnedBy) isOwnedBy_;
	};
}
