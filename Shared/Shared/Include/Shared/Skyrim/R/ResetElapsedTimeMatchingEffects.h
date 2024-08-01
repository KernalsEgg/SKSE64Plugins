#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MagicSystem.h"
#include "Shared/Skyrim/M/MagicTarget.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct EffectItem;

	class Actor;
	class MagicItem;
	class TESBoundObject;

	struct ResetElapsedTimeMatchingEffects :
		public MagicTarget::ForEachActiveEffectVisitor // 0
	{
	public:
		// Override
		virtual ~ResetElapsedTimeMatchingEffects() override; // 0

		// Override (MagicTarget::ForEachActiveEffectVisitor)
		virtual ForEachResult operator()(ActiveEffect* activeEffect) override; // 1

		// Member variables
		MagicItem*                                                      magicItem;        // 8
		Actor*                                                          caster;           // 10
		EffectItem*                                                     effectItem;       // 18
		TESBoundObject*                                                 boundObject;      // 20
		Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource;    // 28
		bool                                                            resetElapsedTime; // 2C
		std::uint8_t                                                    padding2D;        // 2D
		std::uint16_t                                                   padding2E;        // 2E
	};
	static_assert(offsetof(ResetElapsedTimeMatchingEffects, magicItem) == 0x8);
	static_assert(offsetof(ResetElapsedTimeMatchingEffects, caster) == 0x10);
	static_assert(offsetof(ResetElapsedTimeMatchingEffects, effectItem) == 0x18);
	static_assert(offsetof(ResetElapsedTimeMatchingEffects, boundObject) == 0x20);
	static_assert(offsetof(ResetElapsedTimeMatchingEffects, castingSource) == 0x28);
	static_assert(offsetof(ResetElapsedTimeMatchingEffects, resetElapsedTime) == 0x2C);
	static_assert(sizeof(ResetElapsedTimeMatchingEffects) == 0x30);
}
