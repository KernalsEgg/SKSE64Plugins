#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class CloakHitEffects
	{
	public:
		static void Patch(bool& cloakHitEffects);
	};
}
