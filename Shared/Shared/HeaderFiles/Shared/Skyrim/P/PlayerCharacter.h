#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/A/AITimeStamp.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Skyrim/B/BSTHashMap.h"
#include "Shared/Skyrim/C/Character.h"
#include "Shared/Skyrim/D/Difficulty.h"
#include "Shared/Skyrim/H/hkReferencePointer.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct BGSActorCellEvent;
	struct BGSActorDeathEvent;
	struct MenuModeChangeEvent;
	struct MenuOpenCloseEvent;
	struct PerkRank;
	struct PositionPlayerEvent;
	struct TESQuestStageItem;
	struct TESTrackedStatisticsEvent;
	struct UserEventEnabledEvent;

	class AlchemyItem;
	class BGSLocation;
	class BGSPerk;
	class BGSTextureSet;
	class bhkMouseSpringAction;
	class BSLight;
	class NiNode;
	class TESFaction;
	class TESRace;
	class TintMask;

	struct CrimeGold
	{
	public:
		// Member variables
		float currentViolent;    // 0
		float currentNonViolent; // 4
		float infamyNonViolent;  // 8
		float infamyViolent;     // C
	};
	static_assert(offsetof(CrimeGold, currentViolent) == 0x0);
	static_assert(offsetof(CrimeGold, currentNonViolent) == 0x4);
	static_assert(offsetof(CrimeGold, infamyNonViolent) == 0x8);
	static_assert(offsetof(CrimeGold, infamyViolent) == 0xC);
	static_assert(sizeof(CrimeGold) == 0x10);

	struct StolenItemValue
	{
	public:
		// Member variables
		std::int32_t noCrime; // 0
		std::int32_t crime;   // 4
	};
	static_assert(offsetof(StolenItemValue, noCrime) == 0x0);
	static_assert(offsetof(StolenItemValue, crime) == 0x4);
	static_assert(sizeof(StolenItemValue) == 0x8);

	class PlayerCharacter :
		public Character,                               // 0
		public BSTEventSink<MenuOpenCloseEvent>,        // 2B0, 2B8
		public BSTEventSink<MenuModeChangeEvent>,       // 2B8, 2C0
		public BSTEventSink<UserEventEnabledEvent>,     // 2C0, 2C8
		public BSTEventSink<TESTrackedStatisticsEvent>, // 2C8, 2D0
		public BSTEventSource<BGSActorCellEvent>,       // 2D0, 2D8
		public BSTEventSource<BGSActorDeathEvent>,      // 328, 330
		public BSTEventSource<PositionPlayerEvent>      // 380, 388
	{
	public:
		enum class GrabType : std::uint32_t
		{
			kNone        = 0,
			kNormal      = 1,
			kTelekinesis = 2
		};
		static_assert(sizeof(GrabType) == 0x4);

		enum class CharacterGenerationFlags : std::uint8_t
		{
			kNone       = 0,
			kHandsBound = 1U << 2
		};
		static_assert(sizeof(CharacterGenerationFlags) == 0x1);

		enum class FlagsBE3 : std::uint8_t
		{
			kNone                                          = 0,
			kThirdPerson                                   = 1U << 0,
			kShownInsufficientWeaponChargeMessageLeftHand  = 1U << 2,
			kShownInsufficientWeaponChargeMessageRightHand = 1U << 3,
			kInCombat                                      = 1U << 5
		};
		static_assert(sizeof(FlagsBE3) == 0x1);

		// Override
		virtual ~PlayerCharacter() override; // 0

		// Override (Character)
		virtual void                              SaveGame(BGSSaveFormBuffer* saveFormBuffer) override;                                                                                               // E
		virtual void                              LoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                               // F
		virtual void                              InitializeLoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                     // 10
		virtual void                              FinishLoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                         // 11
		virtual void                              Revert(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                                 // 12
		virtual void                              Unknown46(TESObjectREFR*) override;                                                                                                                 // 46
		virtual void                              Unknown47(TESObjectREFR*) override;                                                                                                                 // 47
		virtual void                              Unknown55(TESObjectREFR*) override;                                                                                                                 // 55
		virtual NiPoint3                          GetLookingAtLocation() const override;                                                                                                              // 5B
		virtual void                              Unknown6A(TESObjectREFR*) override;                                                                                                                 // 6A
		virtual void                              Unknown6C(TESObjectREFR*) override;                                                                                                                 // 6C
		virtual NiAVObject*                       Get3D(bool firstPerson) const override;                                                                                                             // 6F
		virtual NiAVObject*                       GetThirdPerson3D() const override;                                                                                                                  // 70
		virtual void                              Unknown71(TESObjectREFR*) override;                                                                                                                 // 71
		virtual void                              Unknown72(TESObjectREFR*) override;                                                                                                                 // 72
		virtual void                              Unknown79(TESObjectREFR*) override;                                                                                                                 // 79
		virtual void                              Unknown7D(TESObjectREFR*) override;                                                                                                                 // 7D
		virtual const BSTSmartPointer<BipedAnim>& GetBiped(bool firstPerson) const override;                                                                                                          // 7E
		virtual const BSTSmartPointer<BipedAnim>& GetThirdPersonBiped() const override;                                                                                                               // 7F
		virtual const BSTSmartPointer<BipedAnim>& GetCurrentBiped() const override;                                                                                                                   // 80
		virtual void                              Unknown82(TESObjectREFR*) override;                                                                                                                 // 82
		virtual void                              Unknown86(TESObjectREFR*) override;                                                                                                                 // 86
		virtual NiAVObject*                       GetCurrent3D() const override;                                                                                                                      // 8D
		virtual void                              Unknown98(TESObjectREFR*) override;                                                                                                                 // 98
		virtual void                              Unknown9C(TESObjectREFR*) override;                                                                                                                 // 9C
		virtual void                              UnknownA0(TESObjectREFR*) override;                                                                                                                 // A0
		virtual void                              UnknownA2(Actor*) override;                                                                                                                         // A2
		virtual void                              UnknownA3(Actor*) override;                                                                                                                         // A3
		virtual void                              UnknownA4(Actor*) override;                                                                                                                         // A4
		virtual void                              UnknownA6(Actor*) override;                                                                                                                         // A6
		virtual void                              UnknownAB(Actor*) override;                                                                                                                         // AB
		virtual void                              UnknownAD(Actor*) override;                                                                                                                         // AD
		virtual void                              UnknownAF(Actor*) override;                                                                                                                         // AF
		virtual void                              UnknownB0(Actor*) override;                                                                                                                         // B0
		virtual void                              UnknownB2(Actor*) override;                                                                                                                         // B2
		virtual void                              UnknownB3(Actor*) override;                                                                                                                         // B3
		virtual void                              UnknownB4(Actor*) override;                                                                                                                         // B4
		virtual void                              UnknownB5(Actor*) override;                                                                                                                         // B5
		virtual void                              UnknownB6(Actor*) override;                                                                                                                         // B6
		virtual void                              UnknownB7(Actor*) override;                                                                                                                         // B7
		virtual void                              UnknownB8(Actor*) override;                                                                                                                         // B8
		virtual void                              UnknownB9(Actor*) override;                                                                                                                         // B9
		virtual void                              UnknownBA(Actor*) override;                                                                                                                         // BA
		virtual void                              UnknownBB(Actor*) override;                                                                                                                         // BB
		virtual void                              UnknownBC(Actor*) override;                                                                                                                         // BC
		virtual void                              UnknownBD(Actor*) override;                                                                                                                         // BD
		virtual void                              UnknownBE(Actor*) override;                                                                                                                         // BE
		virtual void                              UnknownBF(Actor*) override;                                                                                                                         // BF
		virtual void                              UnknownC0(Actor*) override;                                                                                                                         // C0
		virtual void                              UnknownC1(Actor*) override;                                                                                                                         // C1
		virtual void                              UnknownC2(Actor*) override;                                                                                                                         // C2
		virtual void                              UnknownC3(Actor*) override;                                                                                                                         // C3
		virtual void                              UnknownC6(Actor*) override;                                                                                                                         // C6
		virtual void                              UnknownC9(Actor*) override;                                                                                                                         // C9
		virtual ObjectReferenceHandle             DropItem(TESBoundObject* item, ExtraDataList* extraDataList, std::uint32_t itemCount, const NiPoint3* position, const NiPoint3* rotation) override; // CB
		virtual void                              UnknownCC(Actor*) override;                                                                                                                         // CC
		virtual void                              UnknownCD(Actor*) override;                                                                                                                         // CD
		virtual void                              UnknownCE(Actor*) override;                                                                                                                         // CE
		virtual void                              UnknownCF(Actor*) override;                                                                                                                         // CF
		virtual void                              UnknownD0(Actor*) override;                                                                                                                         // D0
		virtual void                              UnknownD1(Actor*) override;                                                                                                                         // D1
		virtual void                              UnknownD2(Actor*) override;                                                                                                                         // D2
		virtual void                              UnknownD4(Actor*) override;                                                                                                                         // D4
		virtual void                              UnknownD5(Actor*) override;                                                                                                                         // D5
		virtual void                              UnknownD6(Actor*) override;                                                                                                                         // D6
		virtual void                              UnknownD8(Actor*) override;                                                                                                                         // D8
		virtual void                              UnknownDA(Actor*) override;                                                                                                                         // DA
		virtual void                              UnknownDC(Actor*) override;                                                                                                                         // DC
		virtual void                              UnknownDE(Actor*) override;                                                                                                                         // DE
		virtual void                              UnknownE0(Actor*) override;                                                                                                                         // E0
		virtual void                              UnknownE3(Actor*) override;                                                                                                                         // E3
		virtual void                              UnknownE4(Actor*) override;                                                                                                                         // E4
		virtual void                              UnknownE5(Actor*) override;                                                                                                                         // E5
		virtual void                              UnknownEF(Actor*) override;                                                                                                                         // EF
		virtual void                              UnknownF0(Actor*) override;                                                                                                                         // F0
		virtual void                              UnknownF5(Actor*) override;                                                                                                                         // F5
		virtual void                              UnknownF6(Actor*) override;                                                                                                                         // F6
		virtual void                              UnknownF7(Actor*) override;                                                                                                                         // F7
		virtual void                              UnknownF9(Actor*) override;                                                                                                                         // F9
		virtual void                              ForEachPerk(PerkEntryVisitor& perkEntryVisitor) const override;                                                                                     // FA
		virtual void                              UnknownFB(Actor*) override;                                                                                                                         // FB
		virtual void                              UnknownFC(Actor*) override;                                                                                                                         // FC
		virtual void                              UnknownFD(Actor*) override;                                                                                                                         // FD
		virtual void                              UnknownFE(Actor*) override;                                                                                                                         // FE
		virtual void                              ApplyBasePerks() override;                                                                                                                          // 101
		virtual void                              Unknown102(Actor*) override;                                                                                                                        // 102
		virtual void                              Unknown103(Actor*) override;                                                                                                                        // 103
		virtual void                              Unknown105(Actor*) override;                                                                                                                        // 105
		virtual void                              Unknown109(Actor*) override;                                                                                                                        // 109
		virtual void                              Unknown10E(Actor*) override;                                                                                                                        // 10E
		virtual void                              Unknown10F(Actor*) override;                                                                                                                        // 10F
		virtual void                              Unknown110(Actor*) override;                                                                                                                        // 110
		virtual void                              Unknown112(Actor*) override;                                                                                                                        // 112
		virtual void                              Unknown113(Actor*) override;                                                                                                                        // 113
		virtual void                              Unknown114(Actor*) override;                                                                                                                        // 114
		virtual void                              Unknown117(Actor*) override;                                                                                                                        // 117
		virtual void                              Unknown118(Actor*) override;                                                                                                                        // 118
		virtual void                              Unknown119(Actor*) override;                                                                                                                        // 119
		virtual void                              Unknown11A(Actor*) override;                                                                                                                        // 11A
		virtual void                              Unknown11B(Actor*) override;                                                                                                                        // 11B
		virtual void                              Unknown11C(Actor*) override;                                                                                                                        // 11C
		virtual void                              Unknown11D(Actor*) override;                                                                                                                        // 11D
		virtual void                              Unknown11F(Actor*) override;                                                                                                                        // 11F
		virtual void                              Unknown121(Actor*) override;                                                                                                                        // 121
		virtual void                              Unknown126(Actor*) override;                                                                                                                        // 126
		virtual void                              Unknown127(Actor*) override;                                                                                                                        // 127
		virtual void                              Unknown129(Character*) override;                                                                                                                    // 129

		// Override (IAnimationGraphManagerHolder)
		virtual void Unknown4(IAnimationGraphManagerHolder*) override; // 4
		virtual void Unknown5(IAnimationGraphManagerHolder*) override; // 5
		virtual void Unknown7(IAnimationGraphManagerHolder*) override; // 7
		virtual void UnknownB(IAnimationGraphManagerHolder*) override; // B

		// Override (MagicTarget)
		virtual bool IsInvulnerable() const override; // 4
		virtual void Unknown8(MagicTarget*) override; // 8

		// Override (ActorValueOwner)
		virtual bool IsPlayerOwner() const override; // 8

		// Override (ActorState)
		virtual void Unknown4(IMovementState*) override; // 4
		virtual void Unknown14(ActorState*) override;    // 14
		virtual void Unknown15(ActorState*) override;    // 15

		// Override (BSTEventSink<MenuOpenCloseEvent>)
		virtual EventNotifyControl ProcessEvent(const MenuOpenCloseEvent* eventArguments, BSTEventSource<MenuOpenCloseEvent>* eventSource) override; // 1

		// Override (BSTEventSink<MenuModeChangeEvent>)
		virtual EventNotifyControl ProcessEvent(const MenuModeChangeEvent* eventArguments, BSTEventSource<MenuModeChangeEvent>* eventSource) override; // 1

		// Override (BSTEventSink<UserEventEnabledEvent>)
		virtual EventNotifyControl ProcessEvent(const UserEventEnabledEvent* eventArguments, BSTEventSource<UserEventEnabledEvent>* eventSource) override; // 1

		// Override (BSTEventSink<TESTrackedStatisticsEvent>)
		virtual EventNotifyControl ProcessEvent(const TESTrackedStatisticsEvent* eventArguments, BSTEventSource<TESTrackedStatisticsEvent>* eventSource) override; // 1

		// Add
		virtual void Unknown12A(PlayerCharacter*); // 12A
		virtual void Unknown12B(PlayerCharacter*); // 12B
		virtual void Unknown12C(PlayerCharacter*); // 12C
		virtual void Unknown12D(PlayerCharacter*); // 12D
		virtual void Unknown12E(PlayerCharacter*); // 12E

		// Non-member functions
		static float            GetDifficultyMultiplier(Utility::Enumeration<Difficulty, std::uint32_t> difficulty, Utility::Enumeration<ActorValue, std::uint32_t> actorValue, bool isPlayer);
		static PlayerCharacter* GetSingleton();

		// Member functions
		Actor* GetActorDoingPlayerCommand() const;
		bool   GetAutomaticAimActor(NiPointer<Actor>& automaticAimActor) const;
		void   ResetInsufficientWeaponChargeMessage(bool leftHand);

		// Member variables
		std::uint64_t                                                unknown3E0;                  // 3D8, 3E0
		BSTHashMap<const TESFaction*, CrimeGold>                     crimeGold;                   // 3E0, 3E8
		BSTHashMap<const TESFaction*, StolenItemValue>               stolenItemValue;             // 410, 418
		ObjectReferenceHandle                                        travelCommandLocationMarker; // 440, 448
		std::uint32_t                                                unknown44C;                  // 444, 44C
		std::uint64_t                                                unknown450;                  // 448, 450
		std::uint64_t                                                unknown458;                  // 450, 458
		std::uint64_t                                                unknown460;                  // 458, 460
		std::uint64_t                                                unknown468;                  // 460, 468
		std::uint64_t                                                unknown470;                  // 468, 470
		std::uint64_t                                                unknown478;                  // 470, 478
		std::uint64_t                                                unknown480;                  // 478, 480
		std::uint64_t                                                unknown488;                  // 480, 488
		std::uint64_t                                                unknown490;                  // 488, 490
		std::uint64_t                                                unknown498;                  // 490, 498
		std::uint64_t                                                unknown4A0;                  // 498, 4A0
		std::uint64_t                                                unknown4A8;                  // 4A0, 4A8
		std::uint64_t                                                unknown4B0;                  // 4A8, 4B0
		BSTArray<PerkRank*>                                          addedPerkRanks;              // 4B0, 4B8
		BSTArray<BGSPerk*>                                           perks;                       // 4C8, 4D0
		BSTArray<BGSPerk*>                                           standingStonePerks;          // 4E0, 4E8
		BSTArray<ObjectReferenceHandle>                              currentMapMarkers;           // 4F8, 500
		std::uint64_t                                                unknown518;                  // 510, 518
		std::uint64_t                                                unknown520;                  // 518, 520
		std::uint64_t                                                unknown528;                  // 520, 528
		BSTArray<ProjectileHandle>                                   runes;                       // 528, 530
		std::uint64_t                                                unknown548;                  // 540, 548
		std::uint64_t                                                unknown550;                  // 548, 550
		std::uint64_t                                                unknown558;                  // 550, 558
		std::uint64_t                                                unknown560;                  // 558, 560
		std::uint64_t                                                unknown568;                  // 560, 568
		std::uint64_t                                                unknown570;                  // 568, 570
		BSSimpleList<TESQuestStageItem*>                             questLogEntries;             // 570, 578
		std::uint64_t                                                unknown588;                  // 580, 588
		std::uint64_t                                                unknown590;                  // 588, 590
		std::uint64_t                                                unknown598;                  // 590, 598
		std::uint64_t                                                unknown5A0;                  // 598, 5A0
		std::uint64_t                                                unknown5A8;                  // 5A0, 5A8
		std::uint64_t                                                unknown5B0;                  // 5A8, 5B0
		std::uint64_t                                                unknown5B8;                  // 5B0, 5B8
		std::uint64_t                                                unknown5C0;                  // 5B8, 5C0
		std::uint64_t                                                unknown5C8;                  // 5C0, 5C8
		std::uint64_t                                                unknown5D0;                  // 5C8, 5D0
		std::uint64_t                                                unknown5D8;                  // 5D0, 5D8
		std::uint64_t                                                unknown5E0;                  // 5D8, 5E0
		std::uint64_t                                                unknown5E8;                  // 5E0, 5E8
		std::uint64_t                                                unknown5F0;                  // 5E8, 5F0
		std::uint64_t                                                unknown5F8;                  // 5F0, 5F8
		std::uint64_t                                                unknown600;                  // 5F8, 600
		std::uint64_t                                                unknown608;                  // 600, 608
		std::uint64_t                                                unknown610;                  // 608, 610
		std::uint64_t                                                unknown618;                  // 610, 618
		std::uint64_t                                                unknown620;                  // 618, 620
		std::uint64_t                                                unknown628;                  // 620, 628
		std::uint64_t                                                unknown630;                  // 628, 630
		std::uint64_t                                                unknown638;                  // 630, 638
		std::uint64_t                                                unknown640;                  // 638, 640
		std::uint64_t                                                unknown648;                  // 640, 648
		std::uint64_t                                                unknown650;                  // 648, 650
		std::uint64_t                                                unknown658;                  // 650, 658
		std::uint64_t                                                unknown660;                  // 658, 660
		std::uint64_t                                                unknown668;                  // 660, 668
		std::uint64_t                                                unknown670;                  // 668, 670
		std::uint64_t                                                unknown678;                  // 670, 678
		std::uint64_t                                                unknown680;                  // 678, 680
		std::uint64_t                                                unknown688;                  // 680, 688
		std::uint64_t                                                unknown690;                  // 688, 690
		std::uint64_t                                                unknown698;                  // 690, 698
		std::uint64_t                                                unknown6A0;                  // 698, 6A0
		std::uint64_t                                                unknown6A8;                  // 6A0, 6A8
		std::uint64_t                                                unknown6B0;                  // 6A8, 6B0
		std::uint64_t                                                unknown6B8;                  // 6B0, 6B8
		std::uint64_t                                                unknown6C0;                  // 6B8, 6C0
		std::uint64_t                                                unknown6C8;                  // 6C0, 6C8
		std::int32_t                                                 stealWarningCount;           // 6C8, 6D0
		float                                                        stealWarningTimer;           // 6CC, 6D4
		std::int32_t                                                 pickpocketWarningCount;      // 6D0, 6D8
		float                                                        pickpocketWarningTimer;      // 6D4, 6DC
		AITimeStamp                                                  warnToLeaveTimeStamp;        // 6D8, 6E0
		std::uint32_t                                                padding6E4;                  // 6DC, 6E4
		std::uint64_t                                                unknown6E8;                  // 6E0, 6E8
		std::uint64_t                                                unknown6F0;                  // 6E8, 6F0
		std::uint64_t                                                unknown6F8;                  // 6F0, 6F8
		std::uint64_t                                                unknown700;                  // 6F8, 700
		std::uint64_t                                                unknown708;                  // 700, 708
		std::uint64_t                                                unknown710;                  // 708, 710
		std::uint64_t                                                unknown718;                  // 710, 718
		TESFaction*                                                  currentJailFaction;          // 718, 720
		std::int32_t                                                 jailSentence;                // 720, 728
		std::uint32_t                                                padding72C;                  // 724, 72C
		std::uint64_t                                                unknown730;                  // 728, 730
		std::uint64_t                                                unknown738;                  // 730, 738
		std::uint64_t                                                unknown740;                  // 738, 740
		std::uint64_t                                                unknown748;                  // 740, 748
		std::uint64_t                                                unknown750;                  // 748, 750
		std::uint64_t                                                unknown758;                  // 750, 758
		std::uint64_t                                                unknown760;                  // 758, 760
		std::uint64_t                                                unknown768;                  // 760, 768
		std::uint64_t                                                unknown770;                  // 768, 770
		std::uint64_t                                                unknown778;                  // 770, 778
		std::uint64_t                                                unknown780;                  // 778, 780
		std::uint64_t                                                unknown788;                  // 780, 788
		std::uint64_t                                                unknown790;                  // 788, 790
		std::uint64_t                                                unknown798;                  // 790, 798
		std::uint64_t                                                unknown7A0;                  // 798, 7A0
		std::uint64_t                                                unknown7A8;                  // 7A0, 7A8
		std::uint64_t                                                unknown7B0;                  // 7A8, 7B0
		std::uint64_t                                                unknown7B8;                  // 7B0, 7B8
		std::uint64_t                                                unknown7C0;                  // 7B8, 7C0
		std::uint64_t                                                unknown7C8;                  // 7C0, 7C8
		std::uint64_t                                                unknown7D0;                  // 7C8, 7D0
		std::uint64_t                                                unknown7D8;                  // 7D0, 7D8
		std::uint64_t                                                unknown7E0;                  // 7D8, 7E0
		std::uint64_t                                                unknown7E8;                  // 7E0, 7E8
		std::uint64_t                                                unknown7F0;                  // 7E8, 7F0
		std::uint64_t                                                unknown7F8;                  // 7F0, 7F8
		std::uint64_t                                                unknown800;                  // 7F8, 800
		std::uint64_t                                                unknown808;                  // 800, 808
		std::uint64_t                                                unknown810;                  // 808, 810
		std::uint64_t                                                unknown818;                  // 810, 818
		std::uint64_t                                                unknown820;                  // 818, 820
		std::uint64_t                                                unknown828;                  // 820, 828
		std::uint64_t                                                unknown830;                  // 828, 830
		std::uint64_t                                                unknown838;                  // 830, 838
		std::uint64_t                                                unknown840;                  // 838, 840
		std::uint64_t                                                unknown848;                  // 840, 848
		std::uint64_t                                                unknown850;                  // 848, 850
		std::uint64_t                                                unknown858;                  // 850, 858
		std::uint64_t                                                unknown860;                  // 858, 860
		std::uint64_t                                                unknown868;                  // 860, 868
		std::uint64_t                                                unknown870;                  // 868, 870
		std::uint64_t                                                unknown878;                  // 870, 878
		std::uint64_t                                                unknown880;                  // 878, 880
		std::uint64_t                                                unknown888;                  // 880, 888
		std::uint64_t                                                unknown890;                  // 888, 890
		std::uint32_t                                                unknown898;                  // 890, 898
		ActorHandle                                                  actorDoingPlayerCommand;     // 894, 89C
		BSTSmallArray<hkReferencePointer<bhkMouseSpringAction>, 4>   grabSpringActions;           // 898, 8A0
		ObjectReferenceHandle                                        grabbedReference;            // 8C8, 8D0
		float                                                        grabbedReferenceWeight;      // 8CC, 8D4
		float                                                        grabbedReferenceDistance;    // 8D0, 8D8
		std::uint32_t                                                unknown8DC;                  // 8D4, 8DC
		std::uint64_t                                                unknown8E0;                  // 8D8, 8E0
		std::uint64_t                                                unknown8E8;                  // 8E0, 8E8
		std::uint64_t                                                unknown8F0;                  // 8E8, 8F0
		NiPointer<NiNode>                                            firstPerson3D;               // 8F0, 8F8
		std::uint64_t                                                unknown900;                  // 8F8, 900
		float                                                        overencumberedTimer;         // 900, 908
		float                                                        powerAttackTimer;            // 904, 90C
		std::uint32_t                                                unknown910;                  // 908, 910
		std::int32_t                                                 amountStolenSold;            // 90C, 914
		std::uint32_t                                                unknown918;                  // 910, 918
		ActorHandle                                                  lastRiddenMount;             // 914, 91C
		std::uint64_t                                                unknown920;                  // 918, 920
		std::uint64_t                                                unknown928;                  // 920, 928
		std::uint64_t                                                unknown930;                  // 928, 930
		std::uint64_t                                                unknown938;                  // 930, 938
		std::uint64_t                                                unknown940;                  // 938, 940
		std::uint64_t                                                unknown948;                  // 940, 948
		std::uint64_t                                                unknown950;                  // 948, 950
		std::uint64_t                                                unknown958;                  // 950, 958
		std::uint64_t                                                unknown960;                  // 958, 960
		std::uint64_t                                                unknown968;                  // 960, 968
		AlchemyItem*                                                 pendingWeaponPoison;         // 968, 970
		std::uint64_t                                                unknown978;                  // 970, 978
		std::uint64_t                                                unknown980;                  // 978, 980
		std::uint64_t                                                unknown988;                  // 980, 988
		std::uint64_t                                                unknown990;                  // 988, 990
		std::uint64_t                                                unknown998;                  // 990, 998
		NiPointer<BSLight>                                           firstPersonLight;            // 998, 9A0
		NiPointer<BSLight>                                           thirdPersonLight;            // 9A0, 9A8
		std::uint64_t                                                unknown9B0;                  // 9A8, 9B0
		std::uint64_t                                                unknown9B8;                  // 9B0, 9B8
		ActorHandle                                                  automaticAimActor;           // 9B8, 9C0
		std::uint32_t                                                unknown9C4;                  // 9BC, 9C4
		std::uint64_t                                                unknown9C8;                  // 9C0, 9C8
		std::uint64_t                                                unknown9D0;                  // 9C8, 9D0
		std::uint64_t                                                unknown9D8;                  // 9D0, 9D8
		BSTArray<ActorHandle>                                        hudEnemies;                  // 9D8, 9E0
		std::uint64_t                                                unknown9F8;                  // 9F0, 9F8
		std::uint64_t                                                unknownA00;                  // 9F8, A00
		std::uint64_t                                                unknownA08;                  // A00, A08
		std::uint32_t                                                teammateCount;               // A08, A10
		std::uint32_t                                                unknownA14;                  // A0C, A14
		std::uint64_t                                                unknownA18;                  // A10, A18
		std::uint64_t                                                unknownA20;                  // A18, A20
		std::uint64_t                                                unknownA28;                  // A20, A28
		std::uint64_t                                                unknownA30;                  // A28, A30
		std::uint64_t                                                unknownA38;                  // A30, A38
		std::uint64_t                                                unknownA40;                  // A38, A40
		std::uint64_t                                                unknownA48;                  // A40, A48
		std::uint64_t                                                unknownA50;                  // A48, A50
		std::uint64_t                                                unknownA58;                  // A50, A58
		std::uint64_t                                                unknownA60;                  // A58, A60
		std::uint64_t                                                unknownA68;                  // A60, A68
		std::uint64_t                                                unknownA70;                  // A68, A70
		std::uint64_t                                                unknownA78;                  // A70, A78
		std::uint64_t                                                unknownA80;                  // A78, A80
		std::uint64_t                                                unknownA88;                  // A80, A88
		std::uint64_t                                                unknownA90;                  // A88, A90
		std::uint64_t                                                unknownA98;                  // A90, A98
		std::uint64_t                                                unknownAA0;                  // A98, AA0
		std::uint64_t                                                unknownAA8;                  // AA0, AA8
		std::uint64_t                                                unknownAB0;                  // AA8, AB0
		std::uint64_t                                                unknownAB8;                  // AB0, AB8
		std::uint64_t                                                unknownAC0;                  // AB8, AC0
		std::uint64_t                                                unknownAC8;                  // AC0, AC8
		BGSLocation*                                                 currentLocation;             // AC8, AD0
		std::uint32_t                                                unknownAD8;                  // AD0, AD8
		float                                                        telekinesisDistance;         // AD4, ADC
		float                                                        favorRequestWaitTimer;       // AD8, AE0
		std::uint32_t                                                unknownAE4;                  // ADC, AE4
		std::uint64_t                                                unknownAE8;                  // AE0, AE8
		std::uint64_t                                                unknownAF0;                  // AE8, AF0
		std::uint32_t                                                unknownAF8;                  // AF0, AF8
		Utility::Enumeration<GrabType, std::uint32_t>                grabType;                    // AF4, AFC
		Utility::Enumeration<Difficulty, std::uint32_t>              difficulty;                  // AF8, B00
		std::uint32_t                                                unknownB04;                  // AFC, B04
		std::uint8_t                                                 unknownB08;                  // B00, B08
		std::int8_t                                                  perkCount;                   // B01, B09
		Utility::Enumeration<CharacterGenerationFlags, std::uint8_t> characterGenerationFlags;    // B02, B0A
		std::uint8_t                                                 paddingB0B;                  // B03, B0B
		std::uint32_t                                                unknownB0C;                  // B04, B0C
		std::uint64_t                                                unknownB10;                  // B08, B10
		BSTArray<TintMask*>                                          tintMasks;                   // B10, B18
		BSTArray<TintMask*>*                                         overlayTintMasks;            // B28, B30
		BGSTextureSet*                                               complexion;                  // B30, B38
		TESRace*                                                     characterGenerationRace;     // B38, B40
		std::uint64_t                                                unknownB48;                  // B40, B48
		std::uint64_t                                                unknownB50;                  // B48, B50
		std::uint64_t                                                unknownB58;                  // B50, B58
		std::uint64_t                                                unknownB60;                  // B58, B60
		std::uint64_t                                                unknownB68;                  // B60, B68
		std::uint64_t                                                unknownB70;                  // B68, B70
		std::uint64_t                                                unknownB78;                  // B70, B78
		std::uint64_t                                                unknownB80;                  // B78, B80
		std::uint64_t                                                unknownB88;                  // B80, B88
		std::uint64_t                                                unknownB90;                  // B88, B90
		std::uint64_t                                                unknownB98;                  // B90, B98
		std::uint64_t                                                unknownBA0;                  // B98, BA0
		std::uint64_t                                                unknownBA8;                  // BA0, BA8
		std::uint64_t                                                unknownBB0;                  // BA8, BB0
		std::uint64_t                                                unknownBB8;                  // BB0, BB8
		std::uint64_t                                                unknownBC0;                  // BB8, BC0
		std::uint64_t                                                unknownBC8;                  // BC0, BC8
		std::uint64_t                                                unknownBD0;                  // BC8, BD0
		std::uint64_t                                                unknownBD8;                  // BD0, BD8
		std::uint16_t                                                unknownBE0;                  // BD8, BE0
		std::uint8_t                                                 unknownBE2;                  // BDA, BE2
		Utility::Enumeration<FlagsBE3, std::uint8_t>                 flagsBE3;                    // BDB, BE3
		std::uint32_t                                                unknownBE4;                  // BDC, BE4
	};
	static_assert(offsetof(PlayerCharacter, crimeGold) == SKYRIM_RELOCATE(0x3E0, 0x3E8));
	static_assert(offsetof(PlayerCharacter, stolenItemValue) == SKYRIM_RELOCATE(0x410, 0x418));
	static_assert(offsetof(PlayerCharacter, travelCommandLocationMarker) == SKYRIM_RELOCATE(0x440, 0x448));
	static_assert(offsetof(PlayerCharacter, addedPerkRanks) == SKYRIM_RELOCATE(0x4B0, 0x4B8));
	static_assert(offsetof(PlayerCharacter, perks) == SKYRIM_RELOCATE(0x4C8, 0x4D0));
	static_assert(offsetof(PlayerCharacter, standingStonePerks) == SKYRIM_RELOCATE(0x4E0, 0x4E8));
	static_assert(offsetof(PlayerCharacter, currentMapMarkers) == SKYRIM_RELOCATE(0x4F8, 0x500));
	static_assert(offsetof(PlayerCharacter, runes) == SKYRIM_RELOCATE(0x528, 0x530));
	static_assert(offsetof(PlayerCharacter, questLogEntries) == SKYRIM_RELOCATE(0x570, 0x578));
	static_assert(offsetof(PlayerCharacter, stealWarningCount) == SKYRIM_RELOCATE(0x6C8, 0x6D0));
	static_assert(offsetof(PlayerCharacter, stealWarningTimer) == SKYRIM_RELOCATE(0x6CC, 0x6D4));
	static_assert(offsetof(PlayerCharacter, pickpocketWarningCount) == SKYRIM_RELOCATE(0x6D0, 0x6D8));
	static_assert(offsetof(PlayerCharacter, pickpocketWarningTimer) == SKYRIM_RELOCATE(0x6D4, 0x6DC));
	static_assert(offsetof(PlayerCharacter, warnToLeaveTimeStamp) == SKYRIM_RELOCATE(0x6D8, 0x6E0));
	static_assert(offsetof(PlayerCharacter, currentJailFaction) == SKYRIM_RELOCATE(0x718, 0x720));
	static_assert(offsetof(PlayerCharacter, jailSentence) == SKYRIM_RELOCATE(0x720, 0x728));
	static_assert(offsetof(PlayerCharacter, actorDoingPlayerCommand) == SKYRIM_RELOCATE(0x894, 0x89C));
	static_assert(offsetof(PlayerCharacter, grabSpringActions) == SKYRIM_RELOCATE(0x898, 0x8A0));
	static_assert(offsetof(PlayerCharacter, grabbedReference) == SKYRIM_RELOCATE(0x8C8, 0x8D0));
	static_assert(offsetof(PlayerCharacter, grabbedReferenceWeight) == SKYRIM_RELOCATE(0x8CC, 0x8D4));
	static_assert(offsetof(PlayerCharacter, grabbedReferenceDistance) == SKYRIM_RELOCATE(0x8D0, 0x8D8));
	static_assert(offsetof(PlayerCharacter, firstPerson3D) == SKYRIM_RELOCATE(0x8F0, 0x8F8));
	static_assert(offsetof(PlayerCharacter, overencumberedTimer) == SKYRIM_RELOCATE(0x900, 0x908));
	static_assert(offsetof(PlayerCharacter, powerAttackTimer) == SKYRIM_RELOCATE(0x904, 0x90C));
	static_assert(offsetof(PlayerCharacter, amountStolenSold) == SKYRIM_RELOCATE(0x90C, 0x914));
	static_assert(offsetof(PlayerCharacter, lastRiddenMount) == SKYRIM_RELOCATE(0x914, 0x91C));
	static_assert(offsetof(PlayerCharacter, pendingWeaponPoison) == SKYRIM_RELOCATE(0x968, 0x970));
	static_assert(offsetof(PlayerCharacter, firstPersonLight) == SKYRIM_RELOCATE(0x998, 0x9A0));
	static_assert(offsetof(PlayerCharacter, thirdPersonLight) == SKYRIM_RELOCATE(0x9A0, 0x9A8));
	static_assert(offsetof(PlayerCharacter, automaticAimActor) == SKYRIM_RELOCATE(0x9B8, 0x9C0));
	static_assert(offsetof(PlayerCharacter, hudEnemies) == SKYRIM_RELOCATE(0x9D8, 0x9E0));
	static_assert(offsetof(PlayerCharacter, teammateCount) == SKYRIM_RELOCATE(0xA08, 0xA10));
	static_assert(offsetof(PlayerCharacter, currentLocation) == SKYRIM_RELOCATE(0xAC8, 0xAD0));
	static_assert(offsetof(PlayerCharacter, telekinesisDistance) == SKYRIM_RELOCATE(0xAD4, 0xADC));
	static_assert(offsetof(PlayerCharacter, favorRequestWaitTimer) == SKYRIM_RELOCATE(0xAD8, 0xAE0));
	static_assert(offsetof(PlayerCharacter, grabType) == SKYRIM_RELOCATE(0xAF4, 0xAFC));
	static_assert(offsetof(PlayerCharacter, difficulty) == SKYRIM_RELOCATE(0xAF8, 0xB00));
	static_assert(offsetof(PlayerCharacter, perkCount) == SKYRIM_RELOCATE(0xB01, 0xB09));
	static_assert(offsetof(PlayerCharacter, characterGenerationFlags) == SKYRIM_RELOCATE(0xB02, 0xB0A));
	static_assert(offsetof(PlayerCharacter, tintMasks) == SKYRIM_RELOCATE(0xB10, 0xB18));
	static_assert(offsetof(PlayerCharacter, overlayTintMasks) == SKYRIM_RELOCATE(0xB28, 0xB30));
	static_assert(offsetof(PlayerCharacter, complexion) == SKYRIM_RELOCATE(0xB30, 0xB38));
	static_assert(offsetof(PlayerCharacter, characterGenerationRace) == SKYRIM_RELOCATE(0xB38, 0xB40));
	static_assert(offsetof(PlayerCharacter, flagsBE3) == SKYRIM_RELOCATE(0xBDB, 0xBE3));
	static_assert(sizeof(PlayerCharacter) == SKYRIM_RELOCATE(0xBE0, 0xBE8));
}
