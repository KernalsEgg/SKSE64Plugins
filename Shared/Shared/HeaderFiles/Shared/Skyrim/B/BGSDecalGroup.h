#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSDecalManager.h"
#include "Shared/Skyrim/B/BSTArray.h"



namespace Skyrim
{
	struct BGSDecalGroup
	{
	public:
		// Member variables
		bool                                     permanentGroup; // 0
		bool                                     manualSaveLoad; // 1
		std::uint16_t                            padding2;       // 2
		std::uint32_t                            padding4;       // 4
		BSTArray<std::uint32_t>                  decalGroups;    // 8
		BSTArray<BGSDecalManager::CreationData*> pendingDecals;  // 20
	};
	static_assert(offsetof(BGSDecalGroup, permanentGroup) == 0x0);
	static_assert(offsetof(BGSDecalGroup, manualSaveLoad) == 0x1);
	static_assert(offsetof(BGSDecalGroup, decalGroups) == 0x8);
	static_assert(offsetof(BGSDecalGroup, pendingDecals) == 0x20);
	static_assert(sizeof(BGSDecalGroup) == 0x38);
}
