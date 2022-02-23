#include "PCH.h"

#include "Patches/EquipBestAmmo.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Patches
{
	bool EquipBestAmmo::Patch()
	{
		if (!Patterns::Patches::EquipBestAmmo::CompareDamageContainer() ||
			!Patterns::Patches::EquipBestAmmo::CompareDamageInventoryChanges() ||
			!Patterns::Patches::EquipBestAmmo::InitializeDamage() ||
			!Patterns::Patches::EquipBestAmmo::IsBoltContainer() ||
			!Patterns::Patches::EquipBestAmmo::IsBoltInventoryChanges())
		{
			return false;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::EquipBestAmmo::InitializeDamage + 0x4, static_cast<std::int32_t>(Addresses::Patches::EquipBestAmmo::FloatMinimumValue - (Addresses::Patches::EquipBestAmmo::InitializeDamage + 0x8))); // movss xmm6, -std::numeric_limits<float>::max()
		Utility::Memory::SafeWrite(Addresses::Patches::EquipBestAmmo::CompareDamageContainer, 0x76ui8, std::optional<std::uint8_t>{});                                                                                                        // jbe 6
		Utility::Memory::SafeWrite(Addresses::Patches::EquipBestAmmo::CompareDamageInventoryChanges, 0x76ui8, std::optional<std::uint8_t>{});                                                                                                 // jbe 10

		// Skip ammo if it is not playable
		Utility::Trampoline::GetSingleton().RelativeCallBranch(
			Addresses::Patches::EquipBestAmmo::IsBoltContainer + (8 + 3 + 2),
			0x24ui8, 0x01ui8,                              // and al, 1
			0x40ui8, 0x3Aui8, 0xC7ui8,                     // cmp al, dil
			0x75ui8, 0x08ui8,                              // jne 8
			0x41ui8, 0xF6ui8, 0x80ui8, 0x118ui32, 0x02ui8, // test byte ptr [r8+118], 2
			0xC3ui8                                        // ret
		);

		Utility::Trampoline::GetSingleton().RelativeCallBranch(
			Addresses::Patches::EquipBestAmmo::IsBoltInventoryChanges + (7 + 3 + 2),
			0x24ui8, 0x01ui8,                     // and al, 1
			0x40ui8, 0x3Aui8, 0xC7ui8,            // cmp al, dil
			0x75ui8, 0x07ui8,                     // jne 7
			0xF6ui8, 0x85ui8, 0x118ui32, 0x02ui8, // test byte ptr [rbp+118], 2
			0xC3ui8                               // ret
		);

		return true;
	}
}
