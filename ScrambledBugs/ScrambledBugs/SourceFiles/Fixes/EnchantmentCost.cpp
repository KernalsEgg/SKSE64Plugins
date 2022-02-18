#include "PCH.h"

#include "Fixes/EnchantmentCost.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Fixes
{
	bool EnchantmentCost::Fix()
	{
		if (!Patterns::Fixes::EnchantmentCost::Unequal())
		{
			return false;
		}

		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Fixes::EnchantmentCost::Unequal, reinterpret_cast<std::uintptr_t>(std::addressof(EnchantmentCost::Unequal)));

		return true;
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
