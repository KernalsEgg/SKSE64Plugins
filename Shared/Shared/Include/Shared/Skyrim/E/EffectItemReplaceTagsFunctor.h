#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSString.h"



namespace Skyrim
{
	struct EffectItem;

	class MagicItem;

	struct EffectItemReplaceTagsFunctor
	{
	public:
		// Member variables
		BSString    tag;       // 0
		EffectItem* effect;    // 10
		const char* tagStart;  // 18
		const char* tagEnd;    // 20
		MagicItem*  magicItem; // 28
	};
	static_assert(offsetof(EffectItemReplaceTagsFunctor, tag) == 0x0);
	static_assert(offsetof(EffectItemReplaceTagsFunctor, effect) == 0x10);
	static_assert(offsetof(EffectItemReplaceTagsFunctor, tagStart) == 0x18);
	static_assert(offsetof(EffectItemReplaceTagsFunctor, tagEnd) == 0x20);
	static_assert(offsetof(EffectItemReplaceTagsFunctor, magicItem) == 0x28);
	static_assert(sizeof(EffectItemReplaceTagsFunctor) == 0x30);
}
