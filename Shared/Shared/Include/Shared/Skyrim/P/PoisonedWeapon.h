#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSTEventSource.h"



namespace Skyrim
{
	namespace PoisonedWeapon
	{
		struct Event
		{
		public:
			// Member variables
			ObjectReferenceHandle poisonHandle{}; // 0
		};
		static_assert(offsetof(Event, poisonHandle) == 0x0);
		static_assert(sizeof(Event) == 0x4);

		// Non-member functions
		static BSTEventSource<PoisonedWeapon::Event>* GetEventSource();
	}
}
