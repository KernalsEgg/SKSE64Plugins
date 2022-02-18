#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class Actor;
	class SpellItem;

	class MagicCaster
	{
	public:
		// Add
		virtual ~MagicCaster();                                                                                                                                             // 0
		virtual void Cast(SpellItem* spell, bool noHitEffectArt, Actor* target, float effectiveness, bool hostileEffectivenessOnly, float magnitudeOverride, Actor* cause); // 1
		virtual void Unknown2(MagicCaster*);                                                                                                                                // 2
		virtual void Unknown3(MagicCaster*);                                                                                                                                // 3
		virtual void Unknown4(MagicCaster*);                                                                                                                                // 4
		virtual void Unknown5(MagicCaster*);                                                                                                                                // 5
		virtual void Unknown6(MagicCaster*);                                                                                                                                // 6
		virtual void Unknown7(MagicCaster*);                                                                                                                                // 7
		virtual void Unknown8(MagicCaster*);                                                                                                                                // 8
		virtual void Unknown9(MagicCaster*);                                                                                                                                // 9
		virtual void UnknownA(MagicCaster*);                                                                                                                                // A
		virtual void UnknownB(MagicCaster*);                                                                                                                                // B
		virtual void UnknownC(MagicCaster*);                                                                                                                                // C
		virtual void UnknownD(MagicCaster*);                                                                                                                                // D
		virtual void UnknownE(MagicCaster*);                                                                                                                                // E
		virtual void UnknownF(MagicCaster*);                                                                                                                                // F
		virtual void Unknown10(MagicCaster*);                                                                                                                               // 10
		virtual void Unknown11(MagicCaster*);                                                                                                                               // 11
		virtual void Unknown12(MagicCaster*);                                                                                                                               // 12
		virtual void Unknown13(MagicCaster*);                                                                                                                               // 13
		virtual void Unknown14(MagicCaster*);                                                                                                                               // 14
		virtual void Unknown15(MagicCaster*);                                                                                                                               // 15
		virtual void Unknown16(MagicCaster*);                                                                                                                               // 16
		virtual void Unknown17(MagicCaster*);                                                                                                                               // 17
		virtual void Unknown18(MagicCaster*);                                                                                                                               // 18
		virtual void Unknown19(MagicCaster*);                                                                                                                               // 19
		virtual void Unknown1A(MagicCaster*);                                                                                                                               // 1A
		virtual void Unknown1B(MagicCaster*);                                                                                                                               // 1B
		virtual void Unknown1C(MagicCaster*);                                                                                                                               // 1C

		// Member variables
		std::int64_t unknown8;  // 8
		std::int64_t unknown10; // 10
		std::int64_t unknown18; // 18
		std::int64_t unknown20; // 20
		std::int64_t unknown28; // 28
		std::int64_t unknown30; // 30
		std::int64_t unknown38; // 38
		std::int64_t unknown40; // 40
	};
	static_assert(sizeof(MagicCaster) == 0x48);
}
