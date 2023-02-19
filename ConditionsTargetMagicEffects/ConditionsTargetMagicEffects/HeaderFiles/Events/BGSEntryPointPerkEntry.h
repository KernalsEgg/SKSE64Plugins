#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class BGSEntryPointPerkEntry
	{
	public:
		static void Register();

	private:
		static bool CheckConditionFilters(Skyrim::BGSEntryPointPerkEntry* entryPointPerkEntry, std::uint32_t argumentCount, Skyrim::TESForm** arguments);

		static Skyrim::NiPointer<Skyrim::TESObjectREFR>  CreateTemporaryConditionReference();
		static Skyrim::BSSpinLock&                       GetConditionLock();
		static Skyrim::NiPointer<Skyrim::TESObjectREFR>& GetTemporaryConditionSubjectReference();
		static Skyrim::NiPointer<Skyrim::TESObjectREFR>& GetTemporaryConditionTargetReference();
	};
}
