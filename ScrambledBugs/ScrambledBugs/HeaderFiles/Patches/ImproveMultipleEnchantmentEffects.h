#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/E/Effect.h"
#include "Shared/Skyrim/E/EnchantConstructMenu.h"
#include "Shared/Skyrim/M/MagicItemTraversalFunctor.h"



namespace ScrambledBugs::Patches
{
	class ImproveMultipleEnchantmentEffects
	{
	public:
		static void Patch(bool& improveMultipleEnchantmentEffects);

	private:
		static Skyrim::MagicItemTraversalFunctor::ReturnType Traverse(Skyrim::CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor* createEffectFunctor, Skyrim::Effect* effect);
	};
}
