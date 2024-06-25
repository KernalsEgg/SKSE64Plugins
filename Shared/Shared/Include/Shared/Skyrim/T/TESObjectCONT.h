#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSOpenCloseForm.h"
#include "Shared/Skyrim/T/TESBoundAnimObject.h"
#include "Shared/Skyrim/T/TESContainer.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESMagicCasterForm.h"
#include "Shared/Skyrim/T/TESMagicTargetForm.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESWeightForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSSoundDescriptorForm;

	class TESObjectCONT :
		public TESBoundAnimObject,        // 0
		public TESContainer,              // 30
		public TESFullName,               // 48
		public TESModelTextureSwap,       // 58
		public TESWeightForm,             // 90
		public BGSDestructibleObjectForm, // A0
		public BGSOpenCloseForm,          // B0
		public TESMagicCasterForm,        // B8
		public TESMagicTargetForm         // B9
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kRandomAnimationStart                            = 1U << 16,
			kObstacle                                        = 1U << 25,
			kNavigationMeshGenerationImportOptionFilter      = 1U << 26,
			kNavigationMeshGenerationImportOptionBoundingBox = 1U << 27,
			kNavigationMeshGenerationImportOptionGround      = 1U << 30

			//kNavigationMeshGenerationImportOptionCollisionGeometry
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		enum class Flags : std::uint8_t
		{
			kNone                                    = 0,
			kAllowSoundsWhenContainerAnimationsExist = 1U << 0,
			kRespawns                                = 1U << 1,
			kShowOwner                               = 1U << 2
		};
		static_assert(sizeof(Flags) == 0x1);

		struct Sounds
		{
		public:
			// Member variables
			BGSSoundDescriptorForm* open;  // 0
			BGSSoundDescriptorForm* close; // 8
		};
		static_assert(offsetof(Sounds, open) == 0x0);
		static_assert(offsetof(Sounds, close) == 0x8);
		static_assert(sizeof(Sounds) == 0x10);

		// Override
		virtual ~TESObjectCONT() override; // 0

		// Override (TESBoundAnimObject)
		virtual void InitializeData() override;                                                                                                                     // 4
		virtual bool Load(TESFile* file) override;                                                                                                                  // 6
		virtual void Unknown13(TESForm*) override;                                                                                                                  // 13
		virtual bool Activate(TESObjectREFR* target, TESObjectREFR* activator, bool deferred, TESBoundObject* boundObject, std::int32_t boundObjectCount) override; // 37
		virtual void Unknown4C(TESBoundObject*) override;                                                                                                           // 4C
		virtual void Unknown4D(TESBoundObject*) override;                                                                                                           // 4D

		// Override (BGSOpenCloseForm)
		virtual void HandleOpen(TESObjectREFR* target, TESObjectREFR* activator) override;  // 1
		virtual void HandleClose(TESObjectREFR* target, TESObjectREFR* activator) override; // 2
		virtual void Unknown3(BGSOpenCloseForm*) override;                                  // 3

		// Member variables
		Utility::Enumeration<Flags, std::uint8_t> containerFlags; // B9
		std::uint16_t                             paddingBA;      // BA
		std::uint32_t                             paddingBC;      // BC
		Sounds                                    sounds;         // C0
	};
	static_assert(offsetof(TESObjectCONT, containerFlags) == 0xB9);
	static_assert(offsetof(TESObjectCONT, sounds) == 0xC0);
	static_assert(sizeof(TESObjectCONT) == 0xD0);
}
