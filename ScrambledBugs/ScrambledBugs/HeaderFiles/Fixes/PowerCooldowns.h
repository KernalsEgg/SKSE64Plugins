#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/B/BGSSaveFormBuffer.h"



namespace ScrambledBugs::Fixes
{
	class PowerCooldowns
	{
	public:
		static void Fix(bool& powerCooldowns);

	private:
		static void SavePowerCooldowns(Skyrim::Actor* actor, Skyrim::BGSSaveFormBuffer* saveFormBuffer);
	};
}
