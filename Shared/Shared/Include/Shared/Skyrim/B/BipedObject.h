#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class BGSTextureSet;
	class NiAVObject;
	class TESBoundObject;
	class TESModel;
	class TESObjectARMA;

	struct BipedObject
	{
	public:
		// Member variables
		TESBoundObject*       boundObject;     // 0
		TESObjectARMA*        addon;           // 8
		TESModel*             bipedModel;      // 10
		BGSTextureSet*        skinTexture;     // 18
		NiPointer<NiAVObject> bipedModelClone; // 20
		std::uint64_t         unknown28;       // 28
		std::uint64_t         unknown30;       // 30
		std::uint64_t         unknown38;       // 38
		std::uint64_t         unknown40;       // 40
		std::uint64_t         unknown48;       // 48
		std::uint64_t         unknown50;       // 50
		std::uint64_t         unknown58;       // 58
		std::uint64_t         unknown60;       // 60
		std::uint64_t         unknown68;       // 68
		std::uint64_t         unknown70;       // 70
	};
	static_assert(offsetof(BipedObject, boundObject) == 0x0);
	static_assert(offsetof(BipedObject, addon) == 0x8);
	static_assert(offsetof(BipedObject, bipedModel) == 0x10);
	static_assert(offsetof(BipedObject, skinTexture) == 0x18);
	static_assert(offsetof(BipedObject, bipedModelClone) == 0x20);
	static_assert(sizeof(BipedObject) == 0x78);
}
