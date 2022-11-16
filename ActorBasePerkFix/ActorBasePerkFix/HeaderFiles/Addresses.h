#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Relocation/PreprocessorDirectives.h"



namespace ActorBasePerkFix::Addresses
{
	namespace TaskQueueInterface
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x5C67A0, 1.6.318.0: SkyrimSE.exe + 0x5EA9E0</summary>
		inline const std::uintptr_t QueueApplyPerk{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(36007, 36982)) }; // TaskQueueInterface::QueueApplyPerk
	}
}
