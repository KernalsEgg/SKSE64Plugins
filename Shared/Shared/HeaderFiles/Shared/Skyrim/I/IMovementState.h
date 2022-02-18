#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/I/IMovementInterface.h"



namespace Skyrim
{
	class IMovementState :
		public IMovementInterface // 0
	{
	public:
		// Override
		virtual ~IMovementState() override; // 0

		// Add
		virtual void Unknown1(IMovementState*)  = 0; // 1
		virtual void Unknown2(IMovementState*)  = 0; // 2
		virtual void Unknown3(IMovementState*)  = 0; // 3
		virtual void Unknown4(IMovementState*)  = 0; // 4
		virtual void Unknown5(IMovementState*)  = 0; // 5
		virtual void Unknown6(IMovementState*)  = 0; // 6
		virtual void Unknown7(IMovementState*)  = 0; // 7
		virtual void Unknown8(IMovementState*)  = 0; // 8
		virtual void Unknown9(IMovementState*)  = 0; // 9
		virtual void UnknownA(IMovementState*)  = 0; // A
		virtual void UnknownB(IMovementState*)  = 0; // B
		virtual void UnknownC(IMovementState*)  = 0; // C
		virtual void UnknownD(IMovementState*)  = 0; // D
		virtual void UnknownE(IMovementState*)  = 0; // E
		virtual void UnknownF(IMovementState*)  = 0; // F
		virtual void Unknown10(IMovementState*) = 0; // 10
		virtual void Unknown11(IMovementState*) = 0; // 11
		virtual void Unknown12(IMovementState*) = 0; // 12
		virtual void Unknown13(IMovementState*) = 0; // 13
	};
	static_assert(sizeof(IMovementState) == 0x8);
}
