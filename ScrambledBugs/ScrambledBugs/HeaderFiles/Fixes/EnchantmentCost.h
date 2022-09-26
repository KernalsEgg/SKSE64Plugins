#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/E/Effect.h"



namespace ScrambledBugs::Fixes
{
	class EnchantmentCost
	{
	public:
		static void Fix(bool& enchantmentCost);

	private:
		static bool NotEqual(Skyrim::Effect* left, Skyrim::Effect* right);
	};
}
