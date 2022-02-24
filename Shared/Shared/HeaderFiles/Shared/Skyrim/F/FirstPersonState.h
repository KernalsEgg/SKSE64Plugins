#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/P/PlayerInputHandler.h"
#include "Shared/Skyrim/T/TESCameraState.h"



namespace Skyrim
{
	class NiAVObject;
	class NiNode;

	class FirstPersonState :
		public TESCameraState,    // 0
		public PlayerInputHandler // 20
	{
	public:
		// Override
		virtual ~FirstPersonState() override; // 0

		// Override (TESCameraState)
		virtual void Unknown1(TESCameraState*) override; // 1
		virtual void Unknown2(TESCameraState*) override; // 2
		virtual void Unknown3(TESCameraState*) override; // 3
		virtual void Unknown4(TESCameraState*) override; // 4
		virtual void Unknown5(TESCameraState*) override; // 5
		virtual void Unknown6(TESCameraState*) override; // 6
		virtual void Unknown7(TESCameraState*) override; // 7
		virtual void Unknown8(TESCameraState*) override; // 8

		// Override (PlayerInputHandler)
		virtual void Unknown1(PlayerInputHandler*) override; // 1
		virtual void Unknown4(PlayerInputHandler*) override; // 4

		// Member variables
		NiPoint3      lastPosition;             // 30
		NiPoint3      lastFrameSpringVelocity;  // 3C
		NiPoint3      dampingOffset;            // 48
		std::uint32_t padding54;                // 54
		NiAVObject*   firstPersonCameraObject;  // 58
		NiNode*       firstPersonCameraFOVNode; // 60
		float         sittingRotation;          // 68
		std::uint32_t unknown6C;                // 6C
		std::uint32_t unknown70;                // 70
		float         currentPitchOffset;       // 74
		float         targetPitchOffset;        // 78
		std::uint32_t unknown7C;                // 7C
		std::uint32_t unknown80;                // 80
		bool          cameraOverride;           // 84
		bool          cameraPitchOverride;      // 85
		std::uint8_t  unknown86;                // 86
		std::uint8_t  padding87;                // 87
		std::uint64_t unknown88;                // 88
	};
	static_assert(offsetof(FirstPersonState, lastPosition) == 0x30);
	static_assert(offsetof(FirstPersonState, lastFrameSpringVelocity) == 0x3C);
	static_assert(offsetof(FirstPersonState, dampingOffset) == 0x48);
	static_assert(offsetof(FirstPersonState, firstPersonCameraObject) == 0x58);
	static_assert(offsetof(FirstPersonState, firstPersonCameraFOVNode) == 0x60);
	static_assert(offsetof(FirstPersonState, sittingRotation) == 0x68);
	static_assert(offsetof(FirstPersonState, currentPitchOffset) == 0x74);
	static_assert(offsetof(FirstPersonState, targetPitchOffset) == 0x78);
	static_assert(offsetof(FirstPersonState, cameraOverride) == 0x84);
	static_assert(offsetof(FirstPersonState, cameraPitchOverride) == 0x85);
	static_assert(sizeof(FirstPersonState) == 0x90);
}
