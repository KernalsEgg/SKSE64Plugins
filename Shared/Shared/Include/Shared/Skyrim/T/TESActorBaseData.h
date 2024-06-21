#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/F/FactionRank.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSVoiceType;
	class TESForm;
	class TESLevItem;

	class TESActorBaseData :
		public BaseFormComponent // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                             = 0,
			kFemale                           = 1U << 0, // Traits
			kEssential                        = 1U << 1,
			kIsCharacterGenerationFacePreset  = 1U << 2,
			kRespawn                          = 1U << 3,
			kAutomaticallyCalculateStatistics = 1U << 4, // Stats
			kUnique                           = 1U << 5,
			kDoesntAffectStealthMeter         = 1U << 6,
			kPlayerLevelMultiplier            = 1U << 7, // Stats, Leveling Data
			kProtected                        = 1U << 11,
			kSummonable                       = 1U << 14,
			kDoesntBleed                      = 1U << 16,
			kBleedoutOverride                 = 1U << 18, // Stats
			kOppositeGenderAnimations         = 1U << 19, // Traits
			kSimpleActor                      = 1U << 20,
			kIsGhost                          = 1U << 29,
			kInvulnerable                     = 1U << 31
		};
		static_assert(sizeof(Flags) == 0x4);

		enum class TemplateDataFlags : std::uint16_t
		{
			kNone                  = 0,
			kUseTraits             = 1U << 0,
			kUseStatistics         = 1U << 1,
			kUseFactions           = 1U << 2,
			kUseSpellList          = 1U << 3,
			kUseAIData             = 1U << 4,
			kUseAIPackages         = 1U << 5,
			kUseBaseData           = 1U << 7,
			kUseInventory          = 1U << 8,
			kUseScript             = 1U << 9,
			kUseDefaultPackageList = 1U << 10,
			kUseAttackData         = 1U << 11,
			kUseKeywords           = 1U << 12
		};
		static_assert(sizeof(TemplateDataFlags) == 0x2);

		struct LevelingData
		{
		public:
			// Member variables
			std::uint16_t level;            // 0
			std::uint16_t calculateMinimum; // 2
			std::uint16_t calculateMaximum; // 4
		};
		static_assert(offsetof(LevelingData, level) == 0x0);
		static_assert(offsetof(LevelingData, calculateMinimum) == 0x2);
		static_assert(offsetof(LevelingData, calculateMaximum) == 0x4);
		static_assert(sizeof(LevelingData) == 0x6);

		// Override
		virtual ~TESActorBaseData() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual void          Unknown4(TESActorBaseData*); // 4
		virtual bool          IsGhost() const;             // 5
		virtual bool          IsInvulnerable() const;      // 6
		virtual void          Unknown7(TESActorBaseData*); // 7
		virtual BGSVoiceType* GetVoiceType();              // 8

		// Member variables
		Utility::Enumeration<Flags, std::uint32_t>             actorBaseDataFlags; // 8
		std::int16_t                                           magickaOffset;      // C, Stats
		std::int16_t                                           staminaOffset;      // E, Stats
		LevelingData                                           levelingData;       // 10, Stats
		std::uint16_t                                          speed;              // 16, Stats
		std::uint16_t                                          dispositionBase;    // 18, Traits
		Utility::Enumeration<TemplateDataFlags, std::uint16_t> templateDataFlags;  // 1A
		std::int16_t                                           healthOffset;       // 1C, Stats
		std::uint16_t                                          bleedoutOverride;   // 1E, Stats
		TESLevItem*                                            deathItem;          // 20, Traits
		BGSVoiceType*                                          voiceType;          // 28, Traits
		TESForm*                                               actorBaseTemplate;  // 30, Template Data
		TESForm**                                              templates;          // 38
		BSTArray<FactionRank>                                  factions;           // 40, Factions
	};
	static_assert(offsetof(TESActorBaseData, actorBaseDataFlags) == 0x8);
	static_assert(offsetof(TESActorBaseData, magickaOffset) == 0xC);
	static_assert(offsetof(TESActorBaseData, staminaOffset) == 0xE);
	static_assert(offsetof(TESActorBaseData, levelingData) == 0x10);
	static_assert(offsetof(TESActorBaseData, speed) == 0x16);
	static_assert(offsetof(TESActorBaseData, dispositionBase) == 0x18);
	static_assert(offsetof(TESActorBaseData, templateDataFlags) == 0x1A);
	static_assert(offsetof(TESActorBaseData, healthOffset) == 0x1C);
	static_assert(offsetof(TESActorBaseData, bleedoutOverride) == 0x1E);
	static_assert(offsetof(TESActorBaseData, deathItem) == 0x20);
	static_assert(offsetof(TESActorBaseData, voiceType) == 0x28);
	static_assert(offsetof(TESActorBaseData, actorBaseTemplate) == 0x30);
	static_assert(offsetof(TESActorBaseData, templates) == 0x38);
	static_assert(offsetof(TESActorBaseData, factions) == 0x40);
	static_assert(sizeof(TESActorBaseData) == 0x58);
}
