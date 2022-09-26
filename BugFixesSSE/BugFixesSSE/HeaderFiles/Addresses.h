#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace BugFixesSSE::Addresses
{
	namespace Fixes
	{
		namespace MagicEffectConditions
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x53E3E0 (33287), 1.6.318.0: SkyrimSE.exe + 0x5584D0</summary>
			inline const std::uintptr_t UpdateConditions{ Relocation::AddressLibrary::GetSingleton().GetAddress(34062) }; // ActiveEffect::UpdateConditions
		}

		namespace MovementSpeed
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x60E540 + 0xA8 (36991), 1.6.318.0: SkyrimSE.exe + 0x636590</summary>
			inline const std::uintptr_t CompareMovementType{ Relocation::AddressLibrary::GetSingleton().GetAddress(38019) + 0xA6 }; // Actor::UpdateMovementSpeed
		}

		namespace SpeechExperience
		{
			namespace ItemStacks
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x8528D0 + 0xD1 (50007), 1.6.318.0: SkyrimSE.exe + 0x87F4A0</summary>
				inline const std::uintptr_t Buy{ Relocation::AddressLibrary::GetSingleton().GetAddress(50951) + 0xD1 }; // BarterMenu::ItemSelect

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x8528D0 + 0x53 (50007), 1.6.318.0: SkyrimSE.exe + 0x87F4A0</summary>
				inline const std::uintptr_t GetItemCount{ Relocation::AddressLibrary::GetSingleton().GetAddress(50951) + 0x53 }; // BarterMenu::ItemSelect

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x8528D0 + 0x1BE (50007), 1.6.318.0: SkyrimSE.exe + 0x87F4A0</summary>
				inline const std::uintptr_t Sell{ Relocation::AddressLibrary::GetSingleton().GetAddress(50951) + 0x1BE }; // BarterMenu::ItemSelect
			}
		}
	}
}
