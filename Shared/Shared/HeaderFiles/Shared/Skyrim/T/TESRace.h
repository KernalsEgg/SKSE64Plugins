#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/A/AttackAnimationArrayMap.h"
#include "Shared/Skyrim/B/BGSAttackDataForm.h"
#include "Shared/Skyrim/B/BGSBehaviorGraphModel.h"
#include "Shared/Skyrim/B/BGSBipedObjectForm.h"
#include "Shared/Skyrim/B/BGSKeywordForm.h"
#include "Shared/Skyrim/B/BGSSkinForm.h"
#include "Shared/Skyrim/B/BGSTextureModel.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BipedObjectSlot.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/S/Sex.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Skyrim/T/TESSpellList.h"
#include "Shared/Skyrim/T/TESTexture.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSArtObject;
	class BGSBodyPartData;
	class BGSColorForm;
	class BGSEquipSlot;
	class BGSHeadPart;
	class BGSImpactDataSet;
	class BGSMaterialType;
	class BGSMovementType;
	class BGSSoundDescriptorForm;
	class BGSTextureSet;
	class BGSVoiceType;
	class TESNPC;
	class TESObjectARMO;

	class TESRace :
		public TESForm,            // 0
		public TESFullName,        // 20
		public TESDescription,     // 30
		public TESSpellList,       // 40
		public BGSSkinForm,        // 50
		public BGSBipedObjectForm, // 60
		public BGSKeywordForm,     // 70
		public BGSAttackDataForm   // 88
	{
	public:
		enum
		{
			kSkillBonusCount = 7
		};

		enum class Flags : std::uint32_t
		{
			kNone                         = 0,
			kPlayable                     = 1U << 0,  // General Data
			kFaceGenerationHead           = 1U << 1,  // General Data
			kChild                        = 1U << 2,  // General Data
			kTiltFrontBack                = 1U << 3,  // General Data
			kTiltLeftRight                = 1U << 4,  // General Data
			kNoShadow                     = 1U << 5,  // General Data
			kSwims                        = 1U << 6,  // General Data, Movement
			kFlies                        = 1U << 7,  // General Data, Movement
			kWalks                        = 1U << 8,  // General Data, Movement
			kImmobile                     = 1U << 9,  // General Data, Movement
			kNotPushable                  = 1U << 10, // General Data, Movement
			kNoCombatInWater              = 1U << 11, // General Data, Movement
			kNoRotatingToHeadTrack        = 1U << 12, // General Data, Movement
			kNoBloodSpray                 = 1U << 13, // Blood, When we are hit
			kNoBloodDecal                 = 1U << 14, // Blood, When we are hit
			kUsesHeadTrackAnimations      = 1U << 15, // General Data, Movement
			kSpellsAlignWithMagicNode     = 1U << 16, // General Data
			kUseWorldRaycastsForFootIK    = 1U << 17, // General Data
			kAllowRagdollCollision        = 1U << 18, // General Data
			kRegenerateHealthInCombat     = 1U << 19, // General Data
			kCantOpenDoors                = 1U << 20, // General Data
			kAllowPlayerDialogue          = 1U << 21, // General Data
			kNoKnockdowns                 = 1U << 22, // General Data
			kAllowPickpocket              = 1U << 23, // General Data
			kAlwaysUseProxyController     = 1U << 24, // General Data
			kNoWeaponBlood                = 1U << 25, // Blood, When we are hit
			kOverlayHeadPartList          = 1U << 26, // Face Data
			kOverrideHeadPartList         = 1U << 27, // Face Data
			kCanPickupItems               = 1U << 28, // Combat Data
			kAllowMultipleMembraneShaders = 1U << 29, // General Data
			kCanDualWield                 = 1U << 30, // Combat Data
			kAvoidsRoads                  = 1U << 31  // General Data, Movement
		};
		static_assert(sizeof(Flags) == 0x4);

		enum class MoveType
		{
			kWalk   = 0,
			kRun    = 1,
			kSwim   = 2,
			kFly    = 3,
			kSneak  = 4,
			kSprint = 5,
			kTotal  = 6
		};

		enum class Size : std::uint32_t
		{
			kSmall      = 0,
			kMedium     = 1,
			kLarge      = 2,
			kExtraLarge = 3
		};
		static_assert(sizeof(Size) == 0x4);

		enum class Flags2 : std::uint32_t
		{
			kNone                 = 0,
			kUseAdvancedAvoidance = 1U << 0, // Move Data
			kNonHostile           = 1U << 1, // Combat Data
			kAllowMountedCombat   = 1U << 4, // General Data, Mount Data
		};
		static_assert(sizeof(Flags2) == 0x4);

		enum class EquipTypes : std::uint32_t
		{
			kNone            = 0,
			kHandToHandMelee = 1U << 0,
			kOneHandSword    = 1U << 1,
			kOneHandDagger   = 1U << 2,
			kOneHandAxe      = 1U << 3,
			kOneHandMace     = 1U << 4,
			kTwoHandSword    = 1U << 5,
			kTwoHandAxe      = 1U << 6,
			kBow             = 1U << 7,
			kStaff           = 1U << 8,
			kSpell           = 1U << 9,
			kShield          = 1U << 10,
			kTorch           = 1U << 11,
			kCrossbow        = 1U << 12
		};
		static_assert(sizeof(EquipTypes) == 0x4);

		struct SkillBonus
		{
		public:
			// Member variables
			Utility::Enumeration<ActorValue, std::uint8_t> skill; // 0
			std::uint8_t                                   bonus; // 1
		};
		static_assert(offsetof(SkillBonus, skill) == 0x0);
		static_assert(offsetof(SkillBonus, bonus) == 0x1);
		static_assert(sizeof(SkillBonus) == 0x2);

		struct CopiedData
		{
		public:
			// Member variables
			TESRace* morphRace; // 0
			TESRace* armorRace; // 8
		};
		static_assert(offsetof(CopiedData, morphRace) == 0x0);
		static_assert(offsetof(CopiedData, armorRace) == 0x8);
		static_assert(sizeof(CopiedData) == 0x10);

		struct CharacterGenerationData
		{
		public:
			struct Morph
			{
			public:
				enum
				{
					kNose  = 0,
					kBrow  = 1,
					kEyes  = 2,
					kMouth = 3,
					kTotal = 4
				};

				// Member variables
				std::uint64_t unknown0;  // 0
				std::uint64_t unknown8;  // 8
				std::uint64_t unknown10; // 10
				std::uint64_t unknown18; // 18
			};
			static_assert(sizeof(Morph) == 0x20);

			struct Tinting
			{
			public:
				struct TintLayer
				{
				public:
					enum class MaskType : std::uint8_t
					{
						kNone            = 0,
						kLipColor        = 1,
						kCheekColor      = 2,
						kEyeliner        = 3,
						kEyeSocketUpper  = 4,
						kEyeSocketLower  = 5,
						kSkinTone        = 6,
						kPaint           = 7,
						kLaughLines      = 8,
						kCheekColorLower = 9,
						kNose            = 10,
						kChin            = 11,
						kNeck            = 12,
						kForehead        = 13,
						kDirt            = 14
					};
					static_assert(sizeof(MaskType) == 0x1);

					// Member variables
					std::uint16_t                                index;         // 0
					Utility::Enumeration<MaskType, std::uint8_t> maskType;      // 2
					std::uint8_t                                 padding3;      // 3
					std::uint32_t                                padding4;      // 4
					TESTexture                                   texture;       // 8
					BGSColorForm*                                defaultPreset; // 18
				};
				static_assert(offsetof(TintLayer, index) == 0x0);
				static_assert(offsetof(TintLayer, maskType) == 0x2);
				static_assert(offsetof(TintLayer, texture) == 0x8);
				static_assert(offsetof(TintLayer, defaultPreset) == 0x18);
				static_assert(sizeof(TintLayer) == 0x20);

				struct Presets
				{
				public:
					// Member variables
					BSTArray<BGSColorForm*> colors;        // 0, Tinting, Presets
					BSTArray<float>         defaultValues; // 18, Tinting, Presets
					BSTArray<std::uint16_t> indices;       // 30, Tinting, Presets
				};
				static_assert(offsetof(Presets, colors) == 0x0);
				static_assert(offsetof(Presets, defaultValues) == 0x18);
				static_assert(offsetof(Presets, indices) == 0x30);
				static_assert(sizeof(Presets) == 0x48);

				// Member variables
				TintLayer tintLayer; // 0
				Presets   presets;   // 20
			};
			static_assert(offsetof(Tinting, tintLayer) == 0x0);
			static_assert(offsetof(Tinting, presets) == 0x20);
			static_assert(sizeof(Tinting) == 0x68);

			// Member variables
			Morph                     availableMorphs[Morph::kTotal];     // 0, Face Data
			std::uint32_t             availableMorphFlags[Morph::kTotal]; // 80, Face Data
			BSTArray<Tinting*>*       tinting;                            // 90, Tinting
			BSTArray<BGSTextureSet*>* faceDetailsTextureSetList;          // 98, Tinting
			BGSTextureSet*            defaultFaceDetailsTextureSet;       // A0, Tinting
			BSTArray<TESNPC*>*        presetNPCs;                         // A8, Preset NPCs
			BSTArray<BGSColorForm*>*  availableHairColors;                // B0, Face Data
			BGSColorForm*             defaultHairColor;                   // B8, Face Data
			BSTArray<BGSHeadPart*>*   headParts;                          // C0, Face Data
		};
		static_assert(offsetof(CharacterGenerationData, availableMorphs) == 0x0);
		static_assert(offsetof(CharacterGenerationData, availableMorphFlags) == 0x80);
		static_assert(offsetof(CharacterGenerationData, tinting) == 0x90);
		static_assert(offsetof(CharacterGenerationData, faceDetailsTextureSetList) == 0x98);
		static_assert(offsetof(CharacterGenerationData, defaultFaceDetailsTextureSet) == 0xA0);
		static_assert(offsetof(CharacterGenerationData, presetNPCs) == 0xA8);
		static_assert(offsetof(CharacterGenerationData, availableHairColors) == 0xB0);
		static_assert(offsetof(CharacterGenerationData, defaultHairColor) == 0xB8);
		static_assert(offsetof(CharacterGenerationData, headParts) == 0xC0);
		static_assert(sizeof(CharacterGenerationData) == 0xC8);

		// Override
		virtual ~TESRace() override; // 0

		// Override (TESForm)
		virtual void        Unknown4(TESForm*) override;                // 4
		virtual void        Unknown5(TESForm*) override;                // 5
		virtual void        Unknown6(TESForm*) override;                // 6
		virtual void        Unknown13(TESForm*) override;               // 13
		virtual bool        IsPlayable() const override;                // 19
		virtual const char* GetEditorID() const override;               // 32
		virtual bool        SetEditorID(const char* editorID) override; // 33

		// Member variables
		TESModel                                             skeletons[Utility::ToUnderlying(Sex::kTotal)];                               // 98, Body Data
		SkillBonus                                           skillBonuses[TESRace::kSkillBonusCount];                                     // E8, General Data
		std::uint16_t                                        paddingF6;                                                                   // F6
		float                                                heights[Utility::ToUnderlying(Sex::kTotal)];                                 // F8, Body Data
		float                                                weights[Utility::ToUnderlying(Sex::kTotal)];                                 // 100, Body Data
		Utility::Enumeration<Flags, std::uint32_t>           raceFlags;                                                                   // 108
		float                                                startingHealth;                                                              // 10C, General Data
		float                                                startingMagicka;                                                             // 110, General Data
		float                                                startingStamina;                                                             // 114, General Data
		float                                                baseCarryWeight;                                                             // 118, General Data
		float                                                baseMass;                                                                    // 11C, Body Data
		float                                                accelerationRate;                                                            // 120, Move Data
		float                                                decelerationRate;                                                            // 124, Move Data
		Utility::Enumeration<Size, std::uint32_t>            size;                                                                        // 128, General Data
		Utility::Enumeration<BipedObjectSlot, std::uint32_t> headBipedObject;                                                             // 12C, Face Data
		Utility::Enumeration<BipedObjectSlot, std::uint32_t> hairBipedObject;                                                             // 130, Face Data
		float                                                injuredHealthPercentage;                                                     // 134, Combat Data
		Utility::Enumeration<BipedObjectSlot, std::uint32_t> shieldBipedObject;                                                           // 138, Body Data
		float                                                healthRegeneration;                                                          // 13C, General Data
		float                                                magickaRegeneration;                                                         // 140, General Data
		float                                                staminaRegeneration;                                                         // 144, General Data
		float                                                unarmedDamage;                                                               // 148, Combat Data
		float                                                unarmedReach;                                                                // 14C, Combat Data
		Utility::Enumeration<BipedObjectSlot, std::uint32_t> bodyBipedObject;                                                             // 150, Body Data
		float                                                aimAngleTolerance;                                                           // 154, Combat Data
		float                                                flightRadius;                                                                // 158, General Data
		float                                                angularAccelerationRate;                                                     // 15C, Move Data
		float                                                angularTolerance;                                                            // 160, Move Data
		Utility::Enumeration<Flags2, std::uint32_t>          raceFlags2;                                                                  // 164
		NiPoint3                                             mountOffsets;                                                                // 168, General Data, Mount Data
		NiPoint3                                             dismountOffsets;                                                             // 174
		NiPoint3                                             mountCameraOffsets;                                                          // 180
		std::uint32_t                                        unknown18C;                                                                  // 18C
		std::uint32_t                                        unknown190;                                                                  // 190
		std::uint32_t                                        padding194;                                                                  // 194
		BGSTextureModel                                      bodyTextures[Utility::ToUnderlying(Sex::kTotal)];                            // 198, Body Data
		BGSBehaviorGraphModel                                behaviorGraphs[Utility::ToUnderlying(Sex::kTotal)];                          // 1E8, Body Data
		BSFixedString                                        behaviorGraphRootNames[Utility::ToUnderlying(Sex::kTotal)];                  // 238
		BSFixedString                                        behaviorGraphProjectNames[Utility::ToUnderlying(Sex::kTotal)];               // 248
		BGSVoiceType*                                        defaultVoiceTypes[Utility::ToUnderlying(Sex::kTotal)];                       // 258, Body Data
		BGSBodyPartData*                                     bodyPartData;                                                                // 268, Body Data
		TESObjectARMO*                                       decapitateArmor[Utility::ToUnderlying(Sex::kTotal)];                         // 270, Body Data
		std::uint64_t                                        unknown280;                                                                  // 280
		std::uint64_t                                        unknown288;                                                                  // 288
		std::uint64_t                                        unknown290;                                                                  // 290
		std::uint64_t                                        unknown298;                                                                  // 298
		std::uint64_t                                        unknown2A0;                                                                  // 2A0
		std::uint64_t                                        unknown2A8;                                                                  // 2A8
		std::uint64_t                                        unknown2B0;                                                                  // 2B0
		std::uint64_t                                        unknown2B8;                                                                  // 2B8
		std::uint64_t                                        unknown2C0;                                                                  // 2C0
		std::uint64_t                                        unknown2C8;                                                                  // 2C8
		AttackAnimationArrayMap*                             attacks[Utility::ToUnderlying(Sex::kTotal)];                                 // 2D0, Attack Data
		BSFixedString                                        editorID;                                                                    // 2E0
		BGSMaterialType*                                     impactMaterialType;                                                          // 2E8, Blood, When we are hit
		BGSImpactDataSet*                                    impactDataSet;                                                               // 2F0, Blood, When we hit something else
		BGSArtObject*                                        decapitateBloodArt;                                                          // 2F8, Blood, When we are hit
		BGSSoundDescriptorForm*                              openCorse;                                                                   // 300, Blood, Sounds made when looted
		BGSSoundDescriptorForm*                              closeCorpse;                                                                 // 308, Blood, Sounds made when looted
		BSFixedString                                        bipedObjectNames[Utility::ToUnderlying(BipedObjectSlot::kCreationKitTotal)]; // 310
		BSTArray<BGSEquipSlot*>                              equipSlots;                                                                  // 410, Combat Data, Equipment Restrictions
		Utility::Enumeration<EquipTypes, std::uint32_t>      equipTypes;                                                                  // 428, Combat Data, Equipment Restrictions
		std::uint32_t                                        unknown42C;                                                                  // 42C
		BGSEquipSlot*                                        unarmedEquipSlot;                                                            // 430, Combat Data
		CopiedData                                           copiedData;                                                                  // 438, General Data
		std::uint64_t                                        unknown448;                                                                  // 448
		std::uint64_t                                        unknown450;                                                                  // 450
		std::uint64_t                                        unknown458;                                                                  // 458
		BSTArray<BSFixedString>                              phonemeTargets;                                                              // 460, Phoneme Mapping
		BGSMovementType*                                     baseMovementDefaults[Utility::ToUnderlying(MoveType::kTotal)];               // 478, Move Data
		CharacterGenerationData*                             characterGenerationData[Utility::ToUnderlying(Sex::kTotal)];                 // 4A8
	};
	static_assert(offsetof(TESRace, skeletons) == 0x98);
	static_assert(offsetof(TESRace, skillBonuses) == 0xE8);
	static_assert(offsetof(TESRace, heights) == 0xF8);
	static_assert(offsetof(TESRace, weights) == 0x100);
	static_assert(offsetof(TESRace, raceFlags) == 0x108);
	static_assert(offsetof(TESRace, startingHealth) == 0x10C);
	static_assert(offsetof(TESRace, startingMagicka) == 0x110);
	static_assert(offsetof(TESRace, startingStamina) == 0x114);
	static_assert(offsetof(TESRace, baseCarryWeight) == 0x118);
	static_assert(offsetof(TESRace, baseMass) == 0x11C);
	static_assert(offsetof(TESRace, accelerationRate) == 0x120);
	static_assert(offsetof(TESRace, decelerationRate) == 0x124);
	static_assert(offsetof(TESRace, size) == 0x128);
	static_assert(offsetof(TESRace, headBipedObject) == 0x12C);
	static_assert(offsetof(TESRace, hairBipedObject) == 0x130);
	static_assert(offsetof(TESRace, injuredHealthPercentage) == 0x134);
	static_assert(offsetof(TESRace, shieldBipedObject) == 0x138);
	static_assert(offsetof(TESRace, healthRegeneration) == 0x13C);
	static_assert(offsetof(TESRace, magickaRegeneration) == 0x140);
	static_assert(offsetof(TESRace, staminaRegeneration) == 0x144);
	static_assert(offsetof(TESRace, unarmedDamage) == 0x148);
	static_assert(offsetof(TESRace, unarmedReach) == 0x14C);
	static_assert(offsetof(TESRace, bodyBipedObject) == 0x150);
	static_assert(offsetof(TESRace, aimAngleTolerance) == 0x154);
	static_assert(offsetof(TESRace, flightRadius) == 0x158);
	static_assert(offsetof(TESRace, angularAccelerationRate) == 0x15C);
	static_assert(offsetof(TESRace, angularTolerance) == 0x160);
	static_assert(offsetof(TESRace, raceFlags2) == 0x164);
	static_assert(offsetof(TESRace, mountOffsets) == 0x168);
	static_assert(offsetof(TESRace, dismountOffsets) == 0x174);
	static_assert(offsetof(TESRace, mountCameraOffsets) == 0x180);
	static_assert(offsetof(TESRace, bodyTextures) == 0x198);
	static_assert(offsetof(TESRace, behaviorGraphs) == 0x1E8);
	static_assert(offsetof(TESRace, behaviorGraphRootNames) == 0x238);
	static_assert(offsetof(TESRace, behaviorGraphProjectNames) == 0x248);
	static_assert(offsetof(TESRace, defaultVoiceTypes) == 0x258);
	static_assert(offsetof(TESRace, bodyPartData) == 0x268);
	static_assert(offsetof(TESRace, decapitateArmor) == 0x270);
	static_assert(offsetof(TESRace, attacks) == 0x2D0);
	static_assert(offsetof(TESRace, editorID) == 0x2E0);
	static_assert(offsetof(TESRace, impactMaterialType) == 0x2E8);
	static_assert(offsetof(TESRace, impactDataSet) == 0x2F0);
	static_assert(offsetof(TESRace, decapitateBloodArt) == 0x2F8);
	static_assert(offsetof(TESRace, openCorse) == 0x300);
	static_assert(offsetof(TESRace, closeCorpse) == 0x308);
	static_assert(offsetof(TESRace, bipedObjectNames) == 0x310);
	static_assert(offsetof(TESRace, equipSlots) == 0x410);
	static_assert(offsetof(TESRace, equipTypes) == 0x428);
	static_assert(offsetof(TESRace, unarmedEquipSlot) == 0x430);
	static_assert(offsetof(TESRace, copiedData) == 0x438);
	static_assert(offsetof(TESRace, phonemeTargets) == 0x460);
	static_assert(offsetof(TESRace, baseMovementDefaults) == 0x478);
	static_assert(offsetof(TESRace, characterGenerationData) == 0x4A8);
	static_assert(sizeof(TESRace) == 0x4B8);
}
