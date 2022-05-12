#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkArray.h"
#include "Shared/Skyrim/H/hkpCollidable.h"



namespace Skyrim
{
	struct hkpAgentNnEntry;

	class hkpLinkedCollidable :
		public hkpCollidable // 0
	{
	public:
		struct CollisionEntry
		{
		public:
			// Member variables
			hkpAgentNnEntry*     agentEntry; // 0
			hkpLinkedCollidable* partner;    // 8
		};
		static_assert(offsetof(CollisionEntry, agentEntry) == 0x0);
		static_assert(offsetof(CollisionEntry, partner) == 0x8);
		static_assert(sizeof(CollisionEntry) == 0x10);

		// Member variables
		hkArray<CollisionEntry> collisionEntries; // 70
	};
	static_assert(offsetof(hkpLinkedCollidable, collisionEntries) == 0x70);
	static_assert(sizeof(hkpLinkedCollidable) == 0x80);
}
