#pragma once

#include "PCH.h"

#include "Shared/Skyrim/E/Effect.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/M/MagicTarget.h"
#include "Shared/Skyrim/T/TESBoundObject.h"



namespace ScrambledBugs::Patches
{
	class PoisonResistance
	{
	public:
		static void Patch(bool& poisonResistance);

	private:
		static float CheckResistance(Skyrim::MagicTarget* magicTarget, Skyrim::MagicItem* magicItem, Skyrim::Effect* effect, Skyrim::TESBoundObject* item);
	};
}
