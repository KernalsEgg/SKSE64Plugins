#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/M/MissileProjectile.h"



namespace Skyrim
{
	class AlchemyItem;

	class ArrowProjectile :
		public MissileProjectile // 0
	{
	public:
		// Override
		virtual ~ArrowProjectile() override; // 0

		// Override (MissileProjectile)
		virtual void SaveGame(BGSSaveFormBuffer* saveFormBuffer) override; // E
		virtual void LoadGame(BGSLoadFormBuffer* loadFormBuffer) override; // F
		virtual void UnknownAA(Projectile*) override;                      // AA
		virtual void UnknownAB(Projectile*) override;                      // AB
		virtual void UnknownAC(Projectile*) override;                      // AC
		virtual void UnknownAD(Projectile*) override;                      // AD
		virtual void UnknownAF(Projectile*) override;                      // AF
		virtual void UnknownB0(Projectile*) override;                      // B0
		virtual void UnknownB1(Projectile*) override;                      // B1
		virtual void UnknownB5(Projectile*) override;                      // B5
		virtual void UnknownB9(Projectile*) override;                      // B9
		virtual void UnknownBD(Projectile*) override;                      // BD
		virtual void UnknownC0(Projectile*) override;                      // C0
		virtual void UnknownC2(MissileProjectile*) override;               // C2
		virtual void UnknownC3(MissileProjectile*) override;               // C3

		// Member variables
		std::uint64_t unknown1E0; // 1E0, 1E8
		AlchemyItem*  poison;     // 1E8, 1F0
	};
	static_assert(offsetof(ArrowProjectile, poison) == SKYRIM_RELOCATE(0x1E8, 0x1F0));
	static_assert(sizeof(ArrowProjectile) == SKYRIM_RELOCATE(0x1F0, 0x1F8));
}
