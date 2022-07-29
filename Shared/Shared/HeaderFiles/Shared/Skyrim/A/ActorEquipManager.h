#pragma once

#include "Shared/PCH.h"

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
		void EquipItem(Actor* actor, TESBoundObject* item, ExtraDataList* extraDataList, std::uint32_t itemCount, BGSEquipSlot* equipSlot, bool queueEquip, bool forceEquip, bool playSounds, bool applyNow);
		bool UnequipItem(Actor* actor, TESBoundObject* item, ExtraDataList* extraDataList, std::uint32_t itemCount, BGSEquipSlot* equipSlot, bool queueEquip, bool forceEquip, bool playSounds, bool applyNow, BGSEquipSlot* replacementEquipSlot);

		// Member variables
		bool initialized;
	};
	static_assert(offsetof(ActorEquipManager, initialized) == 0x1);
	static_assert(sizeof(ActorEquipManager) == 0x2);
}
