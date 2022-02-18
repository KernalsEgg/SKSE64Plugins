#pragma once

#include "PCH.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"



namespace ActorLimitFix::Fixes
{
	/*
	The original static array can hold 2 * (1 << 9) / 8 = 2 * 64 = 128 elements
	The replacement static array can hold 2 * (1 << 12) / 8 = 2 * 512 = 1024 elements
	*/
	class ReplaceStaticArray
	{
	public:
		static bool Fix();

	private:
		struct ActorDistance
		{
		public:
			Skyrim::ActorHandle actorHandle{};     // 0
			float               distanceSquared{}; // 4
		};
		static_assert(offsetof(ActorDistance, actorHandle) == 0x0);
		static_assert(offsetof(ActorDistance, distanceSquared) == 0x4);
		static_assert(sizeof(ActorDistance) == 0x8);

		static ActorDistance actorDistanceArray_[0x400]; // 2 * 0x200
	};
}
