#include "PCH.h"

#include "Fixes/ActivateFurniture.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	bool ActivateFurniture::Fix()
	{
		ActivateFurniture::activate_ = reinterpret_cast<decltype(ActivateFurniture::activate_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::TESFurniture::VirtualFunctionTable, 0x37));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::TESFurniture::VirtualFunctionTable, 0x37, reinterpret_cast<std::uintptr_t>(std::addressof(ActivateFurniture::Activate)));

		return true;
	}

	bool ActivateFurniture::Activate(Skyrim::TESFurniture* furniture, Skyrim::TESObjectREFR* target, Skyrim::TESObjectREFR* activator, bool pathingTo, Skyrim::TESBoundObject* item, std::int32_t itemCount)
	{
		if (activator)
		{
			auto player = Skyrim::PlayerCharacter::GetSingleton();

			if (activator == player && player->IsOnMount())
			{
				return false;
			}
		}

		return ActivateFurniture::activate_(furniture, target, activator, pathingTo, item, itemCount);
	}

	decltype(&ActivateFurniture::Activate) ActivateFurniture::activate_{ nullptr };
}
