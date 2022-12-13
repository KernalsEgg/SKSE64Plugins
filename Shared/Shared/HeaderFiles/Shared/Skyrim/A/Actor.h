#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/A/ActorState.h"
#include "Shared/Skyrim/A/ActorValueOwner.h"
#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/I/IPostAnimationChannelUpdateFunctor.h"
#include "Shared/Skyrim/M/MagicTarget.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/S/SoulLevel.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	struct BSTransformDeltaEvent;
	struct bhkCharacterMoveFinishEvent;

	class ActorMagicCaster;
	class AIProcess;
	class bhkCharacterController;
	class CastPowerItem;
	class CombatController;
	class HitData;
	class InventoryEntryData;
	class NiAVObject;
	class SpellItem;
	class TESForm;
	class TESObjectARMO;
	class TESObjectWEAP;
	class TESRace;

	class Actor :
		public TESObjectREFR,                             // 0
		public MagicTarget,                               // 98, A0
		public ActorValueOwner,                           // B0, B8
		public ActorState,                                // B8, C0
		public BSTEventSink<BSTransformDeltaEvent>,       // C8, D0
		public BSTEventSink<bhkCharacterMoveFinishEvent>, // D0, D8
		public IPostAnimationChannelUpdateFunctor         // D8, E0
	{
	public:
		enum class BooleanBits : std::uint32_t
		{
			kNone           = 0,
			kPlayerTeammate = 1U << 26
		};
		static_assert(sizeof(BooleanBits) == 0x4);

		enum class BooleanFlags : std::uint32_t
		{
			kNone       = 0,
			kMount      = 1U << 1,
			kInKillMove = 1U << 14,
			kEssential  = 1U << 18,
			kProtected  = 1U << 19
		};
		static_assert(sizeof(BooleanFlags) == 0x4);

		enum class LineOfSightLocation : std::uint32_t
		{
			kNone  = 0,
			kEyes  = 1, // Eye level
			kHead  = 2, // 85%
			kTorso = 3, // 50%
			kFeet  = 4  // 15%
		};
		static_assert(sizeof(LineOfSightLocation) == 0x4);

		enum class SlotType : std::uint32_t
		{
			kLeftHand     = 0,
			kRightHand    = 1,
			kPowerOrShout = 3,
			kTotal        = 4
		};
		static_assert(sizeof(SlotType) == 0x4);

		// Override
		virtual ~Actor() override; // 0

		// Override (TESObjectREFR)
		virtual void                  SaveGame(BGSSaveFormBuffer* saveFormBuffer) override;                                                                                                                                                                                                              // E
		virtual void                  LoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                                                                                                                                              // F
		virtual void                  InitializeLoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                                                                                                                                    // 10
		virtual void                  FinishLoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                                                                                                                                        // 11
		virtual void                  Revert(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                                                                                                                                                // 12
		virtual void                  Unknown13(TESForm*) override;                                                                                                                                                                                                                                      // 13
		virtual void                  Unknown23(TESForm*) override;                                                                                                                                                                                                                                      // 23
		virtual void                  Unknown3B(TESObjectREFR*) override;                                                                                                                                                                                                                                // 3B
		virtual void                  Unknown3C(TESObjectREFR*) override;                                                                                                                                                                                                                                // 3C
		virtual void                  Unknown3D(TESObjectREFR*) override;                                                                                                                                                                                                                                // 3D
		virtual void                  Unknown3E(TESObjectREFR*) override;                                                                                                                                                                                                                                // 3E
		virtual void                  Unknown3F(TESObjectREFR*) override;                                                                                                                                                                                                                                // 3F
		virtual void                  Unknown40(TESObjectREFR*) override;                                                                                                                                                                                                                                // 40
		virtual void                  Unknown41(TESObjectREFR*) override;                                                                                                                                                                                                                                // 41
		virtual void                  Unknown45(TESObjectREFR*) override;                                                                                                                                                                                                                                // 45
		virtual void                  Unknown48(TESObjectREFR*) override;                                                                                                                                                                                                                                // 48
		virtual void                  Unknown49(TESObjectREFR*) override;                                                                                                                                                                                                                                // 49
		virtual void                  Unknown4A(TESObjectREFR*) override;                                                                                                                                                                                                                                // 4A
		virtual void                  Unknown4B(TESObjectREFR*) override;                                                                                                                                                                                                                                // 4B
		virtual void                  Unknown4C(TESObjectREFR*) override;                                                                                                                                                                                                                                // 4C
		virtual void                  Unknown4D(TESObjectREFR*) override;                                                                                                                                                                                                                                // 4D
		virtual void                  Unknown4E(TESObjectREFR*) override;                                                                                                                                                                                                                                // 4E
		virtual void                  Unknown4F(TESObjectREFR*) override;                                                                                                                                                                                                                                // 4F
		virtual void                  Unknown52(TESObjectREFR*) override;                                                                                                                                                                                                                                // 52
		virtual void                  Unknown53(TESObjectREFR*) override;                                                                                                                                                                                                                                // 53
		virtual ObjectReferenceHandle RemoveItem(TESBoundObject* item, std::uint32_t itemCount, Utility::Enumeration<TESObjectREFR::RemoveItemReason, std::uint32_t> reason, ExtraDataList* extraDataList, TESObjectREFR* moveToReference, const NiPoint3* position, const NiPoint3* rotation) override; // 56
		virtual void                  Unknown57(TESObjectREFR*) override;                                                                                                                                                                                                                                // 57
		virtual void                  Unknown58(TESObjectREFR*) override;                                                                                                                                                                                                                                // 58
		virtual void                  Unknown59(TESObjectREFR*) override;                                                                                                                                                                                                                                // 59
		virtual void                  Unknown5A(TESObjectREFR*) override;                                                                                                                                                                                                                                // 5A
		virtual NiPoint3              GetLookingAtLocation() const override;                                                                                                                                                                                                                             // 5B
		virtual MagicCaster*          GetMagicCaster(Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource) override;                                                                                                                                                            // 5C
		virtual MagicTarget*          GetMagicTarget() override;                                                                                                                                                                                                                                         // 5D
		virtual bool                  IsChild() const override;                                                                                                                                                                                                                                          // 5E
		virtual void                  Unknown63(TESObjectREFR*) override;                                                                                                                                                                                                                                // 63
		virtual void                  Unknown65(TESObjectREFR*) override;                                                                                                                                                                                                                                // 65
		virtual void                  Unknown66(TESObjectREFR*) override;                                                                                                                                                                                                                                // 66
		virtual void                  Unknown67(TESObjectREFR*) override;                                                                                                                                                                                                                                // 67
		virtual void                  Unknown68(TESObjectREFR*) override;                                                                                                                                                                                                                                // 68
		virtual void                  Unknown69(TESObjectREFR*) override;                                                                                                                                                                                                                                // 69
		virtual void                  Unknown6A(TESObjectREFR*) override;                                                                                                                                                                                                                                // 6A
		virtual void                  Unknown6C(TESObjectREFR*) override;                                                                                                                                                                                                                                // 6C
		virtual void                  Unknown72(TESObjectREFR*) override;                                                                                                                                                                                                                                // 72
		virtual NiPoint3              GetBoundMinimum() const override;                                                                                                                                                                                                                                  // 73
		virtual NiPoint3              GetBoundMaximum() const override;                                                                                                                                                                                                                                  // 74
		virtual void                  Unknown75(TESObjectREFR*) override;                                                                                                                                                                                                                                // 75
		virtual void                  Unknown78(TESObjectREFR*) override;                                                                                                                                                                                                                                // 78
		virtual void                  Unknown79(TESObjectREFR*) override;                                                                                                                                                                                                                                // 79
		virtual void                  Unknown7A(TESObjectREFR*) override;                                                                                                                                                                                                                                // 7A
		virtual void                  Unknown7B(TESObjectREFR*) override;                                                                                                                                                                                                                                // 7B
		virtual void                  Unknown7C(TESObjectREFR*) override;                                                                                                                                                                                                                                // 7C
		virtual void                  Unknown7D(TESObjectREFR*) override;                                                                                                                                                                                                                                // 7D
		virtual void                  Unknown82(TESObjectREFR*) override;                                                                                                                                                                                                                                // 82
		virtual void                  Unknown84(TESObjectREFR*) override;                                                                                                                                                                                                                                // 84
		virtual void                  Unknown85(TESObjectREFR*) override;                                                                                                                                                                                                                                // 85
		virtual void                  Unknown86(TESObjectREFR*) override;                                                                                                                                                                                                                                // 86
		virtual void                  Unknown87(TESObjectREFR*) override;                                                                                                                                                                                                                                // 87
		virtual void                  Unknown89(TESObjectREFR*) override;                                                                                                                                                                                                                                // 89
		virtual void                  Unknown8A(TESObjectREFR*) override;                                                                                                                                                                                                                                // 8A
		virtual void                  Unknown8B(TESObjectREFR*) override;                                                                                                                                                                                                                                // 8B
		virtual void                  Unknown8C(TESObjectREFR*) override;                                                                                                                                                                                                                                // 8C
		virtual void                  Unknown90(TESObjectREFR*) override;                                                                                                                                                                                                                                // 90
		virtual void                  Unknown91(TESObjectREFR*) override;                                                                                                                                                                                                                                // 91
		virtual void                  Unknown92(TESObjectREFR*) override;                                                                                                                                                                                                                                // 92
		virtual void                  Unknown93(TESObjectREFR*) override;                                                                                                                                                                                                                                // 93
		virtual void                  Unknown95(TESObjectREFR*) override;                                                                                                                                                                                                                                // 95
		virtual void                  Unknown96(TESObjectREFR*) override;                                                                                                                                                                                                                                // 96
		virtual void                  Unknown98(TESObjectREFR*) override;                                                                                                                                                                                                                                // 98
		virtual bool                  IsDead(bool notEssential) const override;                                                                                                                                                                                                                          // 99
		virtual void                  Unknown9C(TESObjectREFR*) override;                                                                                                                                                                                                                                // 9C
		virtual void                  Unknown9D(TESObjectREFR*) override;                                                                                                                                                                                                                                // 9D
		virtual TESAmmo*              GetEquippedAmmunition() const override;                                                                                                                                                                                                                            // 9E
		virtual void                  UnknownA1(TESObjectREFR*) override;                                                                                                                                                                                                                                // A1

		// Override (BSTEventSink<BSAnimationGraphEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* eventArguments, BSTEventSource<BSAnimationGraphEvent>* eventSource) override; // 1

		// Override (IAnimationGraphManagerHolder)
		virtual void Unknown1(IAnimationGraphManagerHolder*) override;                                                   // 1
		virtual void Unknown2(IAnimationGraphManagerHolder*) override;                                                   // 2
		virtual void Unknown3(IAnimationGraphManagerHolder*) override;                                                   // 3
		virtual void Unknown5(IAnimationGraphManagerHolder*) override;                                                   // 5
		virtual void Unknown6(IAnimationGraphManagerHolder*) override;                                                   // 6
		virtual void Unknown7(IAnimationGraphManagerHolder*) override;                                                   // 7
		virtual void Unknown8(IAnimationGraphManagerHolder*) override;                                                   // 8
		virtual void UnknownA(IAnimationGraphManagerHolder*) override;                                                   // A
		virtual void UnknownB(IAnimationGraphManagerHolder*) override;                                                   // B
		virtual void UnknownC(IAnimationGraphManagerHolder*) override;                                                   // C
		virtual void UnknownD(IAnimationGraphManagerHolder*) override;                                                   // D
		virtual void UnknownE(IAnimationGraphManagerHolder*) override;                                                   // E
		virtual void UnknownF(IAnimationGraphManagerHolder*) override;                                                   // F
		virtual bool GetAnimationVariableFloat(const BSFixedString& variableName, float& value) const override;          // 10
		virtual bool GetAnimationVariableInteger(const BSFixedString& variableName, std::int32_t& value) const override; // 11
		virtual bool GetAnimationVariableBool(const BSFixedString& variableName, bool& value) const override;            // 12

		// Override (MagicTarget)
		virtual void                         Unknown1(MagicTarget*) override;                                                          // 1
		virtual TESObjectREFR*               GetMagicTargetReference() override;                                                       // 2
		virtual bool                         IsMagicTargetActor() const override;                                                      // 3
		virtual bool                         IsInvulnerable() const override;                                                          // 4
		virtual void                         Unknown5(MagicTarget*) override;                                                          // 5
		virtual void                         Unknown6(MagicTarget*) override;                                                          // 6
		virtual BSSimpleList<ActiveEffect*>* GetActiveEffects() override;                                                              // 7
		virtual void                         Unknown8(MagicTarget*) override;                                                          // 8
		virtual void                         Unknown9(MagicTarget*) override;                                                          // 9
		virtual float                        CheckResistance(MagicItem* magicItem, EffectItem* effect, TESBoundObject* item) override; // A
		virtual void                         UnknownB(MagicTarget*) override;                                                          // B

		// Override (ActorValueOwner)
		virtual float GetActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue) override;                                                                                              // 1
		virtual float GetPermanentActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue) override;                                                                                     // 2
		virtual void  Unknown3(ActorValueOwner*) override;                                                                                                                                             // 3
		virtual void  Unknown4(ActorValueOwner*) override;                                                                                                                                             // 4
		virtual void  Unknown5(ActorValueOwner*) override;                                                                                                                                             // 5
		virtual void  RestoreActorValue(Utility::Enumeration<ActorValueModifier, std::uint32_t> actorValueModifier, Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float value) override; // 6

		// Override (ActorState)
		virtual void Unknown1(IMovementState*) override;  // 1
		virtual void Unknown2(IMovementState*) override;  // 2
		virtual void Unknown3(IMovementState*) override;  // 3
		virtual void Unknown4(IMovementState*) override;  // 4
		virtual void Unknown5(IMovementState*) override;  // 5
		virtual void Unknown6(IMovementState*) override;  // 6
		virtual void Unknown7(IMovementState*) override;  // 7
		virtual void Unknown8(IMovementState*) override;  // 8
		virtual void Unknown9(IMovementState*) override;  // 9
		virtual void UnknownA(IMovementState*) override;  // A
		virtual void UnknownB(IMovementState*) override;  // B
		virtual void UnknownC(IMovementState*) override;  // C
		virtual void UnknownD(IMovementState*) override;  // D
		virtual void UnknownE(IMovementState*) override;  // E
		virtual void UnknownF(IMovementState*) override;  // F
		virtual void Unknown10(IMovementState*) override; // 10
		virtual void Unknown11(IMovementState*) override; // 11
		virtual void Unknown12(IMovementState*) override; // 12
		virtual void Unknown13(IMovementState*) override; // 13
		virtual void Unknown15(ActorState*) override;     // 15

		// Override (BSTEventSink<BSTransformDeltaEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSTransformDeltaEvent* eventArguments, BSTEventSource<BSTransformDeltaEvent>* eventSource) override; // 1

		// Override (BSTEventSink<bhkCharacterMoveFinishEvent>)
		virtual BSEventNotifyControl ProcessEvent(const bhkCharacterMoveFinishEvent* eventArguments, BSTEventSource<bhkCharacterMoveFinishEvent>* eventSource) override; // 1

		// Override (IPostAnimationChannelUpdateFunctor)
		virtual void Unknown1(IPostAnimationChannelUpdateFunctor*) override; // 1

		// Add
		virtual void                  UnknownA2(Actor*);                                                                                                                         // A2
		virtual void                  UnknownA3(Actor*);                                                                                                                         // A3
		virtual void                  UnknownA4(Actor*);                                                                                                                         // A4
		virtual void                  UnknownA5(Actor*);                                                                                                                         // A5
		virtual void                  UnknownA6(Actor*);                                                                                                                         // A6
		virtual void                  UnknownA7(Actor*);                                                                                                                         // A7
		virtual void                  UnknownA8(Actor*);                                                                                                                         // A8
		virtual void                  UnknownA9(Actor*);                                                                                                                         // A9
		virtual void                  UnknownAA(Actor*);                                                                                                                         // AA
		virtual void                  UnknownAB(Actor*);                                                                                                                         // AB
		virtual void                  UnknownAC(Actor*);                                                                                                                         // AC
		virtual void                  UnknownAD(Actor*);                                                                                                                         // AD
		virtual void                  UnknownAE(Actor*);                                                                                                                         // AE
		virtual void                  UnknownAF(Actor*);                                                                                                                         // AF
		virtual void                  UnknownB0(Actor*);                                                                                                                         // B0
		virtual void                  UnknownB1(Actor*);                                                                                                                         // B1
		virtual void                  UnknownB2(Actor*);                                                                                                                         // B2
		virtual void                  UnknownB3(Actor*);                                                                                                                         // B3
		virtual void                  UnknownB4(Actor*);                                                                                                                         // B4
		virtual void                  UnknownB5(Actor*);                                                                                                                         // B5
		virtual void                  UnknownB6(Actor*);                                                                                                                         // B6
		virtual void                  UnknownB7(Actor*);                                                                                                                         // B7
		virtual void                  UnknownB8(Actor*);                                                                                                                         // B8
		virtual void                  UnknownB9(Actor*);                                                                                                                         // B9
		virtual void                  UnknownBA(Actor*);                                                                                                                         // BA
		virtual void                  UnknownBB(Actor*);                                                                                                                         // BB
		virtual void                  UnknownBC(Actor*);                                                                                                                         // BC
		virtual void                  UnknownBD(Actor*);                                                                                                                         // BD
		virtual void                  UnknownBE(Actor*);                                                                                                                         // BE
		virtual void                  UnknownBF(Actor*);                                                                                                                         // BF
		virtual void                  UnknownC0(Actor*);                                                                                                                         // C0
		virtual void                  UnknownC1(Actor*);                                                                                                                         // C1
		virtual void                  UnknownC2(Actor*);                                                                                                                         // C2
		virtual void                  UnknownC3(Actor*);                                                                                                                         // C3
		virtual void                  UnknownC4(Actor*);                                                                                                                         // C4
		virtual void                  UnknownC5(Actor*);                                                                                                                         // C5
		virtual void                  UnknownC6(Actor*) = 0;                                                                                                                     // C6
		virtual void                  UnknownC7(Actor*);                                                                                                                         // C7
		virtual void                  UnknownC8(Actor*);                                                                                                                         // C8
		virtual void                  UnknownC9(Actor*);                                                                                                                         // C9
		virtual void                  UnknownCA(Actor*);                                                                                                                         // CA
		virtual ObjectReferenceHandle DropItem(TESBoundObject* item, ExtraDataList* extraDataList, std::uint32_t itemCount, const NiPoint3* position, const NiPoint3* rotation); // CB
		virtual void                  UnknownCC(Actor*);                                                                                                                         // CC
		virtual void                  UnknownCD(Actor*);                                                                                                                         // CD
		virtual void                  UnknownCE(Actor*);                                                                                                                         // CE
		virtual void                  UnknownCF(Actor*);                                                                                                                         // CF
		virtual void                  UnknownD0(Actor*);                                                                                                                         // D0
		virtual void                  UnknownD1(Actor*);                                                                                                                         // D1
		virtual void                  UnknownD2(Actor*);                                                                                                                         // D2
		virtual void                  UnknownD3(Actor*);                                                                                                                         // D3
		virtual void                  UnknownD4(Actor*);                                                                                                                         // D4
		virtual void                  UnknownD5(Actor*);                                                                                                                         // D5
		virtual void                  UnknownD6(Actor*);                                                                                                                         // D6
		virtual void                  UnknownD7(Actor*);                                                                                                                         // D7
		virtual void                  UnknownD8(Actor*);                                                                                                                         // D8
		virtual void                  UnknownD9(Actor*);                                                                                                                         // D9
		virtual void                  UnknownDA(Actor*);                                                                                                                         // DA
		virtual void                  UnknownDB(Actor*);                                                                                                                         // DB
		virtual void                  UnknownDC(Actor*);                                                                                                                         // DC
		virtual void                  UnknownDD(Actor*);                                                                                                                         // DD
		virtual void                  UnknownDE(Actor*);                                                                                                                         // DE
		virtual void                  UnknownDF(Actor*);                                                                                                                         // DF
		virtual void                  UnknownE0(Actor*);                                                                                                                         // E0
		virtual void                  UnknownE1(Actor*);                                                                                                                         // E1
		virtual void                  UnknownE2(Actor*);                                                                                                                         // E2
		virtual void                  UnknownE3(Actor*);                                                                                                                         // E3
		virtual void                  UnknownE4(Actor*);                                                                                                                         // E4
		virtual void                  UnknownE5(Actor*);                                                                                                                         // E5
		virtual float                 GetTotalArmorRating();                                                                                                                     // E6
		virtual float                 GetTotalArmorBaseFactor();                                                                                                                 // E7
		virtual void                  UnknownE8(Actor*);                                                                                                                         // E8
		virtual void                  UnknownE9(Actor*);                                                                                                                         // E9
		virtual void                  UnknownEA(Actor*);                                                                                                                         // EA
		virtual void                  UnknownEB(Actor*);                                                                                                                         // EB
		virtual void                  UnknownEC(Actor*);                                                                                                                         // EC
		virtual void                  UnknownED(Actor*);                                                                                                                         // ED
		virtual void                  UnknownEE(Actor*);                                                                                                                         // EE
		virtual void                  UnknownEF(Actor*);                                                                                                                         // EF
		virtual void                  UnknownF0(Actor*);                                                                                                                         // F0
		virtual bool                  MoveToHigh();                                                                                                                              // F1
		virtual bool                  MoveToLow();                                                                                                                               // F2
		virtual bool                  MoveToMiddleLow();                                                                                                                         // F3
		virtual bool                  MoveToMiddleHigh();                                                                                                                        // F4
		virtual void                  UnknownF5(Actor*);                                                                                                                         // F5
		virtual void                  UnknownF6(Actor*);                                                                                                                         // F6
		virtual void                  UnknownF7(Actor*);                                                                                                                         // F7
		virtual void                  UnknownF8(Actor*);                                                                                                                         // F8
		virtual void                  UnknownF9(Actor*);                                                                                                                         // F9
		virtual void                  UnknownFA(Actor*);                                                                                                                         // FA
		virtual void                  UnknownFB(Actor*);                                                                                                                         // FB
		virtual void                  UnknownFC(Actor*);                                                                                                                         // FC
		virtual void                  UnknownFD(Actor*);                                                                                                                         // FD
		virtual void                  UnknownFE(Actor*);                                                                                                                         // FE
		virtual void                  UnknownFF(Actor*);                                                                                                                         // FF
		virtual void                  Unknown100(Actor*);                                                                                                                        // 100
		virtual void                  ApplyBasePerks();                                                                                                                          // 101
		virtual void                  Unknown102(Actor*);                                                                                                                        // 102
		virtual void                  Unknown103(Actor*);                                                                                                                        // 103
		virtual void                  Unknown104(Actor*);                                                                                                                        // 104
		virtual void                  Unknown105(Actor*);                                                                                                                        // 105
		virtual void                  Unknown106(Actor*);                                                                                                                        // 106
		virtual void                  Unknown107(Actor*);                                                                                                                        // 107
		virtual void                  Unknown108(Actor*);                                                                                                                        // 108
		virtual void                  Unknown109(Actor*);                                                                                                                        // 109
		virtual void                  Unknown10A(Actor*);                                                                                                                        // 10A
		virtual void                  Unknown10B(Actor*);                                                                                                                        // 10B
		virtual void                  Unknown10C(Actor*);                                                                                                                        // 10C
		virtual void                  Unknown10D(Actor*);                                                                                                                        // 10D
		virtual void                  Unknown10E(Actor*);                                                                                                                        // 10E
		virtual void                  Unknown10F(Actor*);                                                                                                                        // 10F
		virtual void                  Unknown110(Actor*);                                                                                                                        // 110
		virtual void                  Unknown111(Actor*);                                                                                                                        // 111
		virtual void                  Unknown112(Actor*);                                                                                                                        // 112
		virtual void                  Unknown113(Actor*);                                                                                                                        // 113
		virtual void                  Unknown114(Actor*);                                                                                                                        // 114
		virtual bool                  UpdateIsUndead() const;                                                                                                                    // 115
		virtual bool                  UpdateIsNPC() const;                                                                                                                       // 116
		virtual void                  Unknown117(Actor*);                                                                                                                        // 117
		virtual void                  Unknown118(Actor*);                                                                                                                        // 118
		virtual void                  Unknown119(Actor*);                                                                                                                        // 119
		virtual void                  Unknown11A(Actor*);                                                                                                                        // 11A
		virtual void                  Unknown11B(Actor*);                                                                                                                        // 11B
		virtual void                  Unknown11C(Actor*);                                                                                                                        // 11C
		virtual void                  Unknown11D(Actor*);                                                                                                                        // 11D
		virtual void                  Unknown11E(Actor*);                                                                                                                        // 11E
		virtual void                  Unknown11F(Actor*);                                                                                                                        // 11F
		virtual void                  Unknown120(Actor*);                                                                                                                        // 120
		virtual void                  Unknown121(Actor*);                                                                                                                        // 121
		virtual void                  Unknown122(Actor*);                                                                                                                        // 122
		virtual void                  Unknown123(Actor*);                                                                                                                        // 123
		virtual void                  Unknown124(Actor*);                                                                                                                        // 124
		virtual void                  Unknown125(Actor*);                                                                                                                        // 125
		virtual void                  Unknown126(Actor*);                                                                                                                        // 126
		virtual void                  Unknown127(Actor*);                                                                                                                        // 127

		// Member functions
		bool                    AddSpell(SpellItem* spell);
		float                   AdjustHealthDamageToDifficulty(float damage, float onlyReduceDamage) const;
		bool                    CanBeKilledBy(Actor* attacker) const;
		float                   GetActorValueModifier(Utility::Enumeration<ActorValueModifier, std::uint32_t> actorValueModifier, Utility::Enumeration<ActorValue, std::uint32_t> actorValue) const;
		float                   GetArmorRating(InventoryEntryData* inventoryEntryData) const;
		bhkCharacterController* GetCharacterController() const;
		ActorHandle             GetCommandingActor() const;
		bool                    GetControllingActor(NiPointer<Actor>& controllingActor);
		InventoryEntryData*     GetEquippedAmmunitionInventoryEntryData() const;
		TESObjectARMO*          GetEquippedShield() const;
		TESObjectWEAP*          GetEquippedWeapon(bool leftHand) const;
		InventoryEntryData*     GetEquippedWeaponInventoryEntryData(bool leftHand) const;
		NiAVObject*             GetHeadNode() const;
		HitData*                GetLastHitData() const;
		NiPoint3&               GetLineOfSightLocation(NiPoint3& result, Utility::Enumeration<LineOfSightLocation, std::uint32_t> lineOfSightLocation) const;
		float                   GetMaximumWardPower() const;
		bool                    GetMount(NiPointer<Actor>& mount) const;
		bool                    GetRider(NiPointer<Actor>& rider) const;
		SoulLevel               GetSoulLevel() const;
		NiAVObject*             GetTorsoNode() const;
		float                   GetWeaponDamage(InventoryEntryData* inventoryEntryData) const;
		void                    HandleActorValueModified(Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float oldValue, float deltaValue, Actor* source);
		LineOfSightLocation     IsActorInLineOfSight(Actor* target, float viewCone = 2 * std::numbers::pi_v<float>) const;
		bool                    IsDualCasting() const;
		bool                    IsNPC() const;
		bool                    IsOnFlyingMount() const;
		bool                    IsOnMount() const;
		bool                    IsPlayerTeammate() const;
		NiAVObject*             IsPositionInLineOfSight(const NiPoint3& target, NiPoint3& result, float viewCone = 2 * std::numbers::pi_v<float>) const;
		bool                    IsReferenceInLineOfSight(TESObjectREFR* target, float viewCone = 2 * std::numbers::pi_v<float>) const;
		bool                    IsSneaking() const;
		void                    ModifyActorValue(Utility::Enumeration<ActorValueModifier, std::uint32_t> actorValueModifier, Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float value, Actor* source);
		void                    RemoveActorValueModifiers(Utility::Enumeration<ActorValue, std::uint32_t> actorValue);
		void                    RemoveBasePerks();
		void                    SetMaximumWardPower(float maximumWardPower);
		void                    SetSelectedSpell(Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource, MagicItem* selectedSpell);

		// Member variables
		Utility::Enumeration<BooleanBits, std::uint32_t>  booleanBits;                                             // E0, E8
		std::uint32_t                                     unknownEC;                                               // E4, EC
		std::uint64_t                                     unknownF0;                                               // E8, F0
		AIProcess*                                        currentProcess;                                          // F0, F8
		std::uint64_t                                     unknown100;                                              // F8, 100
		std::uint64_t                                     unknown108;                                              // 100, 108
		std::uint64_t                                     unknown110;                                              // 108, 110
		std::uint64_t                                     unknown118;                                              // 110, 118
		std::uint64_t                                     unknown120;                                              // 118, 120
		std::uint64_t                                     unknown128;                                              // 120, 128
		std::uint64_t                                     unknown130;                                              // 128, 130
		std::uint64_t                                     unknown138;                                              // 130, 138
		std::uint64_t                                     unknown140;                                              // 138, 140
		std::uint64_t                                     unknown148;                                              // 140, 148
		std::uint64_t                                     unknown150;                                              // 148, 150
		std::uint64_t                                     unknown158;                                              // 150, 158
		CombatController*                                 combatController;                                        // 158, 160
		std::uint64_t                                     unknown168;                                              // 160, 168
		std::uint64_t                                     unknown170;                                              // 168, 170
		std::uint64_t                                     unknown178;                                              // 170, 178
		std::uint64_t                                     unknown180;                                              // 178, 180
		CastPowerItem*                                    castPowers;                                              // 180, 188
		std::uint64_t                                     unknown190;                                              // 188, 190
		std::uint64_t                                     unknown198;                                              // 190, 198
		std::uint64_t                                     unknown1A0;                                              // 198, 1A0
		ActorMagicCaster*                                 magicCasters[Utility::ToUnderlying(SlotType::kTotal)];   // 1A0, 1A8
		MagicItem*                                        selectedSpells[Utility::ToUnderlying(SlotType::kTotal)]; // 1C0, 1C8
		TESForm*                                          selectedPower;                                           // 1E0, 1E8
		std::uint64_t                                     unknown1F0;                                              // 1E8, 1F0
		TESRace*                                          race;                                                    // 1F0, 1F8
		float                                             equippedWeight;                                          // 1F8, 200
		Utility::Enumeration<BooleanFlags, std::uint32_t> booleanFlags;                                            // 1FC, 204
		std::uint64_t                                     unknown208;                                              // 200, 208
		std::uint64_t                                     unknown210;                                              // 208, 210
		std::uint64_t                                     unknown218;                                              // 210, 218
		std::uint64_t                                     unknown220;                                              // 218, 220
		std::uint64_t                                     unknown228;                                              // 220, 228
		std::uint64_t                                     unknown230;                                              // 228, 230
		std::uint64_t                                     unknown238;                                              // 230, 238
		std::uint64_t                                     unknown240;                                              // 238, 240
		std::uint64_t                                     unknown248;                                              // 240, 248
		std::uint64_t                                     unknown250;                                              // 248, 250
		std::uint64_t                                     unknown258;                                              // 250, 258
		float                                             lastUpdate;                                              // 258, 260
		std::uint32_t                                     unknown264;                                              // 25C, 264
		std::uint64_t                                     unknown268;                                              // 260, 268
		float                                             armorRating;                                             // 268, 270
		float                                             totalArmorBaseFactor;                                    // 26C, 274
		std::uint64_t                                     unknown278;                                              // 270, 278
		std::uint64_t                                     unknown280;                                              // 278, 280
		std::uint64_t                                     unknown288;                                              // 280, 288
		std::uint64_t                                     unknown290;                                              // 288, 290
		std::uint64_t                                     unknown298;                                              // 290, 298
		std::uint64_t                                     unknown2A0;                                              // 298, 2A0
		std::uint64_t                                     unknown2A8;                                              // 2A0, 2A8
		std::uint64_t                                     unknown2B0;                                              // 2A8, 2B0
	};
	static_assert(offsetof(Actor, booleanBits) == SKYRIM_RELOCATE(0xE0, 0xE8));
	static_assert(offsetof(Actor, currentProcess) == SKYRIM_RELOCATE(0xF0, 0xF8));
	static_assert(offsetof(Actor, combatController) == SKYRIM_RELOCATE(0x158, 0x160));
	static_assert(offsetof(Actor, castPowers) == SKYRIM_RELOCATE(0x180, 0x188));
	static_assert(offsetof(Actor, magicCasters) == SKYRIM_RELOCATE(0x1A0, 0x1A8));
	static_assert(offsetof(Actor, selectedSpells) == SKYRIM_RELOCATE(0x1C0, 0x1C8));
	static_assert(offsetof(Actor, selectedPower) == SKYRIM_RELOCATE(0x1E0, 0x1E8));
	static_assert(offsetof(Actor, race) == SKYRIM_RELOCATE(0x1F0, 0x1F8));
	static_assert(offsetof(Actor, equippedWeight) == SKYRIM_RELOCATE(0x1F8, 0x200));
	static_assert(offsetof(Actor, booleanFlags) == SKYRIM_RELOCATE(0x1FC, 0x204));
	static_assert(offsetof(Actor, lastUpdate) == SKYRIM_RELOCATE(0x258, 0x260));
	static_assert(offsetof(Actor, armorRating) == SKYRIM_RELOCATE(0x268, 0x270));
	static_assert(offsetof(Actor, totalArmorBaseFactor) == SKYRIM_RELOCATE(0x26C, 0x274));
	static_assert(sizeof(Actor) == SKYRIM_RELOCATE(0x2B0, 0x2B8));
}
