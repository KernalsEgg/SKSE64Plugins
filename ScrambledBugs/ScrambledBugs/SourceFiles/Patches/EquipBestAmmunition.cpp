#include "PrecompiledHeader.h"

#include "Patches/EquipBestAmmunition.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/T/TESAmmo.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Patches
{
	void EquipBestAmmunition::Patch(bool& equipBestAmmunition)
	{
		if (!Patterns::Patches::EquipBestAmmunition::CompareDamageContainer() ||
			!Patterns::Patches::EquipBestAmmunition::CompareDamageInventoryChanges() ||
			!Patterns::Patches::EquipBestAmmunition::InitializeDamage() ||
			!Patterns::Patches::EquipBestAmmunition::IsBoltContainer() ||
			!Patterns::Patches::EquipBestAmmunition::IsBoltInventoryChanges())
		{
			equipBestAmmunition = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::EquipBestAmmunition::InitializeDamage + 0x4, static_cast<std::int32_t>(Addresses::Patches::EquipBestAmmunition::FloatMinimumValue - (Addresses::Patches::EquipBestAmmunition::InitializeDamage + 0x8))); // movss xmm6, -std::numeric_limits<float>::max()
		Utility::Memory::SafeWrite(Addresses::Patches::EquipBestAmmunition::CompareDamageContainer, 0x76ui8, std::optional<std::uint8_t>{});                                                                                                                    // jbe 6
		Utility::Memory::SafeWrite(Addresses::Patches::EquipBestAmmunition::CompareDamageInventoryChanges, 0x76ui8, std::optional<std::uint8_t>{});                                                                                                             // jbe 10

		/* Skip ammunition if it is not playable */
		Utility::Trampoline::GetSingleton().RelativeCall5Branch(
			Addresses::Patches::EquipBestAmmunition::IsBoltContainer + (8 + 3 + 2),
			0x24ui8, 0x01ui8,                                                                                                                                                   // and al, 1
			0x40ui8, 0x3Aui8, 0xC7ui8,                                                                                                                                          // cmp al, dil
			0x75ui8, 0x08ui8,                                                                                                                                                   // jne 8
			0x41ui8, 0xF6ui8, 0x80ui8, static_cast<std::uint32_t>(offsetof(Skyrim::TESAmmo, ammunitionFlags)), static_cast<std::uint8_t>(Skyrim::TESAmmo::Flags::kNonPlayable), // test byte ptr [r8+118], 2
			0xC3ui8                                                                                                                                                             // ret
		);

		Utility::Trampoline::GetSingleton().RelativeCall5Branch(
			Addresses::Patches::EquipBestAmmunition::IsBoltInventoryChanges + (7 + 3 + 2),
			0x24ui8, 0x01ui8,                                                                                                                                          // and al, 1
			0x40ui8, 0x3Aui8, 0xC7ui8,                                                                                                                                 // cmp al, dil
			0x75ui8, 0x07ui8,                                                                                                                                          // jne 7
			0xF6ui8, 0x85ui8, static_cast<std::uint32_t>(offsetof(Skyrim::TESAmmo, ammunitionFlags)), static_cast<std::uint8_t>(Skyrim::TESAmmo::Flags::kNonPlayable), // test byte ptr [rbp+118], 2
			0xC3ui8                                                                                                                                                    // ret
		);
	}
}
