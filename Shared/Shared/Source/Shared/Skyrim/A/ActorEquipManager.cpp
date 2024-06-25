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

	void ActorEquipManager::EquipBoundObject(Actor* actor, TESBoundObject* boundObject, ExtraDataList* extraDataList, std::uint32_t boundObjectCount, BGSEquipSlot* equipSlot, bool queueEquip, bool forceEquip, bool playSounds, bool applyNow)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ActorEquipManager::EquipBoundObject)>::type>(
			Addresses::ActorEquipManager::EquipBoundObject()) };

		function(this, actor, boundObject, extraDataList, boundObjectCount, equipSlot, queueEquip, forceEquip, playSounds, applyNow);
	}

	bool ActorEquipManager::UnequipBoundObject(Actor* actor, TESBoundObject* boundObject, ExtraDataList* extraDataList, std::uint32_t boundObjectCount, BGSEquipSlot* equipSlot, bool queueEquip, bool forceEquip, bool playSounds, bool applyNow, BGSEquipSlot* replacementEquipSlot)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ActorEquipManager::UnequipBoundObject)>::type>(
			Addresses::ActorEquipManager::UnequipBoundObject()) };

		return function(this, actor, boundObject, extraDataList, boundObjectCount, equipSlot, queueEquip, forceEquip, playSounds, applyNow, replacementEquipSlot);
	}
}
