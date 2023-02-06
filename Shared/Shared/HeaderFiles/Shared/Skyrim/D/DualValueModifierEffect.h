#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/V/ValueModifierEffect.h"



namespace Skyrim
{
	class DualValueModifierEffect :
		public ValueModifierEffect // 0
	{
	public:
		// Override
		virtual ~DualValueModifierEffect() override; // 13

		// Override (ValueModifierEffect)
		virtual void Unknown0(ActiveEffect*) override;                                                                                      // 0
		virtual void Unknown6(ActiveEffect*) override;                                                                                      // 6
		virtual void Unknown8(ActiveEffect*) override;                                                                                      // 8
		virtual void Unknown9(ActiveEffect*) override;                                                                                      // 9
		virtual void ModifyActorValue(Actor* target, float magnitude, Utility::Enumeration<ActorValue, std::uint32_t> actorValue) override; // 20

		// Add
		virtual void Unknown21(DualValueModifierEffect*); // 21
		virtual void Unknown22(DualValueModifierEffect*); // 22

		// Member variables
		float         secondaryActorValueWeight; // 98
		std::uint32_t padding9C;                 // 9C
	};
	static_assert(offsetof(DualValueModifierEffect, secondaryActorValueWeight) == 0x98);
	static_assert(sizeof(DualValueModifierEffect) == 0xA0);
}
