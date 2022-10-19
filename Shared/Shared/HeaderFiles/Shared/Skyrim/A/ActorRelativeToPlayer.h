#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"



namespace Skyrim
{
	struct ActorRelativeToPlayer
	{
	public:
		// Member variables
		ActorHandle actorHandle{};           // 0
		float       distanceSquared{ 0.0F }; // 4
	};
	static_assert(offsetof(ActorRelativeToPlayer, actorHandle) == 0x0);
	static_assert(offsetof(ActorRelativeToPlayer, distanceSquared) == 0x4);
	static_assert(sizeof(ActorRelativeToPlayer) == 0x8);
}
