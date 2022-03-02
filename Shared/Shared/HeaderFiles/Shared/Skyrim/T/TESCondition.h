#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	struct TESConditionItem;

	class TESObjectREFR;

	class TESCondition
	{
	public:
		bool IsTrue(TESObjectREFR* subject, TESObjectREFR* target) const;

		// Member variables
		TESConditionItem* head;
	};
	static_assert(offsetof(TESCondition, head) == 0x0);
	static_assert(sizeof(TESCondition) == 0x8);
}
