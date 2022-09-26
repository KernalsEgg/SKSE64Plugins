#include "PrecompiledHeader.h"

#include "Fixes/PowerCooldowns.h"

#include "Addresses.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/P/PowerCooldown.h"
#include "Shared/Skyrim/S/SpellItem.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void PowerCooldowns::Fix(bool& powerCooldowns)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::PowerCooldowns::SavePowerCooldowns, reinterpret_cast<std::uintptr_t>(std::addressof(PowerCooldowns::SavePowerCooldowns)));
	}

	void PowerCooldowns::SavePowerCooldowns(Skyrim::Actor* actor, Skyrim::BGSSaveFormBuffer* saveFormBuffer)
	{
		// actor != nullptr
		// saveFormBuffer != nullptr

		std::uint32_t powerCooldownCount{ 0 };
		auto*         powerCooldowns = actor->powerCooldowns;

		if (powerCooldowns)
		{
			for (const auto& powerCooldown : *powerCooldowns)
			{
				++powerCooldownCount;
			}

			saveFormBuffer->Write(std::addressof(powerCooldownCount), sizeof(std::uint32_t));

			for (const auto& powerCooldown : *powerCooldowns)
			{
				saveFormBuffer->WriteFormID(powerCooldown.power);
				saveFormBuffer->Write(std::addressof(powerCooldown.cooldown), sizeof(float));
			}
		}
		else
		{
			saveFormBuffer->Write(std::addressof(powerCooldownCount), sizeof(std::uint32_t));
		}
	}
}
