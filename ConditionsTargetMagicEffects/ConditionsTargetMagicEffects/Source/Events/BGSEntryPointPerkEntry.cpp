#include "PrecompiledHeader.h"

#include "Events/BGSEntryPointPerkEntry.h"

#include "Shared/Utility/Memory.h"



namespace ConditionsTargetMagicEffects::Events
{
	void BGSEntryPointPerkEntry::Register()
	{
		Utility::Memory::SafeWriteVirtualFunction(
			Skyrim::Addresses::BGSEntryPointPerkEntry::VirtualFunctionTable(),
			0x0,
			reinterpret_cast<std::uintptr_t>(std::addressof(BGSEntryPointPerkEntry::CheckConditionFilters)));
	}

	bool BGSEntryPointPerkEntry::CheckConditionFilters(Skyrim::BGSEntryPointPerkEntry* entryPointPerkEntry, std::uint32_t argumentCount, Skyrim::TESForm** arguments)
	{
		if (entryPointPerkEntry->argumentCount != argumentCount)
		{
			return false;
		}

		bool result{ true };

		for (std::size_t argumentIndex = 0, conditionIndex = 0; conditionIndex < argumentCount; ++argumentIndex, ++conditionIndex)
		{
			if (!result)
			{
				break;
			}

			Skyrim::TESObjectREFR* conditionSubject{ nullptr };
			Skyrim::TESObjectREFR* conditionTarget{ nullptr };

			auto* argument = arguments[argumentIndex];

			if (argument && argument->formType == Skyrim::FormType::kMagicEffect)
			{
				auto* effectSetting = static_cast<Skyrim::EffectSetting*>(argument);

				argument = arguments[++argumentIndex];

				if (argument && argument->IsBoundObject())
				{
					conditionTarget = BGSEntryPointPerkEntry::GetTemporaryConditionTargetReference().get();

					conditionTarget->SetObjectReference(static_cast<Skyrim::TESBoundObject*>(argument));
					conditionTarget->extraDataList.SetLockList(effectSetting);
				}
			}

			if (argument)
			{
				if (argument->IsBoundObject())
				{
					conditionSubject = BGSEntryPointPerkEntry::GetTemporaryConditionSubjectReference().get();

					conditionSubject->SetObjectReference(static_cast<Skyrim::TESBoundObject*>(argument));
				}
				else
				{
					conditionSubject = argument->AsReference();
				}
			}

			Skyrim::Script::ClearCachedValues();

			result = conditionSubject ?
			             entryPointPerkEntry->conditions[conditionIndex].IsTrue(conditionSubject, conditionTarget) :
			             !entryPointPerkEntry->conditions[conditionIndex].head;
		}

		return result;
	}

	Skyrim::NiPointer<Skyrim::TESObjectREFR> BGSEntryPointPerkEntry::CreateTemporaryConditionReference()
	{
		Skyrim::NiPointer<Skyrim::TESObjectREFR> temporaryConditionReference{ Skyrim::TESObjectREFRFactory::GetFormFactory()->Create() };

		temporaryConditionReference->SetTemporary();

		return temporaryConditionReference;
	}

	Skyrim::NiPointer<Skyrim::TESObjectREFR>& BGSEntryPointPerkEntry::GetTemporaryConditionSubjectReference()
	{
		thread_local static Skyrim::NiPointer<Skyrim::TESObjectREFR> temporaryConditionSubjectReference{ BGSEntryPointPerkEntry::CreateTemporaryConditionReference() };

		return temporaryConditionSubjectReference;
	}

	Skyrim::NiPointer<Skyrim::TESObjectREFR>& BGSEntryPointPerkEntry::GetTemporaryConditionTargetReference()
	{
		thread_local static Skyrim::NiPointer<Skyrim::TESObjectREFR> temporaryConditionTargetReference{ BGSEntryPointPerkEntry::CreateTemporaryConditionReference() };

		return temporaryConditionTargetReference;
	}
}
