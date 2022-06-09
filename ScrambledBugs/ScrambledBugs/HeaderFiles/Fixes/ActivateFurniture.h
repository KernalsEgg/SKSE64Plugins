#pragma once

#include "PCH.h"

#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESFurniture.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace ScrambledBugs::Fixes
{
	class ActivateFurniture
	{
	public:
		static void Fix(bool& activateFurniture);

	private:
		static bool Activate(Skyrim::TESFurniture* furniture, Skyrim::TESObjectREFR* target, Skyrim::TESObjectREFR* activator, bool deferred, Skyrim::TESBoundObject* item, std::int32_t itemCount);

		static decltype(&ActivateFurniture::Activate) activate_;
	};
}
