#pragma once

#include "Shared/PCH.h"

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
		virtual void UnknownE(TESForm*) override;     // E
		virtual void UnknownF(TESForm*) override;     // F
		virtual void Unknown10(TESForm*) override;    // 10
		virtual void Unknown11(TESForm*) override;    // 11
		virtual void Unknown12(TESForm*) override;    // 12
		virtual void UnknownA2(Projectile*) override; // A2
		virtual void UnknownA9(Projectile*) override; // A9
		virtual void UnknownAB(Projectile*) override; // AB
		virtual void UnknownAC(Projectile*) override; // AC
		virtual void UnknownB8(Projectile*) override; // B8
		virtual void UnknownBD(Projectile*) override; // BD
		virtual void UnknownC0(Projectile*) override; // C0

		// Add
		virtual void UnknownC2(MissileProjectile*); // C2
		virtual void UnknownC3(MissileProjectile*); // C3

		// Member variables
		std::int64_t unknown1D8; // 1D8
	};
	static_assert(sizeof(MissileProjectile) == 0x1E0);
}
