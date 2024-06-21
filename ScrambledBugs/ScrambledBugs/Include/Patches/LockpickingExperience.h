#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class LockpickingExperience
	{
	public:
		static void Patch(bool& lockpickingExperience);
	};
}
