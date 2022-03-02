#pragma once

#include "PCH.h"



namespace ScrambledBugs::Patches
{
	class CloakHitEffects
	{
	public:
		static void Patch(bool& cloakHitEffects);
	};
}
