#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSIntrusiveRefCounted.h"
#include "Shared/Skyrim/C/CameraState.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESCamera;

	class TESCameraState :
		public BSIntrusiveRefCounted // 0
	{
	public:
		// Add
		virtual ~TESCameraState();              // 0
		virtual void Unknown1(TESCameraState*); // 1
		virtual void Unknown2(TESCameraState*); // 2
		virtual void Unknown3(TESCameraState*); // 3
		virtual void Unknown4(TESCameraState*); // 4
		virtual void Unknown5(TESCameraState*); // 5
		virtual void Unknown6(TESCameraState*); // 6
		virtual void Unknown7(TESCameraState*); // 7
		virtual void Unknown8(TESCameraState*); // 8

		// Member variables
		std::int32_t                                     paddingC;    // C
		TESCamera*                                       camera;      // 10
		Utility::Enumeration<CameraState, std::uint32_t> cameraState; // 18
		std::int32_t                                     padding1C;
	};
	static_assert(offsetof(TESCameraState, camera) == 0x10);
	static_assert(offsetof(TESCameraState, cameraState) == 0x18);
	static_assert(sizeof(TESCameraState) == 0x20);
}
