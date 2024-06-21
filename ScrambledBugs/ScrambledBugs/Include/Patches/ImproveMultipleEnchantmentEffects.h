#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class ImproveMultipleEnchantmentEffects
	{
	public:
		static void Patch(bool& improveMultipleEnchantmentEffects);

	private:
		static Skyrim::ForEachResult FunctionCallOperator(Skyrim::CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor* createEffectFunctor, Skyrim::EffectItem* effect);
	};
}
