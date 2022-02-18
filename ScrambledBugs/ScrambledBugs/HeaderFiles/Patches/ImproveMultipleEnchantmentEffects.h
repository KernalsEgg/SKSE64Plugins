#pragma once

#include "PCH.h"

#include "Shared/Skyrim/E/Effect.h"
#include "Shared/Skyrim/E/EnchantConstructMenu.h"
#include "Shared/Skyrim/M/MagicItemTraversalFunctor.h"



namespace ScrambledBugs::Patches
{
	class ImproveMultipleEnchantmentEffects
	{
	public:
		static bool Patch();

	private:
		static Skyrim::MagicItemTraversalFunctor::ReturnType Traverse(Skyrim::CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor* createEffectFunctor, Skyrim::Effect* effect);
	};
}
