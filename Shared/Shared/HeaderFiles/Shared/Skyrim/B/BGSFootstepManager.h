#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Skyrim/B/BSTSingleton.h"



namespace Skyrim
{
	struct BGSFootstepEvent;

	class BGSFootstepManager :
		public BSTEventSource<BGSFootstepEvent>,   // 0
		public BSTSingletonSDM<BGSFootstepManager> // 58
	{
	public:
		// Non-member functions
		static BGSFootstepManager* GetSingleton();

		// Member variables
		std::uint8_t  unknown59;
		std::uint16_t unknown5A;
		std::uint32_t unknown5C;
		std::uint64_t unknown60;
		std::uint64_t unknown68;
		std::uint64_t unknown70;
		std::uint64_t unknown78;
	};
	static_assert(sizeof(BGSFootstepManager) == 0x80);
}
