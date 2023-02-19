#include "PrecompiledHeader.h"

#include "Fixes/EnchantmentCost.h"

#include "Addresses.h"
#include "Patterns.h"



namespace ScrambledBugs::Fixes
{
	void EnchantmentCost::Fix(bool& enchantmentCost)
	{
		if (!Patterns::Fixes::EnchantmentCost::Compare())
		{
			enchantmentCost = false;

			return;
		}

		SKSE::Storage::GetSingleton().GetTrampolineInterface()->RelativeCall5(Addresses::Fixes::EnchantmentCost::Compare, reinterpret_cast<std::uintptr_t>(std::addressof(EnchantmentCost::Compare)));
	}

	bool EnchantmentCost::Compare(Skyrim::EffectItem* left, Skyrim::EffectItem* right)
	{
		if (left->effectSetting != right->effectSetting)
		{
			return true;
		}

		if (left->GetMagnitude() != right->GetMagnitude())
		{
			return true;
		}

		if (left->GetArea() != right->GetArea())
		{
			return true;
		}

		if (left->GetDuration() != right->GetDuration())
		{
			return true;
		}

		return false;
	}
}
