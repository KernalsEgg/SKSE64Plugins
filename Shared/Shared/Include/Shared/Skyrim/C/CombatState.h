#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AITimer.h"
#include "Shared/Skyrim/A/AITimeStamp.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	struct UnreachableLocation;

	class Actor;
	class CombatThreat;

	class CombatState
	{
	public:
		// Member functions
		void DamagedByAttacker(Actor* attacker, float damage);

		// Member variables
		std::uint64_t                     unknown0;                     // 0
		std::uint64_t                     unknown8;                     // 8
		std::uint64_t                     unknown10;                    // 10
		std::uint64_t                     unknown18;                    // 18
		std::uint64_t                     unknown20;                    // 20
		AITimeStamp                       damagedByAttackerTimeStamp;   // 28
		AITimer                           combatDialogueAttackTimer;    // 2C
		AITimer                           combatDialogueTauntTimer;     // 34
		AITimer                           combatDialogueBleedoutTimer;  // 3C
		AITimer                           combatDialogueFleeTimer;      // 44
		std::uint32_t                     unknown4C;                    // 4C
		BSTArray<NiPointer<CombatThreat>> combatThreats;                // 50
		std::uint64_t                     unknown68;                    // 68
		std::uint64_t                     unknown70;                    // 70
		std::uint64_t                     unknown78;                    // 78
		BSTArray<UnreachableLocation>     unreachableLocations;         // 80
		std::uint64_t                     unknown98;                    // 98
		std::uint32_t                     unknownA0;                    // A0
		AITimer                           combatStrengthUpdateTimer;    // A4
		AITimer                           combatThreatRatioUpdateTimer; // AC
		AITimer                           combatThreatUpdateTimer;      // B4
	};
	static_assert(offsetof(CombatState, damagedByAttackerTimeStamp) == 0x28);
	static_assert(offsetof(CombatState, combatDialogueAttackTimer) == 0x2C);
	static_assert(offsetof(CombatState, combatDialogueTauntTimer) == 0x34);
	static_assert(offsetof(CombatState, combatDialogueBleedoutTimer) == 0x3C);
	static_assert(offsetof(CombatState, combatDialogueFleeTimer) == 0x44);
	static_assert(offsetof(CombatState, combatThreats) == 0x50);
	static_assert(offsetof(CombatState, unreachableLocations) == 0x80);
	static_assert(offsetof(CombatState, combatStrengthUpdateTimer) == 0xA4);
	static_assert(offsetof(CombatState, combatThreatRatioUpdateTimer) == 0xAC);
	static_assert(offsetof(CombatState, combatThreatUpdateTimer) == 0xB4);
	static_assert(sizeof(CombatState) == 0xC0);
}
