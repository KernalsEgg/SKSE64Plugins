#pragma once

#include "PrecompiledHeader.h"

#include "Settings.h"



namespace Trails
{
	class ImpactManager
	{
	public:
		static bool PlayImpactEffect(Skyrim::TESObjectREFR* reference, const Settings::Footprint& footprint);
	};
}
