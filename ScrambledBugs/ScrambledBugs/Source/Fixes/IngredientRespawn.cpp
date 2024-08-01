#include "PrecompiledHeader.h"

#include "Fixes/IngredientRespawn.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void IngredientRespawn::Fix(bool& ingredientRespawn)
	{
		if (!Patterns::Fixes::IngredientRespawn::SetEmpty())
		{
			ingredientRespawn = false;

			return;
		}

		IngredientRespawn::setEmpty_ = reinterpret_cast<decltype(IngredientRespawn::setEmpty_)>(
			Utility::Memory::ReadRelativeCall5(
				Addresses::Fixes::IngredientRespawn::SetEmpty));
		SKSE::Storage::GetSingleton().GetTrampolineInterface()->RelativeCall5(
			Addresses::Fixes::IngredientRespawn::SetEmpty,
			reinterpret_cast<std::uintptr_t>(std::addressof(IngredientRespawn::SetEmpty)));
	}

	void IngredientRespawn::SetEmpty(Skyrim::TESObjectREFR* reference, bool empty)
	{
		// reference != nullptr

		switch (reference->baseObject->formType.get())
		{
			case Skyrim::FormType::kTree:
			case Skyrim::FormType::kFlora:
			{
				reference->RemoveChanges(Utility::Conversion::ToUnderlying(Skyrim::TESObjectREFR::ChangeFlags::kEmpty));

				break;
			}
		}

		IngredientRespawn::setEmpty_(reference, empty);
	}

	decltype(IngredientRespawn::SetEmpty)* IngredientRespawn::setEmpty_{ nullptr };
}
