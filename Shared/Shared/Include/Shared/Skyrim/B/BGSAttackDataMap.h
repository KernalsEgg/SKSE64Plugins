#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSTHashMap.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/N/NiRefObject.h"



namespace Skyrim
{
	class BGSAttackData;
	class TESRace;

	class BGSAttackDataMap :
		public NiRefObject // 0
	{
	public:
		// Override
		virtual ~BGSAttackDataMap() override; // 0

		// Member variables
		BSTHashMap<BSFixedString, NiPointer<BGSAttackData>> attacks;    // 10
		TESRace*                                            attackRace; // 40
	};
	static_assert(offsetof(BGSAttackDataMap, attacks) == 0x10);
	static_assert(offsetof(BGSAttackDataMap, attackRace) == 0x40);
	static_assert(sizeof(BGSAttackDataMap) == 0x48);
}
