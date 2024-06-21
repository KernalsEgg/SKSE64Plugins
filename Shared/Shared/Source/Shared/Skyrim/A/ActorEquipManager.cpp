#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorEquipManager.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	ActorEquipManager* ActorEquipManager::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<ActorEquipManager**>(Addresses::ActorEquipManager::Singleton()) };

		return *singleton;
	}

	void ActorEquipManager::EquipItem(Actor* actor, TESBoundObject* item, ExtraDataList* extraDataList, std::uint32_t itemCount, BGSEquipSlot* equipSlot, bool queueEquip, bool forceEquip, bool playSounds, bool applyNow)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ActorEquipManager::EquipItem)>::type>(
			Addresses::ActorEquipManager::EquipItem()) };

		function(this, actor, item, extraDataList, itemCount, equipSlot, queueEquip, forceEquip, playSounds, applyNow);
	}

	bool ActorEquipManager::UnequipItem(Actor* actor, TESBoundObject* item, ExtraDataList* extraDataList, std::uint32_t itemCount, BGSEquipSlot* equipSlot, bool queueEquip, bool forceEquip, bool playSounds, bool applyNow, BGSEquipSlot* replacementEquipSlot)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ActorEquipManager::UnequipItem)>::type>(
			Addresses::ActorEquipManager::UnequipItem()) };

		return function(this, actor, item, extraDataList, itemCount, equipSlot, queueEquip, forceEquip, playSounds, applyNow, replacementEquipSlot);
	}
}
