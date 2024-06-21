#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESCameraState.h"



namespace SKSE
{
	struct CameraEvent
	{
	public:
		Skyrim::TESCameraState* oldCameraState;
		Skyrim::TESCameraState* newCameraState;
	};
	static_assert(offsetof(CameraEvent, oldCameraState) == 0x0);
	static_assert(offsetof(CameraEvent, newCameraState) == 0x8);
	static_assert(sizeof(CameraEvent) == 0x10);
}
