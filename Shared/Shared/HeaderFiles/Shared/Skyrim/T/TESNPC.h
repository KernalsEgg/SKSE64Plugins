#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSOverridePackCollection.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/C/Color.h"
#include "Shared/Skyrim/S/Skill.h"
#include "Shared/Skyrim/S/SoundLevel.h"
#include "Shared/Skyrim/T/TESActorBase.h"
#include "Shared/Skyrim/T/TESRaceForm.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class BGSColorForm;
	class BGSHeadPart;
	class BGSListForm;
	class BGSOutfit;
	class BGSRelationship;
	class BGSTextureSet;
	class TESClass;
	class TESFaction;
	class TESObjectARMO;
	class TESRace;

	struct MenuOpenCloseEvent;

	class TESNPC :
		public TESActorBase,              // 0
		public TESRaceForm,               // 150
		public BGSOverridePackCollection, // 160
		public BSTEventSink<MenuOpenCloseEvent>
	{
	public:
		struct CreatureSounds;

		union Sounds
		{
		public:
			// Member variables
			TESNPC*         inheritsSoundsFrom;
			CreatureSounds* creatureSounds;
		};
		static_assert(sizeof(Sounds) == 0x8);

		struct Skills
		{
		public:
			std::uint8_t values[Utility::ToUnderlying(Skill::kTotal)];  // 0
			std::uint8_t offsets[Utility::ToUnderlying(Skill::kTotal)]; // 12
		};
		static_assert(offsetof(Skills, values) == 0x0);
		static_assert(offsetof(Skills, offsets) == 0x12);
		static_assert(sizeof(Skills) == 0x24);

		struct FaceGenerationColor
		{
		public:
			// Member variables
			BGSColorForm*  hairColor;      // 0
			BGSTextureSet* faceComplexion; // 8
		};
		static_assert(offsetof(FaceGenerationColor, hairColor) == 0x0);
		static_assert(offsetof(FaceGenerationColor, faceComplexion) == 0x8);
		static_assert(sizeof(FaceGenerationColor) == 0x10);

		struct CharacterGenerationMorphs
		{
		public:
			enum class Morph
			{
				kNoseLength      = 0,
				kNoseHeight      = 1,
				kJawHeight       = 2,
				kJawWidth        = 3,
				kJawDepth        = 4,
				kCheekboneHeight = 5,
				kCheekboneWidth  = 6,
				kEyesHeight      = 7,
				kEyesDepth       = 8,
				kBrowHeight      = 9,
				kBrowDepth       = 10,
				kBrowWidth       = 11,
				kMouthHeight     = 12,
				kMouthDepth      = 13,
				kChinWidth       = 14,
				kChinLength      = 15,
				kChinDepth       = 16,
				kEyesWidth       = 17,
				kTotal           = 19
			};

			enum class FacePart
			{
				kNose  = 0,
				kEyes  = 2,
				kMouth = 3,
				kTotal = 4
			};

			// Member variables
			float        morphs[Utility::ToUnderlying(Morph::kTotal)];       // 0
			std::int32_t faceParts[Utility::ToUnderlying(FacePart::kTotal)]; // 4C
		};
		static_assert(offsetof(CharacterGenerationMorphs, morphs) == 0x0);
		static_assert(offsetof(CharacterGenerationMorphs, faceParts) == 0x4C);
		static_assert(sizeof(CharacterGenerationMorphs) == 0x5C);

		struct FaceTintLayer
		{
		public:
			// Member variables
			Color         faceTintingColor;       // 0
			std::uint16_t index;                  // 4
			std::uint16_t faceTintingColorPreset; // 6
			std::uint16_t interpolationValue;     // 8
			std::uint16_t paddingA;               // A
			std::uint32_t paddingC;               // C
		};
		static_assert(offsetof(FaceTintLayer, faceTintingColor) == 0x0);
		static_assert(offsetof(FaceTintLayer, index) == 0x4);
		static_assert(offsetof(FaceTintLayer, faceTintingColorPreset) == 0x6);
		static_assert(offsetof(FaceTintLayer, interpolationValue) == 0x8);
		static_assert(sizeof(FaceTintLayer) == 0x10);

		// Override
		virtual ~TESNPC() override; // 0

		// Override (TESActorBase)
		virtual void            Unknown4(TESForm*) override;                          // 4
		virtual void            Unknown5(TESForm*) override;                          // 5
		virtual void            Unknown6(TESForm*) override;                          // 6
		virtual void            UnknownC(TESForm*) override;                          // C
		virtual void            UnknownE(TESForm*) override;                          // E
		virtual void            UnknownF(TESForm*) override;                          // F
		virtual void            Unknown12(TESForm*) override;                         // 12
		virtual void            Unknown13(TESForm*) override;                         // 13
		virtual void            Unknown2E(TESForm*) override;                         // 2E
		virtual void            Unknown2F(TESForm*) override;                         // 2F
		virtual void            Unknown37(TESForm*) override;                         // 37
		virtual void            Unknown41(TESObject*) override;                       // 41
		virtual void            Unknown48(TESBoundObject*) override;                  // 48
		virtual void            Unknown49(TESBoundObject*) override;                  // 49
		virtual void            Unknown4A(TESBoundObject*) override;                  // 4A
		virtual void            Unknown4C(TESBoundObject*) override;                  // 4C
		virtual void            Unknown4D(TESBoundObject*) override;                  // 4D
		virtual TESCombatStyle* GetCombatStyle() override;                            // 54
		virtual void            SetCombatStyle(TESCombatStyle* combatStyle) override; // 55

		// Override (TESActorBaseData)
		virtual void Unknown4(TESActorBaseData*) override; // 4
		virtual void Unknown7(TESActorBaseData*) override; // 7

		// Override (ActorValueOwner)
		virtual float GetActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue) override;              // 1
		virtual void  SetActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float value) override; // 7

		// Override (BSTEventSink<MenuOpenCloseEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* eventArguments, BSTEventSource<MenuOpenCloseEvent>* eventSource) override; // 1

		// Member variables
		Skills                                         skills;                    // 190, Stats
		std::uint16_t                                  calculatedHealth;          // 1B4, Stats
		std::uint16_t                                  calculatedMagicka;         // 1B6, Stats
		std::uint16_t                                  calculatedStamina;         // 1B8, Stats
		std::uint16_t                                  padding1BA;                // 1BA
		float                                          farAwayModelDistance;      // 1BC, Traits, Far Away Model
		TESClass*                                      npcClass;                  // 1C0, Stats
		FaceGenerationColor*                           faceGenerationColor;       // 1C8, Character Gen Parts
		BGSListForm*                                   giftFilter;                // 1D0, AI Data, AI Attributes
		TESCombatStyle*                                combatStyle;               // 1D8, AI Data, AI Attributes
		std::uint32_t                                  fileOffset;                // 1E0
		std::uint32_t                                  padding1E4;                // 1E4
		TESRace*                                       originalRace;              // 1E8, Traits
		TESNPC*                                        faceGenerationNPC;         // 1F0 (Traits template NPC)
		float                                          height;                    // 1F8, Traits
		float                                          weight;                    // 1FC, Traits
		Sounds                                         sounds;                    // 200
		BSFixedString                                  shortName;                 // 208
		TESObjectARMO*                                 farAwayModelSkin;          // 210
		BGSOutfit*                                     defaultOutfit;             // 218, Inventory
		BGSOutfit*                                     sleepOutfit;               // 220, Inventory
		BGSListForm*                                   defaultPackageList;        // 228, AI Packages
		TESFaction*                                    assignedCrimeFaction;      // 230, Factions
		BGSHeadPart**                                  headParts;                 // 238, Character Gen Parts
		std::int8_t                                    headPartCount;             // 240, Character Gen Parts
		std::uint8_t                                   unknown241;                // 241
		std::uint16_t                                  unknown242;                // 242
		std::uint8_t                                   unknown244;                // 244
		Utility::Enumeration<SoundLevel, std::uint8_t> soundLevel;                // 245, Sounds
		Color                                          faceTintingColor;          // 246, Character Gen Parts, Face Tinting Color
		std::uint16_t                                  padding24A;                // 24A
		std::uint32_t                                  padding24C;                // 24C
		BSTArray<BGSRelationship*>*                    relationships;             // 250
		CharacterGenerationMorphs*                     characterGenerationMorphs; // 258
		BSTArray<FaceTintLayer*>*                      faceTintLayers;            // 260, Character Gen Parts
	};
	static_assert(offsetof(TESNPC, skills) == 0x190);
	static_assert(offsetof(TESNPC, calculatedHealth) == 0x1B4);
	static_assert(offsetof(TESNPC, calculatedMagicka) == 0x1B6);
	static_assert(offsetof(TESNPC, calculatedStamina) == 0x1B8);
	static_assert(offsetof(TESNPC, farAwayModelDistance) == 0x1BC);
	static_assert(offsetof(TESNPC, npcClass) == 0x1C0);
	static_assert(offsetof(TESNPC, faceGenerationColor) == 0x1C8);
	static_assert(offsetof(TESNPC, giftFilter) == 0x1D0);
	static_assert(offsetof(TESNPC, combatStyle) == 0x1D8);
	static_assert(offsetof(TESNPC, fileOffset) == 0x1E0);
	static_assert(offsetof(TESNPC, originalRace) == 0x1E8);
	static_assert(offsetof(TESNPC, faceGenerationNPC) == 0x1F0);
	static_assert(offsetof(TESNPC, height) == 0x1F8);
	static_assert(offsetof(TESNPC, weight) == 0x1FC);
	static_assert(offsetof(TESNPC, sounds) == 0x200);
	static_assert(offsetof(TESNPC, shortName) == 0x208);
	static_assert(offsetof(TESNPC, farAwayModelSkin) == 0x210);
	static_assert(offsetof(TESNPC, defaultOutfit) == 0x218);
	static_assert(offsetof(TESNPC, sleepOutfit) == 0x220);
	static_assert(offsetof(TESNPC, defaultPackageList) == 0x228);
	static_assert(offsetof(TESNPC, assignedCrimeFaction) == 0x230);
	static_assert(offsetof(TESNPC, headParts) == 0x238);
	static_assert(offsetof(TESNPC, headPartCount) == 0x240);
	static_assert(offsetof(TESNPC, soundLevel) == 0x245);
	static_assert(offsetof(TESNPC, faceTintingColor) == 0x246);
	static_assert(offsetof(TESNPC, relationships) == 0x250);
	static_assert(offsetof(TESNPC, characterGenerationMorphs) == 0x258);
	static_assert(offsetof(TESNPC, faceTintLayers) == 0x260);
	static_assert(sizeof(TESNPC) == 0x268);
}
