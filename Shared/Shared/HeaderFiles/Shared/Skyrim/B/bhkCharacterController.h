#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSBound.h"
#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Skyrim/H/hkStepInfo.h"
#include "Shared/Skyrim/H/hkVector4.h"
#include "Shared/Skyrim/H/hkpCharacterContext.h"
#include "Shared/Skyrim/H/hkpCharacterStateType.h"
#include "Shared/Skyrim/H/hkpSurfaceInfo.h"
#include "Shared/Skyrim/N/NiRefObject.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class bhkICharOrientationController;

	struct bhkCharacterMoveFinishEvent;

	class bhkCharacterController :
		public NiRefObject,                                // 0
		public BSTEventSource<bhkCharacterMoveFinishEvent> // 10
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone = 0
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~bhkCharacterController() override; // 0

		// Add
		virtual void Unknown2(bhkCharacterController*)  = 0; // 2
		virtual void Unknown3(bhkCharacterController*)  = 0; // 3
		virtual void Unknown4(bhkCharacterController*)  = 0; // 4
		virtual void Unknown5(bhkCharacterController*)  = 0; // 5
		virtual void Unknown6(bhkCharacterController*)  = 0; // 6
		virtual void Unknown7(bhkCharacterController*)  = 0; // 7
		virtual void Unknown8(bhkCharacterController*)  = 0; // 8
		virtual void Unknown9(bhkCharacterController*)  = 0; // 9
		virtual void UnknownA(bhkCharacterController*)  = 0; // A
		virtual void UnknownB(bhkCharacterController*)  = 0; // B
		virtual void UnknownC(bhkCharacterController*)  = 0; // C
		virtual void UnknownD(bhkCharacterController*)  = 0; // D
		virtual void UnknownE(bhkCharacterController*)  = 0; // E
		virtual void UnknownF(bhkCharacterController*)  = 0; // F
		virtual void Unknown10(bhkCharacterController*) = 0; // 10
		virtual void Unknown11(bhkCharacterController*) = 0; // 11
		virtual void Unknown12(bhkCharacterController*) = 0; // 12
		virtual void Unknown13(bhkCharacterController*) = 0; // 13

		// Member variables
		std::uint64_t                                              padding68;                // 68
		hkVector4                                                  forwardDirection;         // 70
		hkStepInfo                                                 stepInformation;          // 80
		hkVector4                                                  velocity;                 // 90
		std::uint64_t                                              unknownA0;                // A0
		std::uint64_t                                              unknownA8;                // A8
		hkVector4                                                  velocityModifier;         // B0
		std::uint64_t                                              unknownC0;                // C0
		std::uint64_t                                              unknownC8;                // C8
		std::uint64_t                                              unknownD0;                // D0
		std::uint64_t                                              unknownD8;                // D8
		std::uint64_t                                              unknownE0;                // E0
		std::uint64_t                                              unknownE8;                // E8
		std::uint64_t                                              unknownF0;                // F0
		std::uint64_t                                              unknownF8;                // F8
		std::uint64_t                                              unknown100;               // 100
		std::uint64_t                                              unknown108;               // 108
		hkVector4                                                  supportNormal;            // 110
		BSBound                                                    collisionBound;           // 120
		BSBound                                                    bumperCollisionBound;     // 150
		std::uint64_t                                              unknown180;               // 180
		std::uint64_t                                              unknown188;               // 188
		bhkICharOrientationController*                             orientationController;    // 190
		std::uint64_t                                              padding198;               // 198
		hkpSurfaceInfo                                             surfaceInformation;       // 1A0
		hkpCharacterContext                                        context;                  // 1E0
		Utility::Enumeration<Flags, std::uint32_t>                 characterControllerFlags; // 218
		Utility::Enumeration<hkpCharacterStateType, std::uint32_t> desiredState;             // 21C
		std::uint64_t                                              unknown220;               // 220
		std::uint64_t                                              unknown228;               // 228
		std::uint64_t                                              unknown230;               // 230
		float                                                      waterHeight;              // 238
		float                                                      jumpHeight;               // 23C
		float                                                      startFallingHeight;       // 240
		float                                                      inAirTime;                // 244
		float                                                      gravity;                  // 248
		std::uint32_t                                              unknown24C;               // 24C
		std::uint64_t                                              unknown250;               // 250
		std::uint64_t                                              unknown258;               // 258
		std::uint32_t                                              unknown260;               // 260
		float                                                      speedMultiplier;          // 264
		std::uint64_t                                              unknown268;               // 268
		std::uint64_t                                              unknown270;               // 270
		std::uint64_t                                              unknown278;               // 278
		std::uint64_t                                              unknown280;               // 280
		std::uint64_t                                              unknown288;               // 288
		std::uint64_t                                              unknown290;               // 290
		std::uint64_t                                              unknown298;               // 298
		std::uint64_t                                              unknown2A0;               // 2A0
		std::uint64_t                                              unknown2A8;               // 2A8
		std::uint64_t                                              unknown2B0;               // 2B0
		std::uint64_t                                              unknown2B8;               // 2B8
		std::uint64_t                                              unknown2C0;               // 2C0
		std::uint64_t                                              unknown2C8;               // 2C8
		std::uint64_t                                              unknown2D0;               // 2D0
		std::uint64_t                                              unknown2D8;               // 2D8
		std::uint64_t                                              unknown2E0;               // 2E0
		std::uint64_t                                              unknown2E8;               // 2E8
		std::uint64_t                                              unknown2F0;               // 2F0
		std::uint64_t                                              unknown2F8;               // 2F8
		std::uint64_t                                              unknown300;               // 300
		std::uint64_t                                              unknown308;               // 308
		std::uint64_t                                              unknown310;               // 310
		std::uint64_t                                              unknown318;               // 318
		std::uint64_t                                              unknown320;               // 320
		std::uint64_t                                              unknown328;               // 328
	};
	static_assert(offsetof(bhkCharacterController, forwardDirection) == 0x70);
	static_assert(offsetof(bhkCharacterController, stepInformation) == 0x80);
	static_assert(offsetof(bhkCharacterController, velocity) == 0x90);
	static_assert(offsetof(bhkCharacterController, velocityModifier) == 0xB0);
	static_assert(offsetof(bhkCharacterController, supportNormal) == 0x110);
	static_assert(offsetof(bhkCharacterController, collisionBound) == 0x120);
	static_assert(offsetof(bhkCharacterController, bumperCollisionBound) == 0x150);
	static_assert(offsetof(bhkCharacterController, orientationController) == 0x190);
	static_assert(offsetof(bhkCharacterController, surfaceInformation) == 0x1A0);
	static_assert(offsetof(bhkCharacterController, context) == 0x1E0);
	static_assert(offsetof(bhkCharacterController, characterControllerFlags) == 0x218);
	static_assert(offsetof(bhkCharacterController, desiredState) == 0x21C);
	static_assert(offsetof(bhkCharacterController, waterHeight) == 0x238);
	static_assert(offsetof(bhkCharacterController, jumpHeight) == 0x23C);
	static_assert(offsetof(bhkCharacterController, startFallingHeight) == 0x240);
	static_assert(offsetof(bhkCharacterController, inAirTime) == 0x244);
	static_assert(offsetof(bhkCharacterController, gravity) == 0x248);
	static_assert(offsetof(bhkCharacterController, speedMultiplier) == 0x264);
	static_assert(sizeof(bhkCharacterController) == 0x330);
}
