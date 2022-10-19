#include "PrecompiledHeader.h"

#include "Fixes/EnchantmentCost.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Fixes
{
	void EnchantmentCost::Fix(bool& enchantmentCost)
	{
		if (!Patterns::Fixes::EnchantmentCost::NotEqualTo())
		{
			enchantmentCost = false;

			return;
		}

		Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Fixes::EnchantmentCost::NotEqualTo, reinterpret_cast<std::uintptr_t>(std::addressof(EnchantmentCost::NotEqualTo)));
	}

	bool EnchantmentCost::NotEqualTo(Skyrim::Effect* left, Skyrim::Effect* right)
	{
		if (left->baseEffect != right->baseEffect)
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
