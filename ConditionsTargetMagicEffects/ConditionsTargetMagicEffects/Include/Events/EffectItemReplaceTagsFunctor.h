#pragma once

#include "PrecompiledHeader.h"



namespace ConditionsTargetMagicEffects::Events
{
	class EffectItemReplaceTagsFunctor
	{
	public:
		static void Register();

	private:
		static const char* ReplaceTagsWithText(Skyrim::EffectItemReplaceTagsFunctor* effectItemReplaceTagsFunctor, const char* tag, const char* capitalize, const char* globalEditorID);
	};
}
