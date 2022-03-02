#include "PCH.h"

#include "Fixes/EnchantmentCost.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Fixes
{
	void EnchantmentCost::Fix(bool& enchantmentCost)
	{
		if (!Patterns::Fixes::EnchantmentCost::Unequal())
		{
			enchantmentCost = false;

			return;
		}

		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Fixes::EnchantmentCost::Unequal, reinterpret_cast<std::uintptr_t>(std::addressof(EnchantmentCost::Unequal)));
	}

	bool EnchantmentCost::Unequal(Skyrim::Effect* left, Skyrim::Effect* right)
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
