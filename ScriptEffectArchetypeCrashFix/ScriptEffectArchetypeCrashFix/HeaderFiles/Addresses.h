#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Relocation/PreprocessorDirectives.h"



namespace ScriptEffectArchetypeCrashFix::Addresses
{
	namespace ActiveEffect
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x53DE80, 1.6.318.0: SkyrimSE.exe + 0x557DD0</summary>
		inline const std::uintptr_t CheckTargetActorsOnly{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(33276, 34051)) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F26050, 1.6.318.0: SkyrimSE.exe + 0x2FC0440</summary>
		inline const std::uintptr_t CheckTargetFunctions{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(516694, 402940)) };
	}
}
