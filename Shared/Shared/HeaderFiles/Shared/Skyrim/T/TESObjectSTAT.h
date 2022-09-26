#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"



namespace Skyrim
{
	class BGSMaterialObject;

	class TESObjectSTAT :
		public TESBoundObject,     // 0
		public TESModelTextureSwap // 30
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kNeverFades                                      = 1U << 2,
			kHasTreeLOD                                      = 1U << 6,
			kAddonLODObject                                  = 1U << 7,
			kHiddenOnLocalMap                                = 1U << 9,
			kHasDistantLOD                                   = 1U << 15,
			kUsesHighDetailLODTexture                        = 1U << 17,
			kHasCurrents                                     = 1U << 19,
			kIsMarker                                        = 1U << 23,
			kObstacle                                        = 1U << 25,
			kNavigationMeshGenerationImportOptionFilter      = 1U << 26,
			kNavigationMeshGenerationImportOptionBoundingBox = 1U << 27,
			kShowInWorldMap                                  = 1U << 28,
			kNavigationMeshGenerationImportOptionGround      = 1U << 30

			// kConsideredSnow
			// kHasPlatformLanguageSpecificTextures
			// kNavigationMeshGenerationImportOptionCollisionGeometry
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		struct DirectionalMaterial
		{
		public:
			// Member variables
			float              maximumAngle;        // 0
			std::uint32_t      padding4;            // 4
			BGSMaterialObject* directionalMaterial; // 8
		};
		static_assert(offsetof(DirectionalMaterial, maximumAngle) == 0x0);
		static_assert(offsetof(DirectionalMaterial, directionalMaterial) == 0x8);
		static_assert(sizeof(DirectionalMaterial) == 0x10);

		// Override
		virtual ~TESObjectSTAT() override; // 0

		// Override (TESBoundObject)
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13
		virtual bool IsPlayable() const override;  // 19
		virtual void Unknown1A(TESForm*) override; // 1A

		// Member variables
		DirectionalMaterial directionalMaterial; // 68
		std::uint64_t       unknown10;           // 78
	};
	static_assert(offsetof(TESObjectSTAT, directionalMaterial) == 0x68);
	static_assert(sizeof(TESObjectSTAT) == 0x80);
}
