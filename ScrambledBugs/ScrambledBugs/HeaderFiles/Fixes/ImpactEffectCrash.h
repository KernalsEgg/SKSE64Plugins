#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTempEffectSimpleDecal.h"



namespace ScrambledBugs::Fixes
{
	class ImpactEffectCrash
	{
	public:
		static void Fix(bool& impactEffectCrash);

	private:
		static bool DecalApplier(Skyrim::BSTempEffectSimpleDecal* tempEffectSimpleDecal);
		static bool MainUpdate(Skyrim::BSTempEffectSimpleDecal* tempEffectSimpleDecal);

		static decltype(&ImpactEffectCrash::DecalApplier) decalApplier_;
		static decltype(&ImpactEffectCrash::MainUpdate)   mainUpdate_;
	};
}
