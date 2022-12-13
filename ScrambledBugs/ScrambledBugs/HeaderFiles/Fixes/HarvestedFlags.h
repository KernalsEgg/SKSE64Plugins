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
		static void SetEmpty(Skyrim::TESObjectREFR* reference, bool empty);

		static decltype(&HarvestedFlags::SetEmpty) setEmpty_;
	};
}
