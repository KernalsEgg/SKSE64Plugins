#pragma once

#include "PCH.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace BugFixesSSE::Addresses
{
	namespace Fixes
	{
		namespace MagicEffectConditions
		{
			/// <summary>ActiveEffect::UpdateConditions (SkyrimSE.exe + 0x53E3E0)</summary>
			inline const std::uintptr_t UpdateConditions{ Relocation::AddressLibrary::GetSingleton().GetAddress(33287) + 0x0 };
		}

		namespace SpeechExperience
		{
			namespace ItemStacks
			{
				/// <summary>SkyrimSE.exe + 0x8528D0</summary>
				inline const std::uintptr_t Buy{ Relocation::AddressLibrary::GetSingleton().GetAddress(50007) + 0xD1 };

				/// <summary>SkyrimSE.exe + 0x8528D0</summary>
				inline const std::uintptr_t GetItemCount{ Relocation::AddressLibrary::GetSingleton().GetAddress(50007) + 0x53 };

				/// <summary>SkyrimSE.exe + 0x8528D0</summary>
				inline const std::uintptr_t Sell{ Relocation::AddressLibrary::GetSingleton().GetAddress(50007) + 0x1BE };
			}
		}

		namespace SpeedMultUpdates
		{
			/// <summary>SkyrimSE.exe + 0x2F39A40</summary>
			inline const std::uintptr_t ActorValueSinks{ Relocation::AddressLibrary::GetSingleton().GetAddress(517376) };

			/// <summary>SkyrimSE.exe + 0x622760</summary>
			inline const std::uintptr_t SpeedMultSink{ Relocation::AddressLibrary::GetSingleton().GetAddress(37542) };
		}
	}
}
