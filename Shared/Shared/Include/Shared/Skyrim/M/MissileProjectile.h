#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/P/Projectile.h"



namespace Skyrim
{
	class MissileProjectile :
		public Projectile // 0
	{
	public:
		// Override
		virtual ~MissileProjectile() override; // 0

		// Override (Projectile)
		virtual void                    SaveGame(BGSSaveFormBuffer* saveFormBuffer) override;                                                                                                                             // E
		virtual void                    LoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                                                             // F
		virtual void                    InitializeLoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                                                   // 10
		virtual void                    FinishLoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                                                       // 11
		virtual void                    Revert(BGSLoadFormBuffer* loadFormBuffer) override;                                                                                                                               // 12
		virtual void                    UnknownA2(Projectile*) override;                                                                                                                                                  // A2
		virtual void                    UnknownA9(Projectile*) override;                                                                                                                                                  // A9
		virtual void                    UnknownAB(Projectile*) override;                                                                                                                                                  // AB
		virtual void                    UnknownAC(Projectile*) override;                                                                                                                                                  // AC
		virtual void                    UnknownB8(Projectile*) override;                                                                                                                                                  // B8
		virtual Projectile::ImpactData* AddImpact(TESObjectREFR* target, const NiPoint3& targetPosition, const NiPoint3& negativeVelocity, hkpCollidable* collidable, hkpShapeKey shapeKey, bool spellCollided) override; // BD
		virtual void                    UnknownC0(Projectile*) override;                                                                                                                                                  // C0

		// Add
		virtual void UnknownC2(MissileProjectile*); // C2
		virtual void UnknownC3(MissileProjectile*); // C3

		// Member variables
		std::uint64_t unknown1E0; // 1D8, 1E0
	};
	static_assert(sizeof(MissileProjectile) == SKYRIM_RELOCATE(0x1E0, 0x1E8));
}
