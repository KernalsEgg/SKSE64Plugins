#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/I/IMovementState.h"



namespace Skyrim
{
	class ActorState :
		public IMovementState // 0
	{
	public:
		struct ActorState1
		{
		public:
			// Member variables
			std::uint32_t unknown0; // 0
		};
		static_assert(sizeof(ActorState1) == 0x4);

		struct ActorState2
		{
		public:
			// Member variables
			std::uint32_t unknown0; // 0
		};
		static_assert(sizeof(ActorState2) == 0x4);

		// Override
		virtual ~ActorState() override; // 0

		// Override (IMovementState)
		virtual void Unknown1(IMovementState*) override; // 1
		virtual void Unknown2(IMovementState*) override; // 2
		virtual void Unknown3(IMovementState*) override; // 3
		virtual void Unknown4(IMovementState*) override; // 4
		virtual void Unknown5(IMovementState*) override; // 5
		virtual void Unknown6(IMovementState*) override; // 6
		virtual void Unknown7(IMovementState*) override; // 7
		virtual void Unknown8(IMovementState*) override; // 8

		// Add
		virtual void Unknown14(ActorState*); // 14
		virtual void Unknown15(ActorState*); // 15

		// Member variables
		ActorState1 actorState1; // 8
		ActorState2 actorState2; // C
	};
	static_assert(offsetof(ActorState, actorState1) == 0x8);
	static_assert(offsetof(ActorState, actorState2) == 0xC);
	static_assert(sizeof(ActorState) == 0x10);
}
