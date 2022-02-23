#pragma once

#include "PCH.h"

#include "Shared/Skyrim/B/BSTempEffectSimpleDecal.h"



namespace ScrambledBugs::Fixes
{
	class ImpactEffectCrash
	{
	public:
		static bool Fix();

	private:
		static bool DecalApplier(Skyrim::BSTempEffectSimpleDecal* tempEffectSimpleDecal);
		static bool MainUpdate(Skyrim::BSTempEffectSimpleDecal* tempEffectSimpleDecal);

		static decltype(&ImpactEffectCrash::DecalApplier) decalApplier_;
		static decltype(&ImpactEffectCrash::MainUpdate)   mainUpdate_;
	};
}
