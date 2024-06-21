#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTHashMap.h"
#include "Shared/Skyrim/N/NiRefObject.h"
#include "Shared/Skyrim/S/SetEventData.h"



namespace Skyrim
{
	class AttackAnimationArrayMap :
		public NiRefObject,                                             // 0
		public BSTHashMap<std::uint32_t, BSTArray<SetEventData> const*> // 10
	{
	public:
		// Override
		virtual ~AttackAnimationArrayMap() override; // 0
	};
	static_assert(sizeof(AttackAnimationArrayMap) == 0x40);
}
