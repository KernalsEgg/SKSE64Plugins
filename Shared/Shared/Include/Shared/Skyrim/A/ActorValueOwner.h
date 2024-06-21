#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class ActorValueOwner
	{
	public:
		// Add
		virtual ~ActorValueOwner();                                                                                                                                                           // 0
		virtual float GetActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue);                                                                                              // 1
		virtual float GetPermanentActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue);                                                                                     // 2
		virtual void  Unknown3(ActorValueOwner*);                                                                                                                                             // 3
		virtual void  Unknown4(ActorValueOwner*);                                                                                                                                             // 4
		virtual void  Unknown5(ActorValueOwner*);                                                                                                                                             // 5
		virtual void  RestoreActorValue(Utility::Enumeration<ActorValueModifier, std::uint32_t> actorValueModifier, Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float value); // 6
		virtual void  SetActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float value);                                                                                 // 7
		virtual bool  IsPlayerOwner() const;                                                                                                                                                  // 8

		// Member functions
		float GetDualCastingEffectiveness(float cost) const;
	};
	static_assert(sizeof(ActorValueOwner) == 0x8);
}
