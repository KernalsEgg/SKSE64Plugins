#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/V/ValueModifierEffect.h"



namespace Skyrim
{
	class AccumulatingValueModifierEffect :
		public ValueModifierEffect // 0
	{
	public:
		// Override
		virtual ~AccumulatingValueModifierEffect() override; // 13

		// Override (ValueModifierEffect)
		virtual void Unknown8(ActiveEffect*) override;         // 8
		virtual void Unknown9(ActiveEffect*) override;         // 9
		virtual void Start() override;                         // 14
		virtual void Finish() override;                        // 15
		virtual void Unknown1A(ValueModifierEffect*) override; // 1A
		virtual void Unknown1C(ValueModifierEffect*) override; // 1C
		virtual void Unknown1D(ValueModifierEffect*) override; // 1D
		virtual void Unknown1F(ValueModifierEffect*) override; // 1F

		// Member variables
		float         currentMagnitude; // 98
		float         maximumMagnitude; // 9C
		float         holdDuration;     // A0, The duration for which your ward power will not accumulate after being hit (fMagicAccumulatingModifierEffectHoldDuration)
		std::uint32_t paddingA4;        // A4
	};
	static_assert(offsetof(AccumulatingValueModifierEffect, currentMagnitude) == 0x98);
	static_assert(offsetof(AccumulatingValueModifierEffect, maximumMagnitude) == 0x9C);
	static_assert(offsetof(AccumulatingValueModifierEffect, holdDuration) == 0xA0);
	static_assert(sizeof(AccumulatingValueModifierEffect) == 0xA8);
}
