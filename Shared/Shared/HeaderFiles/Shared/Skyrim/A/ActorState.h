#pragma once

#include "Shared/PrecompiledHeader.h"

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
			enum class ActorLifeState : std::uint32_t
			{
				kAlive         = 0,
				kDying         = 1,
				kDead          = 2,
				kUnconcious    = 3,
				kReanimate     = 4,
				kRecycle       = 5,
				kRestrained    = 6,
				kEssentialDown = 7,
				kBleedout      = 8
			};
			static_assert(sizeof(ActorLifeState) == 0x4);

			enum class AttackState : std::uint32_t
			{
			};
			static_assert(sizeof(AttackState) == 0x4);

			enum class FlyState : std::uint32_t
			{
			};
			static_assert(sizeof(FlyState) == 0x4);

			enum class KnockState : std::uint32_t
			{
			};
			static_assert(sizeof(KnockState) == 0x4);

			enum class SitSleepState : std::uint32_t
			{
			};
			static_assert(sizeof(SitSleepState) == 0x4);

			// Member variables
			std::uint32_t  movingBack     : 1; // 0 (0, 0)
			std::uint32_t  movingForward  : 1; // 0 (0, 1)
			std::uint32_t  movingRight    : 1; // 0 (0, 2)
			std::uint32_t  movingLeft     : 1; // 0 (0, 3)
			std::uint32_t  unknown0Bit4   : 2; // 0 (0, 4)
			std::uint32_t  walking        : 1; // 0 (0, 6)
			std::uint32_t  running        : 1; // 0 (0, 7)
			std::uint32_t  sprinting      : 1; // 0 (1, 0)
			std::uint32_t  sneaking       : 1; // 0 (1, 1)
			std::uint32_t  swimming       : 1; // 0 (1, 2)
			std::uint32_t  unknown1Bit3   : 3; // 0 (1, 3)
			SitSleepState  sitSleepState  : 4; // 0 (1, 6)
			FlyState       flyState       : 3; // 0 (2, 2)
			ActorLifeState actorLifeState : 4; // 0 (2, 5)
			KnockState     knockState     : 3; // 0 (3, 1)
			AttackState    attackState    : 4; // 0 (3, 4)
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

		// Member functions
		bool IsSneaking() const;
		bool IsSwimming() const;

		// Member variables
		ActorState1 actorState1; // 8
		ActorState2 actorState2; // C
	};
	static_assert(offsetof(ActorState, actorState1) == 0x8);
	static_assert(offsetof(ActorState, actorState2) == 0xC);
	static_assert(sizeof(ActorState) == 0x10);
}
