#include "PrecompiledHeader.h"

#include "Fixes/KillCamera.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/P/Projectile.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Fixes
{
	void KillCamera::Fix(bool& killCamera)
	{
		if (!Patterns::Fixes::KillCamera::HasWeapon())
		{
			killCamera = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Fixes::KillCamera::HasWeapon + sizeof(Utility::Assembly::RelativeCall5), Utility::Assembly::NO_OPERATION_5);
		Utility::Trampoline::GetSingleton().RelativeCall5Branch(
			Addresses::Fixes::KillCamera::HasWeapon,
			0x4Cui8, 0x8Bui8, 0x86ui8, static_cast<std::int32_t>(offsetof(Skyrim::Projectile, weaponSource)),                                                             // mov r8, [rsi+1B8]
			0x4Dui8, 0x85ui8, 0xC0ui8,                                                                                                                                    // test r8, r8
			0x74ui8, 0x0Aui8,                                                                                                                                             // jz A
			0xF7ui8, 0x86ui8, static_cast<std::int32_t>(offsetof(Skyrim::Projectile, projectileFlags)), static_cast<std::uint32_t>(Skyrim::Projectile::Flags::k3DLoaded), // test [rsi+1D4], 100
			0xC3ui8                                                                                                                                                       // ret
		);
	}
}
