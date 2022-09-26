#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTPoint.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class NiNode;

	class TESCamera
	{
	public:
		// Add
		virtual ~TESCamera();              // 0
		virtual void Unknown1(TESCamera*); // 1
		virtual void Unknown2(TESCamera*); // 2

		// Member variables
		BSTPoint2<float>  rotationInput;    // 8
		BSTPoint3<float>  translationInput; // 10
		float             zoomInput;        // 1C
		NiPointer<NiNode> cameraRoot;       // 20
		std::uint64_t     unknown28;        // 28
		bool              enabled;          // 30
		std::uint8_t      padding31;        // 31
		std::uint16_t     padding32;        // 32
		std::uint32_t     padding34;        // 34
	};
	static_assert(offsetof(TESCamera, rotationInput) == 0x8);
	static_assert(offsetof(TESCamera, translationInput) == 0x10);
	static_assert(offsetof(TESCamera, zoomInput) == 0x1C);
	static_assert(offsetof(TESCamera, cameraRoot) == 0x20);
	static_assert(offsetof(TESCamera, enabled) == 0x30);
	static_assert(sizeof(TESCamera) == 0x38);
}
