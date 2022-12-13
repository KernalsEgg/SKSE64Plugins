#include "PrecompiledHeader.h"

#include "Fixes/HarvestedFlags.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Fixes
{
	void HarvestedFlags::Fix(bool& harvestedFlags)
	{
		if (!Patterns::Fixes::HarvestedFlags::SetEmpty())
		{
			harvestedFlags = false;

			return;
		}

		HarvestedFlags::setEmpty_ = reinterpret_cast<decltype(HarvestedFlags::setEmpty_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Fixes::HarvestedFlags::SetEmpty, reinterpret_cast<std::uintptr_t>(std::addressof(HarvestedFlags::SetEmpty))));
	}

	void HarvestedFlags::SetEmpty(Skyrim::TESObjectREFR* reference, bool empty)
	{
		// reference != nullptr

		auto formType = reference->baseObject->formType;

		if (formType == Skyrim::FormType::kTree || formType == Skyrim::FormType::kFlora)
		{
			reference->RemoveChanges(Utility::ToUnderlying(Skyrim::TESObjectREFR::ChangeFlags::kEmpty));
		}

		HarvestedFlags::setEmpty_(reference, empty);
	}

	decltype(&HarvestedFlags::SetEmpty) HarvestedFlags::setEmpty_{ nullptr };
}
