#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValueOwner.h"
#include "Shared/Skyrim/B/BGSAttackDataForm.h"
#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSKeywordForm.h"
#include "Shared/Skyrim/B/BGSPerkRankArray.h"
#include "Shared/Skyrim/B/BGSSkinForm.h"
#include "Shared/Skyrim/T/TESAIForm.h"
#include "Shared/Skyrim/T/TESActorBaseData.h"
#include "Shared/Skyrim/T/TESBoundAnimObject.h"
#include "Shared/Skyrim/T/TESContainer.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESSpellList.h"



namespace Skyrim
{
	class TESCombatStyle;

	class TESActorBase :
		public TESBoundAnimObject,        // 0
		public TESActorBaseData,          // 30
		public TESContainer,              // 88
		public TESSpellList,              // A0
		public TESAIForm,                 // B0
		public TESFullName,               // D8
		public ActorValueOwner,           // E8
		public BGSDestructibleObjectForm, // F0
		public BGSSkinForm,               // 100
		public BGSKeywordForm,            // 110
		public BGSAttackDataForm,         // 128
		public BGSPerkRankArray           // 138
	{
	public:
		// Override
		virtual ~TESActorBase() override; // 0

		// Override (TESBoundAnimObject)
		virtual bool AddChanges(std::uint32_t changeFlags) override;       // A
		virtual void RemoveChanges(std::uint32_t changeFlags) override;    // B
		virtual void SaveGame(BGSSaveFormBuffer* saveFormBuffer) override; // E
		virtual void LoadGame(BGSLoadFormBuffer* loadFormBuffer) override; // F
		virtual void Revert(BGSLoadFormBuffer* loadFormBuffer) override;   // 12
		virtual void Unknown3E(TESObject*) override;                       // 3E
		virtual void Unknown3F(TESObject*) override;                       // 3F

		// Override (ActorValueOwner)
		virtual float GetActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue) override;                                                                                              // 1
		virtual float GetPermanentActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue) override;                                                                                     // 2
		virtual void  Unknown3(ActorValueOwner*) override;                                                                                                                                             // 3
		virtual void  Unknown4(ActorValueOwner*) override;                                                                                                                                             // 4
		virtual void  Unknown5(ActorValueOwner*) override;                                                                                                                                             // 5
		virtual void  RestoreActorValue(Utility::Enumeration<ActorValueModifier, std::uint32_t> actorValueModifier, Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float value) override; // 6
		virtual void  SetActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float value) override;                                                                                 // 7
		virtual bool  IsPlayerOwner() const override;                                                                                                                                                  // 8

		// Add
		virtual void            Unknown53(TESActorBase*);                    // 53
		virtual TESCombatStyle* GetCombatStyle();                            // 54
		virtual void            SetCombatStyle(TESCombatStyle* combatStyle); // 55
		virtual void            Unknown56(TESActorBase*);                    // 56
	};
	static_assert(sizeof(TESActorBase) == 0x150);
}
