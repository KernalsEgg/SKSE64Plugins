#include "PrecompiledHeader.h"

#include "Fixes/PowerCooldowns.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void PowerCooldowns::Fix(bool& powerCooldowns)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::PowerCooldowns::SaveCastPowers, reinterpret_cast<std::uintptr_t>(std::addressof(PowerCooldowns::SaveCastPowers)));
	}

	void PowerCooldowns::SaveCastPowers(Skyrim::Actor* actor, Skyrim::BGSSaveFormBuffer* saveFormBuffer)
	{
		// actor != nullptr
		// saveFormBuffer != nullptr

		std::uint32_t castPowerCount{ 0 };
		auto*         castPowers = actor->castPowers;

		if (castPowers)
		{
			for (const auto& castPower : *castPowers)
			{
				++castPowerCount;
			}

			saveFormBuffer->Write(std::addressof(castPowerCount), sizeof(std::uint32_t));

			for (const auto& castPower : *castPowers)
			{
				saveFormBuffer->WriteFormID(castPower.power);
				saveFormBuffer->Write(std::addressof(castPower.cooldown), sizeof(float));
			}
		}
		else
		{
			saveFormBuffer->Write(std::addressof(castPowerCount), sizeof(std::uint32_t));
		}
	}
}
