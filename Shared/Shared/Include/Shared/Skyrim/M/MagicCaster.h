#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MagicTarget.h"



namespace Skyrim
{
	struct EffectItem;

	class Actor;
	class NiPoint3;
	class Projectile;
	class SpellItem;

	class MagicCaster
	{
	public:
		struct PostCreationCallback :
			public MagicTarget::IPostCreationModification // 0
		{
		public:
			// Override
			virtual ~PostCreationCallback() override; // 0

			// Override (MagicTarget::IPostCreationModification)
			virtual void ModifyActiveEffect(ActiveEffect* activeEffect) override; // 1

			// Member variables
			MagicCaster*  magicCaster;                    // 8
			EffectItem*   effectItem1;                    // 10
			EffectItem*   effectItem2;                    // 18
			Actor*        caster;                         // 20
			Projectile*   projectile;                     // 28
			float         effectiveness;                  // 30
			std::uint32_t padding34;                      // 34
			NiPoint3*     projectilePosition;             // 38
			bool          noHitEffectArt;                 // 40
			bool          effectivenessRequiresHostility; // 41
			std::uint8_t  unknown42;                      // 42
			std::uint8_t  padding43;                      // 43
			std::uint32_t padding44;                      // 44
		};
		static_assert(offsetof(PostCreationCallback, magicCaster) == 0x8);
		static_assert(offsetof(PostCreationCallback, effectItem1) == 0x10);
		static_assert(offsetof(PostCreationCallback, effectItem2) == 0x18);
		static_assert(offsetof(PostCreationCallback, caster) == 0x20);
		static_assert(offsetof(PostCreationCallback, projectile) == 0x28);
		static_assert(offsetof(PostCreationCallback, effectiveness) == 0x30);
		static_assert(offsetof(PostCreationCallback, projectilePosition) == 0x38);
		static_assert(offsetof(PostCreationCallback, noHitEffectArt) == 0x40);
		static_assert(offsetof(PostCreationCallback, effectivenessRequiresHostility) == 0x41);
		static_assert(sizeof(PostCreationCallback) == 0x48);

		// Add
		virtual ~MagicCaster();                                                                                                                                                                         // 0
		virtual void CastSpellItemImmediate(SpellItem* spellItem, bool noHitEffectArt, Actor* target, float effectiveness, bool effectivenessRequiresHostility, float magnitudeOverride, Actor* cause); // 1
		virtual void Unknown2(MagicCaster*);                                                                                                                                                            // 2
		virtual void Unknown3(MagicCaster*);                                                                                                                                                            // 3
		virtual void Unknown4(MagicCaster*);                                                                                                                                                            // 4
		virtual void Unknown5(MagicCaster*);                                                                                                                                                            // 5
		virtual void Unknown6(MagicCaster*);                                                                                                                                                            // 6
		virtual void Unknown7(MagicCaster*);                                                                                                                                                            // 7
		virtual void Unknown8(MagicCaster*);                                                                                                                                                            // 8
		virtual void Unknown9(MagicCaster*);                                                                                                                                                            // 9
		virtual void UnknownA(MagicCaster*);                                                                                                                                                            // A
		virtual void UnknownB(MagicCaster*);                                                                                                                                                            // B
		virtual void UnknownC(MagicCaster*);                                                                                                                                                            // C
		virtual void UnknownD(MagicCaster*);                                                                                                                                                            // D
		virtual void UnknownE(MagicCaster*);                                                                                                                                                            // E
		virtual void UnknownF(MagicCaster*);                                                                                                                                                            // F
		virtual void Unknown10(MagicCaster*);                                                                                                                                                           // 10
		virtual void Unknown11(MagicCaster*);                                                                                                                                                           // 11
		virtual void Unknown12(MagicCaster*);                                                                                                                                                           // 12
		virtual void Unknown13(MagicCaster*);                                                                                                                                                           // 13
		virtual void Unknown14(MagicCaster*);                                                                                                                                                           // 14
		virtual void Unknown15(MagicCaster*);                                                                                                                                                           // 15
		virtual void Unknown16(MagicCaster*);                                                                                                                                                           // 16
		virtual void Unknown17(MagicCaster*);                                                                                                                                                           // 17
		virtual void Unknown18(MagicCaster*);                                                                                                                                                           // 18
		virtual void Unknown19(MagicCaster*);                                                                                                                                                           // 19
		virtual void Unknown1A(MagicCaster*);                                                                                                                                                           // 1A
		virtual void Unknown1B(MagicCaster*);                                                                                                                                                           // 1B
		virtual void Unknown1C(MagicCaster*);                                                                                                                                                           // 1C

		// Member variables
		std::uint64_t unknown8;  // 8
		std::uint64_t unknown10; // 10
		std::uint64_t unknown18; // 18
		std::uint64_t unknown20; // 20
		std::uint64_t unknown28; // 28
		std::uint64_t unknown30; // 30
		std::uint64_t unknown38; // 38
		std::uint64_t unknown40; // 40
	};
	static_assert(sizeof(MagicCaster) == 0x48);
}
