#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActiveEffect.h"
#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class Actor;

	class ValueModifierEffect :
		public ActiveEffect // 0
	{
	public:
		// Override
		virtual ~ValueModifierEffect() override; // 13

		// Override (ActiveEffect)
		virtual void Unknown1(ActiveEffect*) override;        // 1
		virtual void Update(float elapsedTimeDelta) override; // 4
		virtual void Unknown6(ActiveEffect*) override;        // 6
		virtual void Unknown11(ActiveEffect*) override;       // 11
		virtual void Unknown12(ActiveEffect*) override;       // 12
		virtual void Start() override;                        // 14
		virtual void Finish() override;                       // 15
		virtual void Unknown17(ActiveEffect*) override;       // 17
		virtual void Unknown18(ActiveEffect*) override;       // 18

		// Add
		virtual void Unknown19(ValueModifierEffect*);                                                                              // 19
		virtual void Unknown1A(ValueModifierEffect*);                                                                              // 1A
		virtual void Unknown1B(ValueModifierEffect*);                                                                              // 1B
		virtual void Unknown1C(ValueModifierEffect*);                                                                              // 1C
		virtual void Unknown1D(ValueModifierEffect*);                                                                              // 1D
		virtual void Unknown1E(ValueModifierEffect*);                                                                              // 1E
		virtual void Unknown1F(ValueModifierEffect*);                                                                              // 1F
		virtual void ModifyActorValue(Actor* target, float magnitude, Utility::Enumeration<ActorValue, std::uint32_t> actorValue); // 20

		// Member variables
		Utility::Enumeration<ActorValue, std::uint32_t> actorValue; // 90
		std::uint32_t                                   unknown94;  // 94
	};
	static_assert(offsetof(ValueModifierEffect, actorValue) == 0x90);
	static_assert(sizeof(ValueModifierEffect) == 0x98);
}
