#include "PCH.h"

#include "Fixes/KillCamera.h"

#include "Addresses.h"
#include "Patterns.h"
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

		Utility::Memory::SafeWrite(Addresses::Fixes::KillCamera::HasWeapon + sizeof(Utility::Assembly::RelativeCall), Utility::Assembly::NoOperation5);
		Utility::Trampoline::GetSingleton().RelativeCallBranch(
			Addresses::Fixes::KillCamera::HasWeapon,
			0x4Cui8, 0x8Bui8, 0x86ui8, 0x1B0ui32,   // mov r8, [rsi+1B0]
			0x4Dui8, 0x85ui8, 0xC0ui8,              // test r8, r8
			0x74ui8, 0x0Aui8,                       // jz A
			0xF7ui8, 0x86ui8, 0x1CCui32, 0x100ui32, // test [rsi+1CC], 100
			0xC3ui8                                 // ret
		);
	}
}
