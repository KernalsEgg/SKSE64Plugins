#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/A/AITimestamp.h"
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
		public BSTEventSink<MenuOpenCloseEvent>,        // 2B0
		public BSTEventSink<MenuModeChangeEvent>,       // 2B8
		public BSTEventSink<UserEventEnabledEvent>,     // 2C0
		public BSTEventSink<TESTrackedStatisticsEvent>, // 2C8
		public BSTEventSource<BGSActorCellEvent>,       // 2D0
		public BSTEventSource<BGSActorDeathEvent>,      // 328
		public BSTEventSource<PositionPlayerEvent>      // 380
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

		enum class FlagsBDB : std::uint8_t
		{
			kNone                        = 0,
			kThirdPerson                 = 1U << 0,
			kInsufficientChargeLeftHand  = 1U << 2,
			kInsufficientChargeRightHand = 1U << 3,
			kInCombat                    = 1U << 5
		};
		static_assert(sizeof(FlagsBDB) == 0x1);

		// Override
		virtual ~PlayerCharacter() override; // 0

		// Override (Character)
		virtual void                              UnknownE(TESForm*) override;                                                                                                                        // E
		virtual void                              UnknownF(TESForm*) override;                                                                                                                        // F
		virtual void                              Unknown10(TESForm*) override;                                                                                                                       // 10
		virtual void                              Unknown11(TESForm*) override;                                                                                                                       // 11
		virtual void                              Unknown12(TESForm*) override;                                                                                                                       // 12
		virtual void                              Unknown46(TESObjectREFR*) override;                                                                                                                 // 46
		virtual void                              Unknown47(TESObjectREFR*) override;                                                                                                                 // 47
		virtual void                              Unknown55(TESObjectREFR*) override;                                                                                                                 // 55
		virtual void                              Unknown5B(TESObjectREFR*) override;                                                                                                                 // 5B
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
		virtual void                              UnknownFA(Actor*) override;                                                                                                                         // FA
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
		virtual void Unknown4(MagicTarget*) override; // 4
		virtual void Unknown8(MagicTarget*) override; // 8

		// Override (ActorValueOwner)
		virtual void Unknown8(ActorValueOwner*) override; // 8

		// Override (ActorState)
		virtual void Unknown4(IMovementState*) override; // 4
		virtual void Unknown14(ActorState*) override;    // 14
		virtual void Unknown15(ActorState*) override;    // 15

		// Override (BSTEventSink<MenuOpenCloseEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* eventArguments, BSTEventSource<MenuOpenCloseEvent>* eventSource) override; // 1

		// Override (BSTEventSink<MenuModeChangeEvent>)
		virtual BSEventNotifyControl ProcessEvent(const MenuModeChangeEvent* eventArguments, BSTEventSource<MenuModeChangeEvent>* eventSource) override; // 1

		// Override (BSTEventSink<UserEventEnabledEvent>)
		virtual BSEventNotifyControl ProcessEvent(const UserEventEnabledEvent* eventArguments, BSTEventSource<UserEventEnabledEvent>* eventSource) override; // 1

		// Override (BSTEventSink<TESTrackedStatisticsEvent>)
		virtual BSEventNotifyControl ProcessEvent(const TESTrackedStatisticsEvent* eventArguments, BSTEventSource<TESTrackedStatisticsEvent>* eventSource) override; // 1

		// Add
		virtual void Unknown12A(PlayerCharacter*); // 12A
		virtual void Unknown12B(PlayerCharacter*); // 12B
		virtual void Unknown12C(PlayerCharacter*); // 12C
		virtual void Unknown12D(PlayerCharacter*); // 12D
		virtual void Unknown12E(PlayerCharacter*); // 12E

		// Non-member functions
		static PlayerCharacter* GetSingleton();

		// Member variables
		std::uint64_t                                                unknown3D8;               // 3D8
		BSTHashMap<const TESFaction*, CrimeGold>                     crimeGold;                // 3E0
		BSTHashMap<const TESFaction*, StolenItemValue>               stolenItemValue;          // 410
		ObjectReferenceHandle                                        commandedActorWaitMarker; // 440
		std::uint32_t                                                unknown444;               // 444
		std::uint64_t                                                unknown448;               // 448
		std::uint64_t                                                unknown450;               // 450
		std::uint64_t                                                unknown458;               // 458
		std::uint64_t                                                unknown460;               // 460
		std::uint64_t                                                unknown468;               // 468
		std::uint64_t                                                unknown470;               // 470
		std::uint64_t                                                unknown478;               // 478
		std::uint64_t                                                unknown480;               // 480
		std::uint64_t                                                unknown488;               // 488
		std::uint64_t                                                unknown490;               // 490
		std::uint64_t                                                unknown498;               // 498
		std::uint64_t                                                unknown4A0;               // 4A0
		std::uint64_t                                                unknown4A8;               // 4A8
		BSTArray<PerkRank*>                                          addedPerkRanks;           // 4B0
		BSTArray<BGSPerk*>                                           perks;                    // 4C8
		BSTArray<BGSPerk*>                                           standingStonePerks;       // 4E0
		BSTArray<ObjectReferenceHandle>                              currentMapMarkers;        // 4F8
		std::uint64_t                                                unknown510;               // 510
		std::uint64_t                                                unknown518;               // 518
		std::uint64_t                                                unknown520;               // 520
		BSTArray<ProjectileHandle>                                   runes;                    // 528
		std::uint64_t                                                unknown540;               // 540
		std::uint64_t                                                unknown548;               // 548
		std::uint64_t                                                unknown550;               // 550
		std::uint64_t                                                unknown558;               // 558
		std::uint64_t                                                unknown560;               // 560
		std::uint64_t                                                unknown568;               // 568
		BSSimpleList<TESQuestStageItem*>                             questLogEntries;          // 570
		std::uint64_t                                                unknown580;               // 580
		std::uint64_t                                                unknown588;               // 588
		std::uint64_t                                                unknown590;               // 590
		std::uint64_t                                                unknown598;               // 598
		std::uint64_t                                                unknown5A0;               // 5A0
		std::uint64_t                                                unknown5A8;               // 5A8
		std::uint64_t                                                unknown5B0;               // 5B0
		std::uint64_t                                                unknown5B8;               // 5B8
		std::uint64_t                                                unknown5C0;               // 5C0
		std::uint64_t                                                unknown5C8;               // 5C8
		std::uint64_t                                                unknown5D0;               // 5D0
		std::uint64_t                                                unknown5D8;               // 5D8
		std::uint64_t                                                unknown5E0;               // 5E0
		std::uint64_t                                                unknown5E8;               // 5E8
		std::uint64_t                                                unknown5F0;               // 5F0
		std::uint64_t                                                unknown5F8;               // 5F8
		std::uint64_t                                                unknown600;               // 600
		std::uint64_t                                                unknown608;               // 608
		std::uint64_t                                                unknown610;               // 610
		std::uint64_t                                                unknown618;               // 618
		std::uint64_t                                                unknown620;               // 620
		std::uint64_t                                                unknown628;               // 628
		std::uint64_t                                                unknown630;               // 630
		std::uint64_t                                                unknown638;               // 638
		std::uint64_t                                                unknown640;               // 640
		std::uint64_t                                                unknown648;               // 648
		std::uint64_t                                                unknown650;               // 650
		std::uint64_t                                                unknown658;               // 658
		std::uint64_t                                                unknown660;               // 660
		std::uint64_t                                                unknown668;               // 668
		std::uint64_t                                                unknown670;               // 670
		std::uint64_t                                                unknown678;               // 678
		std::uint64_t                                                unknown680;               // 680
		std::uint64_t                                                unknown688;               // 688
		std::uint64_t                                                unknown690;               // 690
		std::uint64_t                                                unknown698;               // 698
		std::uint64_t                                                unknown6A0;               // 6A0
		std::uint64_t                                                unknown6A8;               // 6A8
		std::uint64_t                                                unknown6B0;               // 6B0
		std::uint64_t                                                unknown6B8;               // 6B8
		std::uint64_t                                                unknown6C0;               // 6C0
		std::int32_t                                                 stealWarningCount;        // 6C8
		float                                                        stealWarningTimer;        // 6CC
		std::int32_t                                                 pickpocketWarningCount;   // 6D0
		float                                                        pickpocketWarningTimer;   // 6D4
		AITimestamp                                                  warnToLeaveTimestamp;     // 6D8
		std::uint32_t                                                padding6DC;               // 6DC
		std::uint64_t                                                unknown6E0;               // 6E0
		std::uint64_t                                                unknown6E8;               // 6E8
		std::uint64_t                                                unknown6F0;               // 6F0
		std::uint64_t                                                unknown6F8;               // 6F8
		std::uint64_t                                                unknown700;               // 700
		std::uint64_t                                                unknown708;               // 708
		std::uint64_t                                                unknown710;               // 710
		TESFaction*                                                  currentJailFaction;       // 718
		std::int32_t                                                 jailSentence;             // 720
		std::uint32_t                                                padding724;               // 724
		std::uint64_t                                                unknown728;               // 728
		std::uint64_t                                                unknown730;               // 730
		std::uint64_t                                                unknown738;               // 738
		std::uint64_t                                                unknown740;               // 740
		std::uint64_t                                                unknown748;               // 748
		std::uint64_t                                                unknown750;               // 750
		std::uint64_t                                                unknown758;               // 758
		std::uint64_t                                                unknown760;               // 760
		std::uint64_t                                                unknown768;               // 768
		std::uint64_t                                                unknown770;               // 770
		std::uint64_t                                                unknown778;               // 778
		std::uint64_t                                                unknown780;               // 780
		std::uint64_t                                                unknown788;               // 788
		std::uint64_t                                                unknown790;               // 790
		std::uint64_t                                                unknown798;               // 798
		std::uint64_t                                                unknown7A0;               // 7A0
		std::uint64_t                                                unknown7A8;               // 7A8
		std::uint64_t                                                unknown7B0;               // 7B0
		std::uint64_t                                                unknown7B8;               // 7B8
		std::uint64_t                                                unknown7C0;               // 7C0
		std::uint64_t                                                unknown7C8;               // 7C8
		std::uint64_t                                                unknown7D0;               // 7D0
		std::uint64_t                                                unknown7D8;               // 7D8
		std::uint64_t                                                unknown7E0;               // 7E0
		std::uint64_t                                                unknown7E8;               // 7E8
		std::uint64_t                                                unknown7F0;               // 7F0
		std::uint64_t                                                unknown7F8;               // 7F8
		std::uint64_t                                                unknown800;               // 800
		std::uint64_t                                                unknown808;               // 808
		std::uint64_t                                                unknown810;               // 810
		std::uint64_t                                                unknown818;               // 818
		std::uint64_t                                                unknown820;               // 820
		std::uint64_t                                                unknown828;               // 828
		std::uint64_t                                                unknown830;               // 830
		std::uint64_t                                                unknown838;               // 838
		std::uint64_t                                                unknown840;               // 840
		std::uint64_t                                                unknown848;               // 848
		std::uint64_t                                                unknown850;               // 850
		std::uint64_t                                                unknown858;               // 858
		std::uint64_t                                                unknown860;               // 860
		std::uint64_t                                                unknown868;               // 868
		std::uint64_t                                                unknown870;               // 870
		std::uint64_t                                                unknown878;               // 878
		std::uint64_t                                                unknown880;               // 880
		std::uint64_t                                                unknown888;               // 888
		std::uint32_t                                                unknown890;               // 890
		ActorHandle                                                  commandedActor;           // 894
		BSTSmallArray<hkReferencePointer<bhkMouseSpringAction>, 4>   grabSpringActions;        // 898
		ObjectReferenceHandle                                        grabbedReference;         // 8C8
		float                                                        grabbedReferenceWeight;   // 8CC
		float                                                        grabbedReferenceDistance; // 8D0
		std::uint32_t                                                unknown8D4;               // 8D4
		std::uint64_t                                                unknown8D8;               // 8D8
		std::uint64_t                                                unknown8E0;               // 8E0
		std::uint64_t                                                unknown8E8;               // 8E8
		NiPointer<NiNode>                                            firstPerson3D;            // 8F0
		std::uint64_t                                                unknown8F8;               // 8F8
		float                                                        overencumberedTimer;      // 900
		float                                                        powerAttackTimer;         // 904
		std::uint32_t                                                unknown904;               // 908
		std::int32_t                                                 amountStolenSold;         // 90C
		std::uint32_t                                                unknown910;               // 910
		ActorHandle                                                  lastRiddenMount;          // 914
		std::uint64_t                                                unknown918;               // 918
		std::uint64_t                                                unknown920;               // 920
		std::uint64_t                                                unknown928;               // 928
		std::uint64_t                                                unknown930;               // 930
		std::uint64_t                                                unknown938;               // 938
		std::uint64_t                                                unknown940;               // 940
		std::uint64_t                                                unknown948;               // 948
		std::uint64_t                                                unknown950;               // 950
		std::uint64_t                                                unknown958;               // 958
		std::uint64_t                                                unknown960;               // 960
		AlchemyItem*                                                 weaponPoison;             // 968
		std::uint64_t                                                unknown970;               // 970
		std::uint64_t                                                unknown978;               // 978
		std::uint64_t                                                unknown980;               // 980
		std::uint64_t                                                unknown988;               // 988
		std::uint64_t                                                unknown990;               // 990
		NiPointer<BSLight>                                           firstPersonLight;         // 998
		NiPointer<BSLight>                                           thirdPersonLight;         // 9A0
		std::uint64_t                                                unknown9A8;               // 9A8
		std::uint64_t                                                unknown9B0;               // 9B0
		ActorHandle                                                  autoAimActor;             // 9B8
		std::uint32_t                                                unknown9BC;               // 9BC
		std::uint64_t                                                unknown9C0;               // 9C0
		std::uint64_t                                                unknown9C8;               // 9C8
		std::uint64_t                                                unknown9D0;               // 9D0
		BSTArray<ActorHandle>                                        enemiesHUD;               // 9D8
		std::uint64_t                                                unknown9F0;               // 9F0
		std::uint64_t                                                unknown9F8;               // 9F8
		std::uint64_t                                                unknownA00;               // A00
		std::uint32_t                                                teammateCount;            // A08
		std::uint32_t                                                unknownA0C;               // A0C
		std::uint64_t                                                unknownA10;               // A10
		std::uint64_t                                                unknownA18;               // A18
		std::uint64_t                                                unknownA20;               // A20
		std::uint64_t                                                unknownA28;               // A28
		std::uint64_t                                                unknownA30;               // A30
		std::uint64_t                                                unknownA38;               // A38
		std::uint64_t                                                unknownA40;               // A40
		std::uint64_t                                                unknownA48;               // A48
		std::uint64_t                                                unknownA50;               // A50
		std::uint64_t                                                unknownA58;               // A58
		std::uint64_t                                                unknownA60;               // A60
		std::uint64_t                                                unknownA68;               // A68
		std::uint64_t                                                unknownA70;               // A70
		std::uint64_t                                                unknownA78;               // A78
		std::uint64_t                                                unknownA80;               // A80
		std::uint64_t                                                unknownA88;               // A88
		std::uint64_t                                                unknownA90;               // A90
		std::uint64_t                                                unknownA98;               // A98
		std::uint64_t                                                unknownAA0;               // AA0
		std::uint64_t                                                unknownAA8;               // AA8
		std::uint64_t                                                unknownAB0;               // AB0
		std::uint64_t                                                unknownAB8;               // AB8
		std::uint64_t                                                unknownAC0;               // AC0
		BGSLocation*                                                 currentLocation;          // AC8
		std::uint32_t                                                unknownAD0;               // AD0
		float                                                        telekinesisDistance;      // AD4
		float                                                        commandedActorTimer;      // AD8
		std::uint32_t                                                unknownADC;               // ADC
		std::uint64_t                                                unknownAE0;               // AE0
		std::uint64_t                                                unknownAE8;               // AE8
		std::uint32_t                                                unknownAF0;               // AF0
		Utility::Enumeration<GrabType, std::uint32_t>                grabType;                 // AF4
		Utility::Enumeration<Difficulty, std::uint32_t>              difficulty;               // AF8
		std::uint32_t                                                unknownAFC;               // AFC
		std::uint8_t                                                 unknownB00;               // B00
		std::int8_t                                                  perkCount;                // B01
		Utility::Enumeration<CharacterGenerationFlags, std::uint8_t> characterGenerationFlags; // B02
		std::uint8_t                                                 paddingB03;               // B03
		std::uint32_t                                                unknownB04;               // B04
		std::uint64_t                                                unknownB08;               // B08
		BSTArray<TintMask*>                                          tintMasks;                // B10
		BSTArray<TintMask*>*                                         overlayTintMasks;         // B28
		BGSTextureSet*                                               complexion;               // B30
		TESRace*                                                     characterGenerationRace;  // B38
		std::uint64_t                                                unknownB40;               // B40
		std::uint64_t                                                unknownB48;               // B48
		std::uint64_t                                                unknownB50;               // B50
		std::uint64_t                                                unknownB58;               // B58
		std::uint64_t                                                unknownB60;               // B60
		std::uint64_t                                                unknownB68;               // B68
		std::uint64_t                                                unknownB70;               // B70
		std::uint64_t                                                unknownB78;               // B78
		std::uint64_t                                                unknownB80;               // B80
		std::uint64_t                                                unknownB88;               // B88
		std::uint64_t                                                unknownB90;               // B90
		std::uint64_t                                                unknownB98;               // B98
		std::uint64_t                                                unknownBA0;               // BA0
		std::uint64_t                                                unknownBA8;               // BA8
		std::uint64_t                                                unknownBB0;               // BB0
		std::uint64_t                                                unknownBB8;               // BB8
		std::uint64_t                                                unknownBC0;               // BC0
		std::uint64_t                                                unknownBC8;               // BC8
		std::uint64_t                                                unknownBD0;               // BD0
		std::uint16_t                                                unknownBD8;               // BD8
		std::uint8_t                                                 unknownBDA;               // BDA
		Utility::Enumeration<FlagsBDB, std::uint8_t>                 flagsBDB;                 // BDB
		std::uint32_t                                                unknownBDC;               // BDC
	};
	static_assert(offsetof(PlayerCharacter, crimeGold) == 0x3E0);
	static_assert(offsetof(PlayerCharacter, stolenItemValue) == 0x410);
	static_assert(offsetof(PlayerCharacter, commandedActorWaitMarker) == 0x440);
	static_assert(offsetof(PlayerCharacter, addedPerkRanks) == 0x4B0);
	static_assert(offsetof(PlayerCharacter, perks) == 0x4C8);
	static_assert(offsetof(PlayerCharacter, standingStonePerks) == 0x4E0);
	static_assert(offsetof(PlayerCharacter, currentMapMarkers) == 0x4F8);
	static_assert(offsetof(PlayerCharacter, runes) == 0x528);
	static_assert(offsetof(PlayerCharacter, questLogEntries) == 0x570);
	static_assert(offsetof(PlayerCharacter, stealWarningCount) == 0x6C8);
	static_assert(offsetof(PlayerCharacter, stealWarningTimer) == 0x6CC);
	static_assert(offsetof(PlayerCharacter, pickpocketWarningCount) == 0x6D0);
	static_assert(offsetof(PlayerCharacter, pickpocketWarningTimer) == 0x6D4);
	static_assert(offsetof(PlayerCharacter, warnToLeaveTimestamp) == 0x6D8);
	static_assert(offsetof(PlayerCharacter, currentJailFaction) == 0x718);
	static_assert(offsetof(PlayerCharacter, jailSentence) == 0x720);
	static_assert(offsetof(PlayerCharacter, commandedActor) == 0x894);
	static_assert(offsetof(PlayerCharacter, grabSpringActions) == 0x898);
	static_assert(offsetof(PlayerCharacter, grabbedReference) == 0x8C8);
	static_assert(offsetof(PlayerCharacter, grabbedReferenceWeight) == 0x8CC);
	static_assert(offsetof(PlayerCharacter, grabbedReferenceDistance) == 0x8D0);
	static_assert(offsetof(PlayerCharacter, firstPerson3D) == 0x8F0);
	static_assert(offsetof(PlayerCharacter, overencumberedTimer) == 0x900);
	static_assert(offsetof(PlayerCharacter, powerAttackTimer) == 0x904);
	static_assert(offsetof(PlayerCharacter, amountStolenSold) == 0x90C);
	static_assert(offsetof(PlayerCharacter, lastRiddenMount) == 0x914);
	static_assert(offsetof(PlayerCharacter, weaponPoison) == 0x968);
	static_assert(offsetof(PlayerCharacter, firstPersonLight) == 0x998);
	static_assert(offsetof(PlayerCharacter, thirdPersonLight) == 0x9A0);
	static_assert(offsetof(PlayerCharacter, autoAimActor) == 0x9B8);
	static_assert(offsetof(PlayerCharacter, enemiesHUD) == 0x9D8);
	static_assert(offsetof(PlayerCharacter, teammateCount) == 0xA08);
	static_assert(offsetof(PlayerCharacter, currentLocation) == 0xAC8);
	static_assert(offsetof(PlayerCharacter, telekinesisDistance) == 0xAD4);
	static_assert(offsetof(PlayerCharacter, commandedActorTimer) == 0xAD8);
	static_assert(offsetof(PlayerCharacter, grabType) == 0xAF4);
	static_assert(offsetof(PlayerCharacter, difficulty) == 0xAF8);
	static_assert(offsetof(PlayerCharacter, perkCount) == 0xB01);
	static_assert(offsetof(PlayerCharacter, characterGenerationFlags) == 0xB02);
	static_assert(offsetof(PlayerCharacter, tintMasks) == 0xB10);
	static_assert(offsetof(PlayerCharacter, overlayTintMasks) == 0xB28);
	static_assert(offsetof(PlayerCharacter, complexion) == 0xB30);
	static_assert(offsetof(PlayerCharacter, characterGenerationRace) == 0xB38);
	static_assert(offsetof(PlayerCharacter, flagsBDB) == 0xBDB);
	static_assert(sizeof(PlayerCharacter) == 0xBE0);
}
