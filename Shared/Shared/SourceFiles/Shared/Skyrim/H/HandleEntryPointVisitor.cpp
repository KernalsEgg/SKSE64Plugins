#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/HandleEntryPointVisitor.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	ForEachResult HandleEntryPointVisitor::operator()(BGSPerkEntry* perkEntry)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&HandleEntryPointVisitor::operator())>::type>(Utility::Memory::ReadVirtualFunction(Addresses::HandleEntryPointVisitor::VirtualFunctionTable, 0x0)) };

		return function(this, perkEntry);
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
