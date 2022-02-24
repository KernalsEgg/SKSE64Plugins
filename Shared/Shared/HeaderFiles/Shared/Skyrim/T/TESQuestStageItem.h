#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSLocalizedStringDL.h"
#include "Shared/Skyrim/T/TESCondition.h"



namespace Skyrim
{
	class TESQuest;
	class TESQuestStage;

	struct TESQuestStageItem
	{
	public:
		// Member variables
		TESCondition         conditions;       // 0
		TESQuest*            nextQuest;        // 8
		BGSLocalizedStringDL logEntry;         // 10
		std::uint32_t        unknown14;        // 14
		TESQuest*            owningQuest;      // 18
		TESQuestStage*       owningQuestStage; // 20
	};
	static_assert(offsetof(TESQuestStageItem, conditions) == 0x0);
	static_assert(offsetof(TESQuestStageItem, nextQuest) == 0x8);
	static_assert(offsetof(TESQuestStageItem, logEntry) == 0x10);
	static_assert(offsetof(TESQuestStageItem, owningQuest) == 0x18);
	static_assert(offsetof(TESQuestStageItem, owningQuestStage) == 0x20);
	static_assert(sizeof(TESQuestStageItem) == 0x28);
}
