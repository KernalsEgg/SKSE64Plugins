#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/HandleEntryPointVisitor.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/B/BGSPerkEntry.h"



namespace Skyrim
{
	PerkEntryVisitor::ReturnType HandleEntryPointVisitor::Visit(BGSPerkEntry* perkEntry)
	{
		if (perkEntry && perkEntry->CheckConditionFilters(this->conditionFilterArgumentCount, this->conditionFilterArguments))
		{
			BGSEntryPointFunction::ExecuteFunction(
				perkEntry->GetFunction(),
				this->perkOwner,
				this->entryPointFunctionType,
				this->entryPointFunctionTypeArgumentCount,
				this->entryPointFunctionTypeArguments,
				perkEntry->GetFunctionData());
		}

		return PerkEntryVisitor::ReturnType::kContinue;
	}

	HandleEntryPointVisitor::HandleEntryPointVisitor(
		Utility::Enumeration<BGSEntryPointFunction::EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
		TESForm**                                                                          conditionFilterArguments,
		void**                                                                             entryPointFunctionTypeArguments,
		Actor*                                                                             perkOwner,
		std::uint8_t                                                                       conditionFilterArgumentCount,
		std::uint8_t                                                                       entryPointFunctionTypeArgumentCount) :
		entryPointFunctionType(entryPointFunctionType),
		conditionFilterArguments(conditionFilterArguments),
		entryPointFunctionTypeArguments(entryPointFunctionTypeArguments),
		perkOwner(perkOwner),
		conditionFilterArgumentCount(conditionFilterArgumentCount),
		entryPointFunctionTypeArgumentCount(entryPointFunctionTypeArgumentCount)
	{
	}
}
