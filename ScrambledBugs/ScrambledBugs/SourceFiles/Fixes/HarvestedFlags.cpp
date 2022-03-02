#include "PCH.h"

#include "Fixes/HarvestedFlags.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Fixes
{
	void HarvestedFlags::Fix(bool& harvestedFlags)
	{
		if (!Patterns::Fixes::HarvestedFlags::RemoveHarvestedFlag())
		{
			harvestedFlags = false;

			return;
		}

		HarvestedFlags::setHarvestedFlag_ = reinterpret_cast<decltype(HarvestedFlags::setHarvestedFlag_)>(Utility::Memory::ReadRelativeCall(Addresses::Fixes::HarvestedFlags::RemoveHarvestedFlag));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Fixes::HarvestedFlags::RemoveHarvestedFlag, reinterpret_cast<std::uintptr_t>(std::addressof(HarvestedFlags::SetHarvestedFlag)));
	}

	void HarvestedFlags::SetHarvestedFlag(Skyrim::TESObjectREFR* reference, bool harvested)
	{
		// reference != nullptr

		auto formType = reference->baseObject->formType;

		if (formType == Skyrim::FormType::kTree || formType == Skyrim::FormType::kFlora)
		{
			reference->RemoveChanges(Utility::ToUnderlying(Skyrim::TESObjectREFR::ChangeFlags::kHarvested));
		}

		HarvestedFlags::setHarvestedFlag_(reference, harvested);
	}

	decltype(&HarvestedFlags::SetHarvestedFlag) HarvestedFlags::setHarvestedFlag_{ nullptr };
}
