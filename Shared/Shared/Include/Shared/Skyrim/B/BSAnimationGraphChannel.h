#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSIntrusiveRefCounted.h"



namespace Skyrim
{
	class BSAnimationGraphChannel :
		public BSIntrusiveRefCounted // 0
	{
	public:
		// Add
		virtual ~BSAnimationGraphChannel();                     // 0
		virtual void PollChannelUpdateImplementation(bool) = 0; // 1
		virtual void ResetImplementation()                 = 0; // 2

		// Member variables
		std::uint32_t paddingC;    // C
		BSFixedString channelName; // 10
		std::uint32_t value;       // 18
		std::uint32_t padding1C;   // 1C
	};
	static_assert(offsetof(BSAnimationGraphChannel, channelName) == 0x10);
	static_assert(offsetof(BSAnimationGraphChannel, value) == 0x18);
	static_assert(sizeof(BSAnimationGraphChannel) == 0x20);
}
