#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTSingleton.h"



namespace Skyrim
{
	class Actor;
	class BGSEquipSlot;
	class ExtraDataList;
	class TESBoundObject;

	class ActorEquipManager :
		public BSTSingletonSDM<ActorEquipManager> // 0
	{
	public:
		// Non-member functions
		static ActorEquipManager* GetSingleton();

		// Member functions
		void EquipBoundObject(Actor* actor, TESBoundObject* boundObject, ExtraDataList* extraDataList, std::uint32_t boundObjectCount, BGSEquipSlot* equipSlot, bool queueEquip, bool forceEquip, bool playSounds, bool applyNow);
		bool UnequipBoundObject(Actor* actor, TESBoundObject* boundObject, ExtraDataList* extraDataList, std::uint32_t boundObjectCount, BGSEquipSlot* equipSlot, bool queueEquip, bool forceEquip, bool playSounds, bool applyNow, BGSEquipSlot* replacementEquipSlot);

		// Member variables
		bool initialized; // 1
	};
	static_assert(offsetof(ActorEquipManager, initialized) == 0x1);
	static_assert(sizeof(ActorEquipManager) == 0x2);
}
