#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace ScrambledBugs::Fixes
{
	class HarvestedFlags
	{
	public:
		static void Fix(bool& harvestedFlags);

	private:
		static void SetHarvestedFlag(Skyrim::TESObjectREFR* reference, bool harvested);

		static decltype(&HarvestedFlags::SetHarvestedFlag) setHarvestedFlag_;
	};
}
