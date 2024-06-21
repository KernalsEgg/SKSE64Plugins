#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/B/BGSBlockBashData.h"
#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSEquipType.h"
#include "Shared/Skyrim/B/BGSKeywordForm.h"
#include "Shared/Skyrim/B/BGSMessageIcon.h"
#include "Shared/Skyrim/B/BGSPickupPutdownSounds.h"
#include "Shared/Skyrim/B/BGSPreloadable.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/S/SoundLevel.h"
#include "Shared/Skyrim/T/TESAttackDamageForm.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Skyrim/T/TESEnchantableForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESIcon.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESValueForm.h"
#include "Shared/Skyrim/T/TESWeightForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSImpactDataSet;
	class BGSSoundDescriptorForm;
	class SpellItem;
	class TESObjectSTAT;

	class TESObjectWEAP :
		public TESBoundObject,            // 0
		public TESFullName,               // 30
		public TESModelTextureSwap,       // 40
		public TESIcon,                   // 78
		public TESEnchantableForm,        // 88
		public TESValueForm,              // A0
		public TESWeightForm,             // B0
		public TESAttackDamageForm,       // C0
		public BGSDestructibleObjectForm, // D0
		public BGSEquipType,              // E0
		public BGSPreloadable,            // F0
		public BGSMessageIcon,            // F8
		public BGSPickupPutdownSounds,    // 110
		public BGSBlockBashData,          // 128
		public BGSKeywordForm,            // 140
		public TESDescription             // 158
	{
	public:
		enum class OnHit : std::uint32_t
		{
			kNormalFormulaBehavior = 0,
			kDismemberOnly         = 1,
			kExplodeOnly           = 2,
			kNoDismemberExplode    = 3
		};
		static_assert(sizeof(OnHit) == 0x4);

		enum class Flags2 : std::uint16_t
		{
			kNone                                   = 0,
			kPlayerOnly                             = 1U << 0,  // Flags
			kNPCsUseAmmunition                      = 1U << 1,  // Flags
			kNoJamAfterReload                       = 1U << 2,  // Flags (Unused)
			kMinorCrime                             = 1U << 4,  // Flags
			kRangeFixed                             = 1U << 5,  // Game Data, Range
			kNotUsedInNormalCombat                  = 1U << 6,  // Flags
			kDontUseThirdPersonImageSpaceAnimations = 1U << 8,  // Art and Sound, Animation (Unused)
			kBurstShot                              = 1U << 9,  // Game Data
			kFiringRumbleAlternative                = 1U << 10, // Rumble, Firing Rumble
			kLongBursts                             = 1U << 11, // Game Data
			kNonHostile                             = 1U << 12, // Flags
			kBoundWeapon                            = 1U << 13  // Flags
		};
		static_assert(sizeof(Flags2) == 0x2);

		enum class AttackAnimation : std::uint8_t
		{
			kAttackLeft   = 26,
			kAttackRight  = 32,
			kAttack3      = 38,
			kAttack4      = 44,
			kAttack5      = 50,
			kAttack7      = 62,
			kAttack8      = 68,
			kAttackLoop   = 74,
			kAttackSpin   = 80,
			kAttackSpin2  = 86,
			kPlaceMine    = 97,
			kPlaceMine2   = 103,
			kAttackThrow  = 109,
			kAttackThrow2 = 115,
			kAttackThrow3 = 121,
			kAttackThrow4 = 127,
			kAttackThrow5 = 133,
			kDefault      = 255
		};
		static_assert(sizeof(AttackAnimation) == 0x1);

		enum class AnimationType : std::uint8_t
		{
			kHandToHandMelee = 0,
			kOneHandSword    = 1,
			kOneHandDagger   = 2,
			kOneHandAxe      = 3,
			kOneHandMace     = 4,
			kTwoHandSword    = 5,
			kTwoHandAxe      = 6,
			kBow             = 7,
			kStaff           = 8,
			kCrossbow        = 9
		};
		static_assert(sizeof(AnimationType) == 0x1);

		enum class Flags : std::uint8_t
		{
			kNone                                   = 0,
			kIgnoresNormalWeaponResistance          = 1U << 0, // Flags
			kAutomatic                              = 1U << 1, // Flags
			kHasScope                               = 1U << 2, // Art and Sound
			kCantDrop                               = 1U << 3, // Flags
			kHideBackpack                           = 1U << 4, // Flags (Unused)
			kEmbeddedWeapon                         = 1U << 5, // Game Data (Unused)
			kDontUseThirdPersonImageSpaceAnimations = 1U << 6, // Art and Sound, Animation (Unused)
			kNonPlayable                            = 1U << 7  // Flags
		};
		static_assert(sizeof(Flags) == 0x1);

		enum class CriticalFlags : std::uint8_t
		{
			kNone    = 0,
			kOnDeath = 1U << 0
		};
		static_assert(sizeof(CriticalFlags) == 0x1);

		struct FiringRumble
		{
		public:
			enum class Pattern : std::uint32_t
			{
			};
			static_assert(sizeof(Pattern) == 0x4);

			// Member variables
			float                                        leftMotorStrength;  // 0
			float                                        rightMotorStrength; // 4
			float                                        duration;           // 8
			Utility::Enumeration<Pattern, std::uint32_t> pattern;            // C
		};
		static_assert(offsetof(FiringRumble, leftMotorStrength) == 0x0);
		static_assert(offsetof(FiringRumble, rightMotorStrength) == 0x4);
		static_assert(offsetof(FiringRumble, duration) == 0x8);
		static_assert(offsetof(FiringRumble, pattern) == 0xC);
		static_assert(sizeof(FiringRumble) == 0x10);

		struct RangedData
		{
		public:
			// Member variables
			float         sightFOV;        // 0, Game Data
			std::uint32_t unknown16C;      // 4
			FiringRumble  firingRumble;    // 8, Rumble
			std::uint8_t  projectileCount; // 18, Game Data
			std::uint8_t  padding181;      // 19
			std::uint16_t padding182;      // 1A
		};
		static_assert(offsetof(RangedData, sightFOV) == 0x0);
		static_assert(offsetof(RangedData, firingRumble) == 0x8);
		static_assert(offsetof(RangedData, projectileCount) == 0x18);
		static_assert(sizeof(RangedData) == 0x1C);

		struct Range
		{
		public:
			// Member variables
			float minimum; // 0
			float maximum; // 4
		};
		static_assert(offsetof(Range, minimum) == 0x0);
		static_assert(offsetof(Range, maximum) == 0x4);
		static_assert(sizeof(Range) == 0x8);

		// Override
		virtual ~TESObjectWEAP() override; // 0

		// Override (TESBoundObject)
		virtual void InitializeData() override;                                                                                                       // 4
		virtual void ClearData() override;                                                                                                            // 5
		virtual bool Load(TESFile* file) override;                                                                                                    // 6
		virtual void SaveGame(BGSSaveFormBuffer* saveFormBuffer) override;                                                                            // E
		virtual void LoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                                            // F
		virtual void Unknown13(TESForm*) override;                                                                                                    // 13
		virtual void Unknown14(TESForm*) override;                                                                                                    // 14
		virtual bool IsPlayable() const override;                                                                                                     // 19
		virtual bool Activate(TESObjectREFR* target, TESObjectREFR* activator, bool deferred, TESBoundObject* item, std::int32_t itemCount) override; // 37
		virtual void Unknown39(TESForm*) override;                                                                                                    // 39

		// Override (BGSPreloadable)
		virtual void Unknown4(BGSPreloadable*) override; // 4

		// Override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override; // 5

		// Non-member functions
		static TESObjectWEAP* GetUnarmedWeapon();

		// Member variables
		RangedData*                                         rangedData;                   // 168
		float                                               speed;                        // 170, Game Data
		float                                               reach;                        // 174, Game Data
		Range                                               range;                        // 178, Game Data
		float                                               animationAttackMultiplier;    // 180, Art and Sound, Animation
		std::uint32_t                                       damageToWeaponMultiplier;     // 184
		float                                               stagger;                      // 188, Game Data
		Utility::Enumeration<OnHit, std::uint32_t>          onHit;                        // 18C, Game Data
		Utility::Enumeration<ActorValue, std::uint32_t>     skill;                        // 190
		Utility::Enumeration<ActorValue, std::uint32_t>     resistance;                   // 194, Game Data
		Utility::Enumeration<Flags2, std::uint16_t>         weaponFlags2;                 // 198
		std::uint8_t                                        baseVATSToHitChance;          // 19A, Game Data
		Utility::Enumeration<AttackAnimation, std::uint8_t> attackAnimation;              // 19B, Art and Sound, Animation
		Utility::Enumeration<ActorValue, std::uint8_t>      embeddedWeaponActorValue;     // 19C, Game Data, Embedded Weapon (Unused)
		Utility::Enumeration<AnimationType, std::uint8_t>   animationType;                // 19D, Art and Sound, Anim Type
		Utility::Enumeration<Flags, std::uint8_t>           weaponFlags;                  // 19E
		std::uint8_t                                        padding19F;                   // 19F
		float                                               criticalPercentageMultiplier; // 1A0, Game Data
		std::uint32_t                                       padding1A4;                   // 1A4
		SpellItem*                                          criticalEffect;               // 1A8, Game Data
		std::uint16_t                                       criticalDamage;               // 1B0, Game Data
		Utility::Enumeration<CriticalFlags, std::uint8_t>   criticalFlags;                // 1B2, Game Data
		std::uint8_t                                        padding1B3;                   // 1B3
		std::uint32_t                                       padding1B4;                   // 1B4
		std::uint64_t                                       unknown1B8;                   // 1B8
		BGSSoundDescriptorForm*                             attackSound;                  // 1C0, Art and Sound
		BGSSoundDescriptorForm*                             attackSound2D;                // 1C8, Art and Sound
		BGSSoundDescriptorForm*                             attackLoop;                   // 1D0, Art and Sound
		BGSSoundDescriptorForm*                             attackFail;                   // 1D8, Art and Sound
		BGSSoundDescriptorForm*                             idleSound;                    // 1E0, Art and Sound
		BGSSoundDescriptorForm*                             equipSound;                   // 1E8, Art and Sound
		BGSSoundDescriptorForm*                             unequipSound;                 // 1F0, Art and Sound
		BGSImpactDataSet*                                   impactDataSet;                // 1F8, Art and Sound
		TESObjectSTAT*                                      firstPersonModelObject;       // 200, Art and Sound, Model
		TESObjectWEAP*                                      templateWeapon;               // 208
		BSFixedString                                       embeddedWeaponNode;           // 210, Game Data, Embedded Weapon
		Utility::Enumeration<SoundLevel, std::uint32_t>     detectionSoundLevel;          // 218, Art and Sound
		std::uint32_t                                       padding21C;                   // 21C
	};
	static_assert(offsetof(TESObjectWEAP, rangedData) == 0x168);
	static_assert(offsetof(TESObjectWEAP, speed) == 0x170);
	static_assert(offsetof(TESObjectWEAP, reach) == 0x174);
	static_assert(offsetof(TESObjectWEAP, range) == 0x178);
	static_assert(offsetof(TESObjectWEAP, animationAttackMultiplier) == 0x180);
	static_assert(offsetof(TESObjectWEAP, damageToWeaponMultiplier) == 0x184);
	static_assert(offsetof(TESObjectWEAP, stagger) == 0x188);
	static_assert(offsetof(TESObjectWEAP, onHit) == 0x18C);
	static_assert(offsetof(TESObjectWEAP, skill) == 0x190);
	static_assert(offsetof(TESObjectWEAP, resistance) == 0x194);
	static_assert(offsetof(TESObjectWEAP, weaponFlags2) == 0x198);
	static_assert(offsetof(TESObjectWEAP, baseVATSToHitChance) == 0x19A);
	static_assert(offsetof(TESObjectWEAP, attackAnimation) == 0x19B);
	static_assert(offsetof(TESObjectWEAP, embeddedWeaponActorValue) == 0x19C);
	static_assert(offsetof(TESObjectWEAP, animationType) == 0x19D);
	static_assert(offsetof(TESObjectWEAP, weaponFlags) == 0x19E);
	static_assert(offsetof(TESObjectWEAP, criticalPercentageMultiplier) == 0x1A0);
	static_assert(offsetof(TESObjectWEAP, criticalEffect) == 0x1A8);
	static_assert(offsetof(TESObjectWEAP, criticalDamage) == 0x1B0);
	static_assert(offsetof(TESObjectWEAP, criticalFlags) == 0x1B2);
	static_assert(offsetof(TESObjectWEAP, attackSound) == 0x1C0);
	static_assert(offsetof(TESObjectWEAP, attackSound2D) == 0x1C8);
	static_assert(offsetof(TESObjectWEAP, attackLoop) == 0x1D0);
	static_assert(offsetof(TESObjectWEAP, attackFail) == 0x1D8);
	static_assert(offsetof(TESObjectWEAP, idleSound) == 0x1E0);
	static_assert(offsetof(TESObjectWEAP, equipSound) == 0x1E8);
	static_assert(offsetof(TESObjectWEAP, unequipSound) == 0x1F0);
	static_assert(offsetof(TESObjectWEAP, impactDataSet) == 0x1F8);
	static_assert(offsetof(TESObjectWEAP, firstPersonModelObject) == 0x200);
	static_assert(offsetof(TESObjectWEAP, templateWeapon) == 0x208);
	static_assert(offsetof(TESObjectWEAP, embeddedWeaponNode) == 0x210);
	static_assert(offsetof(TESObjectWEAP, detectionSoundLevel) == 0x218);
	static_assert(sizeof(TESObjectWEAP) == 0x220);
}
