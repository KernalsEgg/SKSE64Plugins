#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/C/CombatController.h"

#include "Shared/Skyrim/C/CombatState.h"



namespace Skyrim
{
	void CombatController::DamagedByAttacker(Actor* attacker, float damage)
	{
		this->combatState->DamagedByAttacker(attacker, damage);
	}
}
