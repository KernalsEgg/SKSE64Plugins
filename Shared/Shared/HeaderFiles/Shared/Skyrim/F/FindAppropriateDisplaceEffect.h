#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MagicTarget.h"



namespace Skyrim
{
	class MagicItem;
	class SpellItem;

	class FindAppropriateDisplaceEffect :
		public MagicTarget::ForEachActiveEffectVisitor // 0
	{
	public:
		// Override
		virtual ~FindAppropriateDisplaceEffect() override = default; // 0

		// Override (MagicTarget::ForEachActiveEffectVisitor)
		virtual MagicTarget::ForEachActiveEffectVisitor::ReturnType Visit(ActiveEffect* activeEffect) override; // 1

		// Member variables
		MagicItem* displacementSpell; // 8
		SpellItem* addiction;         // 10
		bool       displace;          // 18
	};
	static_assert(offsetof(FindAppropriateDisplaceEffect, displacementSpell) == 0x8);
	static_assert(offsetof(FindAppropriateDisplaceEffect, addiction) == 0x10);
	static_assert(offsetof(FindAppropriateDisplaceEffect, displace) == 0x18);
	static_assert(sizeof(FindAppropriateDisplaceEffect) == 0x20);
}
