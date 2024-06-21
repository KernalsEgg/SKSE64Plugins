#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/C/CombatState.h"



namespace Skyrim
{
	void CombatState::DamagedByAttacker(Actor* attacker, float damage)
	{
		this->damagedByAttackerTimeStamp.timeStamp = AITimer::GetTimer();
	}
}
