#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class CraftingSubMenus
	{
	public:
		class EnchantConstructMenu
		{
		public:
			class CreateEffectFunctor
			{
			public:
				static void Register();

			private:
				static Skyrim::ForEachResult FunctionCallOperator(Skyrim::CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor* createEffectFunctor, Skyrim::EffectItem* effect);
			};
		};
	};
}
