#pragma once

#include "PrecompiledHeader.h"

#include "Settings.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Trails
{
	class ImpactManager
	{
	public:
		static bool PlayImpactEffect(Skyrim::TESObjectREFR* source, const Settings::Footstep::Arguments& arguments);
	};
}
