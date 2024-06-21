#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/I/IDEvent.h"



namespace Skyrim
{
	class KinectEvent :
		public IDEvent // 0
	{
	public:
		// Override
		virtual ~KinectEvent() override; // 0

		// Member variables
		BSFixedString heard; // 28
	};
	static_assert(offsetof(KinectEvent, heard) == 0x28);
	static_assert(sizeof(KinectEvent) == 0x30);
}
