#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/E/EffectItem.h"



namespace ScrambledBugs::Fixes
{
	class EnchantmentCost
	{
	public:
		static void Fix(bool& enchantmentCost);

	private:
		static bool Compare(Skyrim::EffectItem* left, Skyrim::EffectItem* right);
	};
}
