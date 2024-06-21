#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class PowerCooldowns
	{
	public:
		static void Fix(bool& powerCooldowns);

	private:
		static void SaveCastPowers(Skyrim::Actor* actor, Skyrim::BGSSaveFormBuffer* saveFormBuffer);
	};
}
