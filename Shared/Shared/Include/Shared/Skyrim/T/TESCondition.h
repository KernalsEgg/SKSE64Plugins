#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MemoryManager.h"



namespace Skyrim
{
	struct TESConditionItem;

	class TESObjectREFR;

	class TESCondition
	{
	public:
		SKYRIM_MEMORY_REDEFINE_NEW();

		TESCondition()                    = default;
		TESCondition(const TESCondition&) = delete;
		TESCondition(TESCondition&&)      = delete;

		~TESCondition();

		TESCondition& operator=(const TESCondition&) = delete;
		TESCondition& operator=(TESCondition&&)      = delete;

		// Member functions
		void Clear();
		bool IsTrue(TESObjectREFR* subject, TESObjectREFR* target) const;

		// Member variables
		TESConditionItem* head{ nullptr }; // 0
	};
	static_assert(offsetof(TESCondition, head) == 0x0);
	static_assert(sizeof(TESCondition) == 0x8);
}
