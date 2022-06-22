#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSKeywordForm.h"
#include "Shared/Skyrim/B/BGSOpenCloseForm.h"
#include "Shared/Skyrim/T/TESBoundAnimObject.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESMagicTargetForm.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSSoundDescriptorForm;
	class TESWaterForm;

	class TESObjectACTI :
		public TESBoundAnimObject,        // 0
		public TESFullName,               // 30
		public TESModelTextureSwap,       // 40
		public BGSDestructibleObjectForm, // 78
		public BGSOpenCloseForm,          // 88
		public BGSKeywordForm,            // 90
		public TESMagicTargetForm         // A8
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kHasTreeLOD                                      = 1U << 6,
			kMustUpdateAnimations                            = 1U << 8,
			kHiddenOnLocalMap                                = 1U << 9,
			kRandomAnimationStart                            = 1U << 16,
			kDangerous                                       = 1U << 17,
			kIgnoreObjectInteraction                         = 1U << 20,
			kIsMarker                                        = 1U << 23,
			kObstacle                                        = 1U << 25,
			kNavigationMeshGenerationImportOptionFilter      = 1U << 26,
			kNavigationMeshGenerationImportOptionBoundingBox = 1U << 27,
			kChildCanUse                                     = 1U << 29,
			kNavigationMeshGenerationImportOptionGround      = 1U << 30

			//kHasPlatformLanguageSpecificTextures
			//kNavigationMeshGenerationImportOptionCollisionGeometry
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		enum class Flags : std::uint16_t
		{
			kNone             = 0,
			kNoDisplacement   = 1U << 0,
			kIgnoredBySandbox = 1U << 1
		};
		static_assert(sizeof(Flags) == 0x2);

		struct Sounds
		{
		public:
			// Member variables
			BGSSoundDescriptorForm* looping;  // 0
			BGSSoundDescriptorForm* activate; // 8
		};
		static_assert(offsetof(Sounds, looping) == 0x0);
		static_assert(offsetof(Sounds, activate) == 0x8);
		static_assert(sizeof(Sounds) == 0x10);

		// Override
		virtual ~TESObjectACTI() override; // 0

		// Override (TESBoundAnimObject)
		virtual void InitializeData() override;                                                                                                       // 4
		virtual void ClearData() override;                                                                                                            // 5
		virtual void Unknown6(TESForm*) override;                                                                                                     // 6
		virtual void UnknownE(TESForm*) override;                                                                                                     // E
		virtual void UnknownF(TESForm*) override;                                                                                                     // F
		virtual void Unknown13(TESForm*) override;                                                                                                    // 13
		virtual void Unknown22(TESForm*) override;                                                                                                    // 22
		virtual bool IsWater() const override;                                                                                                        // 2A
		virtual bool Activate(TESObjectREFR* target, TESObjectREFR* activator, bool deferred, TESBoundObject* item, std::int32_t itemCount) override; // 37
		virtual void Unknown3D(TESObject*) override;                                                                                                  // 3D
		virtual void Unknown4C(TESBoundObject*) override;                                                                                             // 4C
		virtual void Unknown4D(TESBoundObject*) override;                                                                                             // 4D

		// Member variables
		Sounds                                     sounds;         // A8
		TESWaterForm*                              waterType;      // B8
		Utility::Enumeration<Flags, std::uint16_t> activatorFlags; // C0
		std::uint16_t                              paddingC2;      // C2
		std::uint32_t                              paddingC4;      // C4
	};
	static_assert(offsetof(TESObjectACTI, sounds) == 0xA8);
	static_assert(offsetof(TESObjectACTI, waterType) == 0xB8);
	static_assert(offsetof(TESObjectACTI, activatorFlags) == 0xC0);
	static_assert(sizeof(TESObjectACTI) == 0xC8);
}
