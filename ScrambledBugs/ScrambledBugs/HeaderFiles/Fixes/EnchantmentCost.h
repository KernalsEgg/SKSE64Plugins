#pragma once

#include "PCH.h"

#include "Shared/Skyrim/E/Effect.h"



namespace ScrambledBugs::Fixes
{
	class EnchantmentCost
	{
	public:
		static bool Fix();

	private:
		static bool Unequal(Skyrim::Effect* left, Skyrim::Effect* right);
	};
}
