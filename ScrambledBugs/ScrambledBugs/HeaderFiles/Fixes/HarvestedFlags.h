#pragma once

#include "PCH.h"

#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace ScrambledBugs::Fixes
{
	class HarvestedFlags
	{
	public:
		static bool Fix();

	private:
		static void SetHarvestedFlag(Skyrim::TESObjectREFR* reference, bool harvested);

		static decltype(&HarvestedFlags::SetHarvestedFlag) setHarvestedFlag_;
	};
}
