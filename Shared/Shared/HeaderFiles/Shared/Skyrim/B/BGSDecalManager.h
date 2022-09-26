#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/N/NiColor.h"
#include "Shared/Skyrim/N/NiMatrix33.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	struct BGSDecalGroup;

	class BGSDecalEmitter;
	class BGSDecalNode;
	class BGSTextureSet;
	class BSShaderAccumulator;
	class BSTempEffect;
	class NiAVObject;
	class NiCamera;
	class NiNode;
	class TESObjectCELL;

	class BGSDecalManager :
		BSTSingletonSDM<BGSDecalManager> // 0
	{
	public:
		struct CreationData
		{
		public:
			// Member variables
			NiPoint3              position{ 0.0F, 0.0F, 0.0F };                                     // 0
			NiPoint3              normal{ 0.0F, 0.0F, 0.0F };                                       // C
			NiPoint3              unknown18{ 0.0F, 0.0F, 0.0F };                                    // 18
			ObjectReferenceHandle targetHandle{};                                                   // 24
			NiPointer<NiAVObject> target3D{ nullptr };                                              // 28
			NiNode*               clone{ nullptr };                                                 // 30
			BGSTextureSet*        textureSet1{ nullptr };                                           // 38
			BGSTextureSet*        textureSet2{ nullptr };                                           // 40
			std::uint32_t         unknown48{ static_cast<std::uint32_t>(-1) };                      // 48
			float                 width{ 0.0F };                                                    // 4C
			float                 height{ 0.0F };                                                   // 50
			float                 depth{ 0.0F };                                                    // 54
			NiMatrix33            rotation{ 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F }; // 58
			std::uint32_t         padding7C;                                                        // 7C
			TESObjectCELL*        parentCell{ nullptr };                                            // 80
			float                 parallaxScale{ 0.0F };                                            // 88
			std::uint32_t         padding8C;                                                        // 8C
			NiAVObject*           skinnedDecalNode{ nullptr };                                      // 90
			float                 shininess{ 4.0F };                                                // 98
			float                 angleThreshold{ 15.0F };                                          // 9C
			float                 placementRadius{ 16.0F };                                         // A0
			NiColor               color{ 1.0F, 1.0F, 1.0F };                                        // A4
			std::uint32_t         unknownB0{ 0 };                                                   // B0
			std::int8_t           subtextureIndex{ 0 };                                             // B4
			bool                  permanent{ false };                                               // B5
			std::uint8_t          unknownB6{ 1 };                                                   // B6
			bool                  parallax{ false };                                                // B7
			bool                  alphaTesting{ true };                                             // B8
			bool                  alphaBlending{ false };                                           // B9
			std::uint8_t          parallaxPasses{ 0 };                                              // BA
			std::uint8_t          unknownBB{ 0 };                                                   // BB
			std::uint8_t          unknownBC{ 0 };                                                   // BC
			bool                  twoSided{ false };                                                // BD
			std::uint8_t          unknownBE{ 0 };                                                   // BE
			std::uint8_t          unknownBF{ 0 };                                                   // BF
			std::uint32_t         unknownC0{ 0 };                                                   // C0
			std::uint32_t         paddingC4;                                                        // C4
		};
		static_assert(offsetof(CreationData, position) == 0x0);
		static_assert(offsetof(CreationData, normal) == 0xC);
		static_assert(offsetof(CreationData, targetHandle) == 0x24);
		static_assert(offsetof(CreationData, target3D) == 0x28);
		static_assert(offsetof(CreationData, clone) == 0x30);
		static_assert(offsetof(CreationData, textureSet1) == 0x38);
		static_assert(offsetof(CreationData, textureSet2) == 0x40);
		static_assert(offsetof(CreationData, width) == 0x4C);
		static_assert(offsetof(CreationData, height) == 0x50);
		static_assert(offsetof(CreationData, depth) == 0x54);
		static_assert(offsetof(CreationData, rotation) == 0x58);
		static_assert(offsetof(CreationData, parentCell) == 0x80);
		static_assert(offsetof(CreationData, parallaxScale) == 0x88);
		static_assert(offsetof(CreationData, skinnedDecalNode) == 0x90);
		static_assert(offsetof(CreationData, shininess) == 0x98);
		static_assert(offsetof(CreationData, angleThreshold) == 0x9C);
		static_assert(offsetof(CreationData, placementRadius) == 0xA0);
		static_assert(offsetof(CreationData, color) == 0xA4);
		static_assert(offsetof(CreationData, subtextureIndex) == 0xB4);
		static_assert(offsetof(CreationData, permanent) == 0xB5);
		static_assert(offsetof(CreationData, parallax) == 0xB7);
		static_assert(offsetof(CreationData, alphaTesting) == 0xB8);
		static_assert(offsetof(CreationData, alphaBlending) == 0xB9);
		static_assert(offsetof(CreationData, parallaxPasses) == 0xBA);
		static_assert(offsetof(CreationData, twoSided) == 0xBD);
		static_assert(sizeof(CreationData) == 0xC8);

		struct AdditionData
		{
		public:
			// Member variables
			const CreationData* creationData;               // 0
			bool                forceDecal;                 // 8
			std::uint8_t        unknown9;                   // 9
			std::uint16_t       paddingA;                   // A
			std::uint32_t       decalCount;                 // C
			std::uint32_t       skinDecalCount;             // 10
			std::uint32_t       skinDecalCountCurrentFrame; // 14
			std::uint32_t       decalCountCurrentFrame;     // 18
			std::uint32_t       unknown1C;                  // 1C
			BGSDecalGroup*      decalGroup;                 // 20
		};
		static_assert(offsetof(AdditionData, creationData) == 0x0);
		static_assert(offsetof(AdditionData, forceDecal) == 0x8);
		static_assert(offsetof(AdditionData, decalCount) == 0xC);
		static_assert(offsetof(AdditionData, skinDecalCount) == 0x10);
		static_assert(offsetof(AdditionData, skinDecalCountCurrentFrame) == 0x14);
		static_assert(offsetof(AdditionData, decalCountCurrentFrame) == 0x18);
		static_assert(offsetof(AdditionData, decalGroup) == 0x20);
		static_assert(sizeof(AdditionData) == 0x28);

		// Non-member functions
		static BGSDecalManager* GetSingleton();

		// Member variables
		std::uint8_t                         unknown1;                   // 0
		std::uint16_t                        unknown2;                   // 2
		std::uint32_t                        decalCountCurrentFrame;     // 4
		std::uint32_t                        skinDecalCountCurrentFrame; // 8
		std::uint32_t                        decalCount;                 // C
		std::uint32_t                        skinDecalCount;             // 10
		std::uint8_t                         unknown14;                  // 14
		std::uint8_t                         padding15;                  // 15
		std::uint16_t                        padding16;                  // 16
		BSTArray<NiPointer<BSTempEffect>>    decals;                     // 18
		BSTArray<NiPointer<BGSDecalEmitter>> decalEmitters;              // 30
		BSTArray<NiPointer<BGSDecalNode>>    decalNodes;                 // 48
		std::uint64_t                        unknown60;                  // 60
		std::uint64_t                        unknown68;                  // 68
		std::uint64_t                        unknown70;                  // 70
		NiPointer<NiCamera>                  camera;                     // 78
		NiPointer<BSShaderAccumulator>       shaderAccumulator;          // 80
		std::uint32_t                        unknown88;                  // 88
		std::uint32_t                        padding8C;                  // 8C
	};
	static_assert(offsetof(BGSDecalManager, decalCountCurrentFrame) == 0x4);
	static_assert(offsetof(BGSDecalManager, skinDecalCountCurrentFrame) == 0x8);
	static_assert(offsetof(BGSDecalManager, decalCount) == 0xC);
	static_assert(offsetof(BGSDecalManager, skinDecalCount) == 0x10);
	static_assert(offsetof(BGSDecalManager, decals) == 0x18);
	static_assert(offsetof(BGSDecalManager, decalEmitters) == 0x30);
	static_assert(offsetof(BGSDecalManager, decalNodes) == 0x48);
	static_assert(offsetof(BGSDecalManager, camera) == 0x78);
	static_assert(offsetof(BGSDecalManager, shaderAccumulator) == 0x80);
	static_assert(sizeof(BGSDecalManager) == 0x90);
}
