#pragma once

#include "PrecompiledHeader.h"

#include "Settings.h"



namespace Trails
{
	class ImpactManager
	{
	public:
		static bool PlayImpactEffect(Skyrim::TESObjectREFR* source, const Settings::Footstep::Arguments& arguments);
	};
}
