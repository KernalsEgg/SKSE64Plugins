#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Relocation/PreprocessorDirectives.h"



namespace PowerAttackNotifications::Addresses
{
	namespace Events
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x63CFB0, 1.6.318.0: SkyrimSE.exe + 0x663510</summary>
		inline const std::uintptr_t StartStaminaMeterBlinking{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(38047, 39003)) + 0xF1 };
	}
}
