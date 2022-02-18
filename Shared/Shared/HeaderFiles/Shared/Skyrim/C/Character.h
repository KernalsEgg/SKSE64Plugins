#pragma once

#include "Shared/PCH.h"

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
		virtual void UnknownE(TESForm*) override;        // E
		virtual void UnknownF(TESForm*) override;        // F
		virtual void Unknown10(TESForm*) override;       // 10
		virtual void Unknown11(TESForm*) override;       // 11
		virtual void Unknown12(TESForm*) override;       // 12
		virtual void Unknown3B(TESObjectREFR*) override; // 3B
		virtual void Unknown5E(TESObjectREFR*) override; // 5E
		virtual void Unknown61(TESObjectREFR*) override; // 61
		virtual void Unknown63(TESObjectREFR*) override; // 63
		virtual void Unknown7F(TESObjectREFR*) override; // 7F
		virtual void Unknown81(TESObjectREFR*) override; // 81
		virtual void UnknownC0(Actor*) override;         // C0
		virtual void UnknownC4(Actor*) override;         // C4
		virtual void UnknownC5(Actor*) override;         // C5
		virtual void UnknownC6(Actor*) override;         // C6
		virtual void UnknownCA(Actor*) override;         // CA
		virtual void UnknownD7(Actor*) override;         // D7
		virtual void UnknownDC(Actor*) override;         // DC
		virtual void UnknownE6(Actor*) override;         // E6
		virtual void UnknownE7(Actor*) override;         // E7
		virtual void UnknownE8(Actor*) override;         // E8
		virtual void Unknown120(Actor*) override;        // 120

		// Add
		virtual void Unknown128(Character*); // 128
		virtual void Unknown129(Character*); // 129
	};
	static_assert(sizeof(Character) == 0x2B0);
}
