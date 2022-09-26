#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/A/Actor.h"



namespace Skyrim
{
	class Character :
		public Actor // 0
	{
	public:
		// Override
		virtual ~Character() override; // 0

		// Override (Actor)
		virtual void                              SaveGame(BGSSaveFormBuffer* saveFormBuffer) override;           // E
		virtual void                              LoadGame(BGSLoadFormBuffer* loadFormBuffer) override;           // F
		virtual void                              InitializeLoadGame(BGSLoadFormBuffer* loadFormBuffer) override; // 10
		virtual void                              FinishLoadGame(BGSLoadFormBuffer* loadFormBuffer) override;     // 11
		virtual void                              Revert(BGSLoadFormBuffer* loadFormBuffer) override;             // 12
		virtual void                              Unknown3B(TESObjectREFR*) override;                             // 3B
		virtual void                              Unknown5E(TESObjectREFR*) override;                             // 5E
		virtual void                              Unknown61(TESObjectREFR*) override;                             // 61
		virtual void                              Unknown63(TESObjectREFR*) override;                             // 63
		virtual const BSTSmartPointer<BipedAnim>& GetThirdPersonBiped() const override;                           // 7F
		virtual void                              Unknown81(TESObjectREFR*) override;                             // 81
		virtual void                              UnknownC0(Actor*) override;                                     // C0
		virtual void                              UnknownC4(Actor*) override;                                     // C4
		virtual void                              UnknownC5(Actor*) override;                                     // C5
		virtual void                              UnknownC6(Actor*) override;                                     // C6
		virtual void                              UnknownCA(Actor*) override;                                     // CA
		virtual void                              UnknownD7(Actor*) override;                                     // D7
		virtual void                              UnknownDC(Actor*) override;                                     // DC
		virtual float                             GetTotalArmorRating() override;                                 // E6
		virtual float                             GetTotalArmorBaseFactor() override;                             // E7
		virtual void                              UnknownE8(Actor*) override;                                     // E8
		virtual void                              Unknown120(Actor*) override;                                    // 120

		// Add
		virtual void Unknown128(Character*); // 128
		virtual void Unknown129(Character*); // 129
	};
	static_assert(sizeof(Character) == SKYRIM_RELOCATE(0x2B0, 0x2B8));
}
