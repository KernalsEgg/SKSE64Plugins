#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MagicTarget.h"



namespace Skyrim
{
	class ActiveEffect;

	class FindMaxMagnitudeVisitor :
		public MagicTarget::ForEachActiveEffectVisitor // 0
	{
	public:
		// Override
		virtual ~FindMaxMagnitudeVisitor() override = default; // 0

		// Override (MagicTarget::ForEachActiveEffectVisitor)
		virtual ForEachResult operator()(ActiveEffect* activeEffect) override; // 1

		// Member variables
		ActiveEffect* finishedActiveEffect{ nullptr }; // 8
		float         maximumMagnitude{ -1.0F };       // 10
	};
	static_assert(offsetof(FindMaxMagnitudeVisitor, finishedActiveEffect) == 0x8);
	static_assert(offsetof(FindMaxMagnitudeVisitor, maximumMagnitude) == 0x10);
	static_assert(sizeof(FindMaxMagnitudeVisitor) == 0x18);
}
