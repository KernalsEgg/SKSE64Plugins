#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/B/BSTSmartPointer.h"
#include "Shared/Skyrim/C/CameraState.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/T/TESCamera.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	class bhkRigidBody;
	class TESCameraState;

	class PlayerCamera :
		public TESCamera,                    // 0
		public BSTSingletonSDM<PlayerCamera> // 38
	{
	public:
		// Override
		virtual ~PlayerCamera() override; // 0

		// Override (TESCamera)
		virtual void Unknown1(TESCamera*) override; // 1

		// Member variables
		std::uint8_t                                                                           padding39;                                                            // 39
		std::uint16_t                                                                          padding3A;                                                            // 3A
		ActorHandle                                                                            cameraTargetHandle;                                                   // 3C
		BSTSmallArray<TESCameraState*, Utility::Conversion::ToUnderlying(CameraState::kTotal)> temporaryReturnStates;                                                // 40
		BSTSmartPointer<TESCameraState>                                                        cameraStates[Utility::Conversion::ToUnderlying(CameraState::kTotal)]; // B8
		std::uint64_t                                                                          unknown120;                                                           // 120
		NiPointer<bhkRigidBody>                                                                rigidBody;                                                            // 128
		std::uint32_t                                                                          unknown130;                                                           // 130
		mutable BSSpinLock                                                                     lock;                                                                 // 134
		float                                                                                  worldFOV;                                                             // 13C
		float                                                                                  firstPersonFOV;                                                       // 140
		NiPoint3                                                                               position;                                                             // 144
		float                                                                                  idleTimer;                                                            // 150
		float                                                                                  yaw;                                                                  // 154, Radians
		std::uint32_t                                                                          unknown158;                                                           // 158
		std::uint32_t                                                                          unknown15C;                                                           // 15C
		bool                                                                                   allowAutomaticVanityMode;                                             // 160
		bool                                                                                   bowZoomedIn;                                                          // 161
		bool                                                                                   weaponSheathed;                                                       // 162
		bool                                                                                   updated;                                                              // 163
		std::uint8_t                                                                           unknown164;                                                           // 164
		std::uint8_t                                                                           padding165;                                                           // 165
		std::uint16_t                                                                          padding166;                                                           // 166
	};
	static_assert(offsetof(PlayerCamera, cameraTargetHandle) == 0x3C);
	static_assert(offsetof(PlayerCamera, temporaryReturnStates) == 0x40);
	static_assert(offsetof(PlayerCamera, cameraStates) == 0xB8);
	static_assert(offsetof(PlayerCamera, rigidBody) == 0x128);
	static_assert(offsetof(PlayerCamera, lock) == 0x134);
	static_assert(offsetof(PlayerCamera, worldFOV) == 0x13C);
	static_assert(offsetof(PlayerCamera, firstPersonFOV) == 0x140);
	static_assert(offsetof(PlayerCamera, position) == 0x144);
	static_assert(offsetof(PlayerCamera, idleTimer) == 0x150);
	static_assert(offsetof(PlayerCamera, yaw) == 0x154);
	static_assert(offsetof(PlayerCamera, allowAutomaticVanityMode) == 0x160);
	static_assert(offsetof(PlayerCamera, bowZoomedIn) == 0x161);
	static_assert(offsetof(PlayerCamera, weaponSheathed) == 0x162);
	static_assert(offsetof(PlayerCamera, updated) == 0x163);
	static_assert(sizeof(PlayerCamera) == 0x168);
}
