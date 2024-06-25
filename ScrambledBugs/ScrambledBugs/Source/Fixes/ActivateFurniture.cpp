#include "PrecompiledHeader.h"

#include "Fixes/ActivateFurniture.h"

#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void ActivateFurniture::Fix(bool& activateFurniture)
	{
		ActivateFurniture::activate_ = reinterpret_cast<decltype(ActivateFurniture::activate_)>(
			Utility::Memory::ReadVirtualFunction(
				Skyrim::Addresses::TESFurniture::VirtualFunctionTable(),
				0x37));
		Utility::Memory::SafeWriteVirtualFunction(
			Skyrim::Addresses::TESFurniture::VirtualFunctionTable(),
			0x37,
			reinterpret_cast<std::uintptr_t>(std::addressof(ActivateFurniture::Activate)));
	}

	bool ActivateFurniture::Activate(
		Skyrim::TESFurniture*   furniture,
		Skyrim::TESObjectREFR*  target,
		Skyrim::TESObjectREFR*  activator,
		bool                    deferred,
		Skyrim::TESBoundObject* boundObject,
		std::int32_t            boundObjectCount)
	{
		if (activator)
		{
			auto* player = Skyrim::PlayerCharacter::GetSingleton();

			if (activator == player && player->IsOnMount())
			{
				return false;
			}
		}

		return ActivateFurniture::activate_(furniture, target, activator, deferred, boundObject, boundObjectCount);
	}

	decltype(ActivateFurniture::Activate)* ActivateFurniture::activate_{ nullptr };
}
