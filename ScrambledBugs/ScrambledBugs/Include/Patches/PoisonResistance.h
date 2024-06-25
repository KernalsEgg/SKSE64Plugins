#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class PoisonResistance
	{
	public:
		static void Patch(bool& poisonResistance);

	private:
		static float CheckResistance(Skyrim::MagicTarget* magicTarget, Skyrim::MagicItem* magicItem, Skyrim::EffectItem* effectItem, Skyrim::TESBoundObject* boundObject);
	};
}
