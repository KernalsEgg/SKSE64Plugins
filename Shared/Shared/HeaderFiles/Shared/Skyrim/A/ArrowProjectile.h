#pragma once

#include "Shared/PCH.h"

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
		virtual void UnknownE(TESForm*) override;            // E
		virtual void UnknownF(TESForm*) override;            // F
		virtual void UnknownAA(Projectile*) override;        // AA
		virtual void UnknownAB(Projectile*) override;        // AB
		virtual void UnknownAC(Projectile*) override;        // AC
		virtual void UnknownAD(Projectile*) override;        // AD
		virtual void UnknownAF(Projectile*) override;        // AF
		virtual void UnknownB0(Projectile*) override;        // B0
		virtual void UnknownB1(Projectile*) override;        // B1
		virtual void UnknownB5(Projectile*) override;        // B5
		virtual void UnknownB9(Projectile*) override;        // B9
		virtual void UnknownBD(Projectile*) override;        // BD
		virtual void UnknownC0(Projectile*) override;        // C0
		virtual void UnknownC2(MissileProjectile*) override; // C2
		virtual void UnknownC3(MissileProjectile*) override; // C3

		// Member variables
		std::uint64_t unknown1E0; // 1E0
		AlchemyItem*  poison;     // 1E8
	};
	static_assert(offsetof(ArrowProjectile, poison) == 0x1E8);
	static_assert(sizeof(ArrowProjectile) == 0x1F0);
}
