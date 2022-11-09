#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class Actor;
	class CombatAimController;
	class CombatAreaStandard;
	class CombatBehaviorController;
	class CombatBlackboard;
	class CombatGroup;
	class CombatInventory;
	class CombatState;
	class CombatTargetSelectorStandard;
	class TESCombatStyle;

	class CombatController
	{
	public:
		// Member functions
		void DamagedByAttacker(Actor* attacker, float damage);

		// Member variables
		CombatGroup*                   combatGroup;              // 0
		CombatState*                   combatState;              // 8
		CombatInventory*               combatInventory;          // 10
		CombatBlackboard*              combatBlackboard;         // 18
		CombatBehaviorController*      combatBehaviorController; // 20
		ActorHandle                    actorHandle;              // 28
		ActorHandle                    targetHandle;             // 2C
		ActorHandle                    previousTargetHandle;     // 30
		std::uint8_t                   unknown34;                // 34
		bool                           startedCombat;            // 35
		std::uint16_t                  unknown36;                // 36
		TESCombatStyle*                combatStyle;              // 38
		bool                           stoppedCombat;            // 40
		std::uint8_t                   unknown41;                // 41
		bool                           ignoringCombat;           // 42
		bool                           inactive;                 // 43
		std::uint32_t                  unknown44;                // 44
		std::uint64_t                  unknown48;                // 48
		BSTArray<CombatAimController*> combatAimControllers;     // 50
#ifdef SKYRIM_ANNIVERSARY_EDITION
		mutable BSSpinLock combatAimControllerLock; // 68
#endif
		CombatAimController*                    currentCombatAimController;   // 68, 70
		CombatAimController*                    previousCombatAimController;  // 70, 78
		BSTArray<CombatAreaStandard*>           combatAreas;                  // 78, 80
		CombatAreaStandard*                     currentCombatAreas;           // 90, 98
		BSTArray<CombatTargetSelectorStandard*> combatTargetSelectors;        // 98, A0
		CombatTargetSelectorStandard*           currentCombatTargetSelector;  // B0, B8
		CombatTargetSelectorStandard*           previousCombatTargetSelector; // B8, C0
		std::uint32_t                           handleCount;                  // C0, C8
		std::uint32_t                           unknownCC;                    // C4, CC
		NiPointer<Actor>                        cachedActor;                  // C8, D0
		NiPointer<Actor>                        cachedTarget;                 // D0, D8
	};
	static_assert(offsetof(CombatController, combatGroup) == 0x0);
	static_assert(offsetof(CombatController, combatState) == 0x8);
	static_assert(offsetof(CombatController, combatInventory) == 0x10);
	static_assert(offsetof(CombatController, combatBlackboard) == 0x18);
	static_assert(offsetof(CombatController, combatBehaviorController) == 0x20);
	static_assert(offsetof(CombatController, actorHandle) == 0x28);
	static_assert(offsetof(CombatController, targetHandle) == 0x2C);
	static_assert(offsetof(CombatController, previousTargetHandle) == 0x30);
	static_assert(offsetof(CombatController, startedCombat) == 0x35);
	static_assert(offsetof(CombatController, combatStyle) == 0x38);
	static_assert(offsetof(CombatController, stoppedCombat) == 0x40);
	static_assert(offsetof(CombatController, ignoringCombat) == 0x42);
	static_assert(offsetof(CombatController, inactive) == 0x43);
	static_assert(offsetof(CombatController, combatAimControllers) == 0x50);
#ifdef SKYRIM_ANNIVERSARY_EDITION
	static_assert(offsetof(CombatController, combatAimControllerLock) == 0x68);
#endif
	static_assert(offsetof(CombatController, currentCombatAimController) == SKYRIM_RELOCATE(0x68, 0x70));
	static_assert(offsetof(CombatController, previousCombatAimController) == SKYRIM_RELOCATE(0x70, 0x78));
	static_assert(offsetof(CombatController, combatAreas) == SKYRIM_RELOCATE(0x78, 0x80));
	static_assert(offsetof(CombatController, currentCombatAreas) == SKYRIM_RELOCATE(0x90, 0x98));
	static_assert(offsetof(CombatController, combatTargetSelectors) == SKYRIM_RELOCATE(0x98, 0xA0));
	static_assert(offsetof(CombatController, currentCombatTargetSelector) == SKYRIM_RELOCATE(0xB0, 0xB8));
	static_assert(offsetof(CombatController, previousCombatTargetSelector) == SKYRIM_RELOCATE(0xB8, 0xC0));
	static_assert(offsetof(CombatController, handleCount) == SKYRIM_RELOCATE(0xC0, 0xC8));
	static_assert(offsetof(CombatController, cachedActor) == SKYRIM_RELOCATE(0xC8, 0xD0));
	static_assert(offsetof(CombatController, cachedTarget) == SKYRIM_RELOCATE(0xD0, 0xD8));
	static_assert(sizeof(CombatController) == SKYRIM_RELOCATE(0xD8, 0xE0));
}
