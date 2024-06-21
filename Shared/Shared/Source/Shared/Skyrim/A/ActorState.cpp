#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorState.h"



namespace Skyrim
{
	bool ActorState::IsSneaking() const
	{
		return this->actorState1.sneaking;
	}

	bool ActorState::IsSwimming() const
	{
		return this->actorState1.swimming;
	}
}
